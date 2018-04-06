/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:28:41 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/06 13:17:50 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh.h"

void			exec_simpl(char **com, t_shell *info)
{
	char		*bin_path;
	char		**env;
	pid_t		father;

	if (check_builtin(com, info, info->fd_out))
		return;
	env = alloc_tab(info->env);
	bin_path = look_for_bin(com[0], parse_path(info->env), NULL, NULL);
	father = fork();
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (father > 0)
	{
		wait(0);
		if (info->kill > 0)
			kill(info->kill, 13);
	}
	int i = 0;
	while (i < info->father)
	{
		i++;
		wait(0);
	}
	if (father == 0)
	{
		dup2(info->fd_out, 1);
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

void			exec_in_pipe(char **com, t_shell *info, char **env, int i)
{
	pid_t		father;
	char		*bin_path;
	int			tmp_fd[2];

	bin_path = look_for_bin(com[0], parse_path(info->env), NULL, NULL);
	pipe(tmp_fd);
/*	if (check_builtin(com, info, tmp_fd[1]))
	{
		close(tmp_fd[1]);
		info->fd_in = tmp_fd[0];
		info->fd_out = dup(info->save_stdout);
		return;
	}*/
	father = fork();
	if (i == 1)
		wait(0);
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (!(ft_strcmp(com[0], "base64")) && father > 0)
		info->kill = father;
	if (father == 0)
	{
		dup2(tmp_fd[1], 1);
		close(info->fd_in);
		wait(0);
		if (execve(bin_path, com, env))
		{
			ft_print("command not found: %s\n", com[0]);
			exit(-1);
		}
		wait(0);
	}
	info->father++;
	free_c_tab(env);
	free(bin_path);
	info->fd_in = tmp_fd[0];
	close(tmp_fd[1]);
	info->fd_out = dup(info->save_stdout);
}
