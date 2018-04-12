/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:08:35 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 19:11:30 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			ft_echo_redire(char **command, int out, t_shell *info)
{
	int i;
	int father;

	i = 1;
	father = fork();
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		dup2(out, 1);
		close(info->fd_in);
		while (command[i])
		{
			ft_print("%s", command[i]);
			i++;
		}
		ft_print("\n");
		exit(0);
	}
}

void				exec_redir(char **com, t_shell *info, int fd,
					t_parselex *first)
{
	char		*bin_path;
	char		**env;
	pid_t		father;

	if (!ft_strcmp(com[0], "echo"))
		return (ft_echo_redire(com, fd, info));
	else if (check_builtin(com, info, fd, first))
		return ;
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
			no_command(father, com);
	}
	free_c_tab(env);
	free(bin_path);
}

t_parselex			*redir_simpl(t_shell *info, t_parselex *list,
						t_parselex *first)
{
	int		fd;

	if (list->next->next == NULL)
		return (NULL);
	fd = open(list->next->next->cutting[0], O_CREAT | O_TRUNC
		| O_WRONLY | FD_CLOEXEC, 0644);
	exec_redir(list->cutting, info, fd, first);
	while (list && !(end_token_tool(list->cutting[0])))
		list = list->next;
	close(fd);
	reset_fd_tool(info);
	return (list);
}

t_parselex			*redir_doble(t_shell *info, t_parselex *list,
						t_parselex *first)
{
	int		fd;

	if (list->next->next == NULL)
		return (NULL);
	fd = open(list->next->next->cutting[0], O_CREAT | O_APPEND
		| O_RDWR, 0644);
	exec_redir(list->cutting, info, fd, first);
	while (list && !(end_token_tool(list->cutting[0])))
		list = list->next;
	close(fd);
	reset_fd_tool(info);
	return (list);
}
