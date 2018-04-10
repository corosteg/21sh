/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:08:35 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/10 13:19:39 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				exec_redir(char **com, t_shell *info, int fd,
					t_parselex *first)
{
	char		*bin_path;
	char		**env;
	pid_t		father;

	if (check_builtin(com, info, fd, first))
		return;
	env = alloc_tab(info->env);
	bin_path = look_for_bin(com[0], parse_path(info->env), NULL, NULL);
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
	free_c_tab(env);
	free(bin_path);
}

t_parselex				*redir_simpl(t_shell *info, t_parselex *list,
						t_parselex *first)
{
	int		fd;

	if (list->next->next == NULL)
		return (NULL);
	fd = open(list->next->next->cutting[0], O_CREAT | O_TRUNC
		| O_WRONLY, 0644);
	exec_redir(list->cutting, info, fd, first);
	while (list && !(end_token_tool(list->cutting[0])))
		list = list->next;
	reset_fd_tool(info);
	return (list);
}

t_parselex				*redir_doble(t_shell *info, t_parselex *list,
						t_parselex *first)
{
	int		fd;

	if (list->next->next == NULL)
		return (NULL);
	fd = open(list->next->next->cutting[0], O_APPEND
		| O_RDWR, 0644);
	exec_redir(list->cutting, info, fd, first);
	while (list && !(end_token_tool(list->cutting[0])))
		list = list->next;
	reset_fd_tool(info);
	return (list);
}

t_parselex				*delete_next_token(t_parselex *list)
{
	t_parselex		*tmp;

	tmp = list->next;
	list->next = list->next->next;
	free_c_tab(tmp->cutting);
	free(tmp);
	tmp = list->next;
	list->next = list->next->next;
	free_c_tab(tmp->cutting);
	free(tmp);
	return (list);
}

t_parselex				*redir_left(t_shell *info, t_parselex *list,
						t_parselex *first)
{
	char	*ta[3];


	if (list->next->next == NULL)
		return (NULL);
	ta[0] = ft_strdup("/bin/cat");
	ta[1] = ft_strdup(list->next->next->cutting[0]);
	ta[2] = NULL;
	exec_in_pipe(ta, info, first, 1);
//	exec_redir(list->cutting, info, info->fd_out);
//	while (list && !(end_token_tool(list->cutting[0], info)))
//		list = list->next;
//	reset_fd_tool(info);
	free(ta[0]);
	free(ta[1]);
	list = delete_next_token(list);
	return (list);
}

t_parselex				*redir_heredoc(t_shell *info, t_parselex *list,
						t_parselex *first)
{
	char	*ta[3];


	if (list->next->next == NULL)
		return (NULL);
	ta[0] = ft_strdup("/bin/cat");
	ta[1] = ft_strdup(list->next->next->cutting[0]);
	ta[2] = NULL;
	exec_in_pipe(ta, info, first, 1);
	list = delete_next_token(list);
	free(ta[0]);
	free(ta[1]);
//	reset_fd_tool(info);
	return (list);
}
