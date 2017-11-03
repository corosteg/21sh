/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:28:34 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/03 20:48:17 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				p_ascii(t_shell *info, char *str, int buf)
{
	char				*tmp;
	struct winsize		screen;

	ioctl(0, TIOCGWINSZ, &screen);
	ft_putchar(buf);
	info->len++;
	info->x++;
	if (info->x > screen.ws_col)
		info->x = 0;
	if (info->command[0] == '\0')
	{
		tmp = info->command;
		info->command = ft_strdup(str);
		free(tmp);
	if (info->is_his)
		info->no_move_his = 1;
	}
	else
		info->command = ft_strfreejoin(info->command, str, 1);
	if (info->is_his)
		info->no_move_his = 1;
}
