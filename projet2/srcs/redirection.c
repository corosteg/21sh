/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:08:35 by corosteg          #+#    #+#             */
/*   Updated: 2018/02/02 23:32:24 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void			exec_redir(char **com, t_shell *info, int fd)
{
	char		*bin_path;
	char		**env;
	pid_t		father;

	env = alloc_tab(info->env);
	bin_path = look_for_bin(com[0], parse_path(info->env));
	father = fork();
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
		dup2(fd, 1);
		close(info->fd_in);
		if (execve(bin_path, com, env))
		{
			ft_print("command not found: %s\n", com[0]);
			exit(father);
		}
	}
}

t_parselex				*redir_simpl(t_shell *info, t_parselex *list)
{
	int		fd;

	if (list->next->next == NULL)
		return (NULL);
	fd = open(list->next->next->cutting[0], O_CREAT | O_TRUNC
		| O_WRONLY, 0644);
	exec_redir(list->cutting, info, fd);
	while (list && !(end_token_tool(list->cutting[0], info)))
		list = list->next;
	return (list);
}

t_parselex				*redir_doble(t_shell *info, t_parselex *list)
{
	int		fd;

	if (list->next->next == NULL)
		return (NULL);
	fd = open(list->next->next->cutting[0], O_APPEND
		| O_RDWR, 0644);
	exec_redir(list->cutting, info, fd);
	while (list && !(end_token_tool(list->cutting[0], info)))
		list = list->next;
	return (list);
}
