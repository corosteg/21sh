/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 21:58:41 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/05 19:22:49 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh.h"

int					check_builtin(char **command, t_shell *info, int out)
{
	if (!(ft_strcmp(command[0], "cd")))
	{
		ft_cd_pars(command, info->env, 1, info);
		return (1);
	}
//	if (!(ft_strcmp(command[0], "echo")))
//	{
//		ft_echo(command, info->env, out);
//		return (1);
//	}
	return (0);
}
