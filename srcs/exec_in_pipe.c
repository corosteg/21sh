/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_in_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:25:40 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/13 17:18:47 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			exec_in_pipe2(char **env, t_shell *info, int fd, int fd2)
{
	close(fd);
	info->fd_in = fd2;
	info->fd_out = dup(info->save_stdout);
	free_c_tab(env);
}

void			exec_in_pipe3(char **env, t_shell *info, char *bin_path,
					int *tmp_fd)
{
	info->father++;
	free_c_tab(env);
	free(bin_path);
	info->fd_in = tmp_fd[0];
	close(tmp_fd[1]);
	info->fd_out = dup(info->save_stdout);
}

void			exec_in_pipe4(t_shell *info, int *tmp_fd)
{
	if (info->ag == 0)
		dup2(tmp_fd[1], 0);
	else if (info->ag == 1)
		dup2(tmp_fd[1], 1);
	else if (info->ag == 2)
		dup2(tmp_fd[1], 2);
}

void			exec_in_pipe(char **com, t_shell *info,
					t_parselex *first, int i)
{
	pid_t		father;
	char		*bin_path;
	int			tmp_fd[2];
	char		**env;

	env = alloc_tab(info->env);
	pipe(tmp_fd);
	if (check_builtin(com, info, tmp_fd[1], first))
		return (exec_in_pipe2(env, info, tmp_fd[1], tmp_fd[0]));
	bin_path = look_for_bin(com[0], parse_path(info->env), NULL, NULL);
	father = fork();
	if (i == 1)
		wait(0);
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (!(ft_strcmp(com[0], "base64")) && father > 0)
		info->kill = father;
	if (father == 0)
	{
		exec_in_pipe4(info, tmp_fd);
		close(info->fd_in);
		if (execve(bin_path, com, env))
			no_command(father, com);
	}
	exec_in_pipe3(env, info, bin_path, tmp_fd);
}
