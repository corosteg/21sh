/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 21:58:41 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/11 15:58:46 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh.h"

int					check_builtin(char **command, t_shell *info,
					int out, t_parselex *first)
{
	if (!(ft_strcmp(command[0], "cd")))
	{
		ft_cd_pars(command, info->env, 1, info);
		return (1);
	}
	if (!(ft_strcmp(command[0], "echo")))
	{
		if (info->ag == 1)
			ft_echo(command, info->env, out);
		else if (info->ag == 2)
			ft_echo(command, info->env, 2);
		else if (info->ag == 0)
			;
		return (1);
	}
	if (!(ft_strcmp(command[0], "unsetenv")))
	{
		ft_unsetenv(command, info->env, info);
		return (1);
	}
	if (!(ft_strcmp(command[0], "setenv")))
	{
		ft_setenv(command, info->env, info);
		return (1);
	}
	if (!(ft_strcmp(command[0], "exit")))
	{
		ft_exit(first, info);
		return (1);
	}
	if (!(ft_strcmp(command[0], "env")))
	{
		ft_env(info->env, out);
		return (1);
	}
	return (0);
}
