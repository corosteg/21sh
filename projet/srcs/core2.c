/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:09:30 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 15:10:27 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int						check_operador(char c)
{
	if (c == ';')
		return (1);
	if (c == '>')
		return (1);
	if (c == '<')
		return (1);
	if (c == '|')
		return (1);
	return (0);
}

int						check_final(t_shell *info, int run)
{
	int		tmp;

	if (info->command[run] == '\0')
	{
		tmp = info->fd_out;
		info->fd_out = info->save_stdout;
		close(tmp);
		return (1);
	}
	if (info->command[run] == ';')
	{
		tmp = info->fd_out;
		info->fd_out = dup(info->save_stdout);
		close(tmp);
		return (1);
	}
	return (0);
}
