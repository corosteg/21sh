/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:28:41 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 16:29:54 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		infanticide(t_shell *info)
{
	int i;

	i = 0;
	while (i < info->father)
	{
		i++;
		wait(0);
	}
}

void			no_command(int father, char **com)
{
	ft_print("command not found: %s\n", com[0]);
	exit(father);
}

static void		born_to_kill(t_shell *info)
{
	wait(0);
	if (info->kill > 0)
		kill(info->kill, 13);
}

void			exec_free(char **env, char *bin_path)
{
	free_c_tab(env);
	free(bin_path);
}

void			exec_simpl(char **com, t_shell *info, t_parselex *first,
					char **env)
{
	char		*bin_path;
	pid_t		father;

	if (check_builtin(com, info, info->fd_out, first))
		return (free_c_tab(env));
	bin_path = look_for_bin(com[0], parse_path(info->env), NULL, NULL);
	father = fork();
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (father > 0)
		born_to_kill(info);
	infanticide(info);
	if (father == 0)
	{
		if (info->ag2 == 0)
			close(1);
		else if (info->ag2 == 1)
			dup2(info->fd_out, 1);
		else if (info->ag2 == 2)
			dup2(info->save_stderr, 1);
		close(info->fd_in);
		if (execve(bin_path, com, env))
			no_command(father, com);
	}
	exec_free(env, bin_path);
}
