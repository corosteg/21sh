/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:23:59 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 15:10:14 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int						parsing_list(t_parselex *list)
{
	if (!(ft_strcmp(list->cutting[0], ";")))
		ft_print("21sh:  syntax error near unexpected token `;'");
	else if (!(ft_strcmp(list->cutting[0], "|")))
		ft_print("21sh:  syntax error near unexpected token `|'");
	else if (!(ft_strcmp(list->cutting[0], "||")))
		ft_print("21sh:  syntax error near unexpected token `||'");
	else if (!(ft_strcmp(list->cutting[0], "&")))
		ft_print("21sh:  syntax error near unexpected token `&'");
	else if (!(ft_strcmp(list->cutting[0], "&&")))
		ft_print("21sh:  syntax error near unexpected token `&&'");
	else
		return (0);
	return (1);
}

static	t_parselex		*check_redire(t_parselex *list, t_shell *info,
						t_parselex *first)
{
	if (list && list->next && !(ft_strcmp(list->next->cutting[0], "<<")))
		list = redir_heredoc(info, list, first);
	if (list && list->next && !(ft_strcmp(list->next->cutting[0], "<")))
		list = redir_left(info, list, first);
	if (list && list->next && !(ft_strcmp(list->next->cutting[0], ">")))
		list = redir_simpl(info, list, first);
	if (list && list->next && !(ft_strcmp(list->next->cutting[0], ">>")))
		list = redir_doble(info, list, first);
	return (list);
}

static void				create_files(t_parselex *list)
{
	while (list && ft_strcmp(list->cutting[0], ";") != 0)
	{
		if (!(ft_strcmp(list->cutting[0], ">")))
			open(list->next->cutting[0], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		list = list->next;
	}
}

static t_parselex		*check_exec(t_parselex *list, t_shell *info,
						t_parselex *first)
{
	check_agregation(list, info);
	if (list->next && !(ft_strcmp(list->next->cutting[0], "|")))
	{
		create_files(list);
		exec_in_pipe(list->cutting, info, first, 0);
	}
	if (list->next == NULL || end_token_tool(list->next->cutting[0]))
	{
		exec_simpl(list->cutting, info, first, alloc_tab(info->env));
		reset_fd_tool(info);
	}
	list = list->next;
	return (list);
}

int						core(t_shell *info)
{
	t_parselex		*list;
	t_parselex		*first;

	info->fd_in = dup(0);
	info->fd_out = dup(1);
	info->fd_err = dup(2);
	if ((list = parse_cmd(info, 1, NULL, NULL)) == NULL)
		return (0);
	if (parsing_list(list))
		return (0);
	create_files(list);
	first = list;
	while (list)
	{
		if (!(list = check_redire(list, info, first)))
			break ;
		list = check_exec(list, info, first);
	}
	free_lex(first);
	dup2(info->save_stdin, 0);
	return (1);
}
