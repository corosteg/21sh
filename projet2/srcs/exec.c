/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:28:41 by corosteg          #+#    #+#             */
/*   Updated: 2018/02/05 19:09:32 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh.h"

void			exec_simpl(char **com, t_shell *info)
{
	char		*bin_path;
	char		**env;
	pid_t		father;

	env = alloc_tab(info->env);
	bin_path = look_for_bin(com[0], parse_path(info->env), NULL, NULL);
	father = fork();
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (father > 0)
		wait(NULL);
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

void			exec_in_pipe(char **com, t_shell *info, char **env)
{
	pid_t		father;
	char		*bin_path;
	int			tmp_fd[2];

	bin_path = look_for_bin(com[0], parse_path(info->env), NULL, NULL);
	pipe(tmp_fd);
	father = fork();
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
		dup2(tmp_fd[1], 1);
		close(info->fd_in);
		if (execve(bin_path, com, env))
		{
			ft_print("command not found: %s\n", com[0]);
			exit(father);
		}
	}
	free_c_tab(env);
	free(bin_path);
	info->fd_in = tmp_fd[0];
	close(tmp_fd[1]);
	info->fd_out = dup(info->save_stdout);
}
