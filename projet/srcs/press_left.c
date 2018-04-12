/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:28:25 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 18:50:04 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				p_left3(t_shell *info)
{
	info->start_cp = -1;
	info->end_cp = -1;
	tool_refresh(info);
}

int					p_left(t_shell *info)
{
	struct winsize		screen;

	info->x--;
	ioctl(0, TIOCGWINSZ, &screen);
	if (info->x < 0)
	{
		info->y--;
		info->x = 0;
		tputs(tgetstr("up", NULL), 1, ft_putchar);
		while (info->x <= screen.ws_col)
		{
			tputs(tgetstr("nd", NULL), 1, ft_putchar);
			info->x++;
		}
		info->x = screen.ws_col - 1;
	}
	else
		tputs(tgetstr("le", NULL), 1, ft_putchar);
	info->len--;
	if (info->start_cp != -1 || info->end_cp != -1)
		p_left3(info);
	return (0);
}

int					p_left2(t_shell *info)
{
	struct winsize		screen;

	info->x--;
	ioctl(0, TIOCGWINSZ, &screen);
	if (info->x < 0)
	{
		info->y--;
		info->x = 0;
		tputs(tgetstr("up", NULL), 1, ft_putchar);
		while (info->x <= screen.ws_col)
		{
			tputs(tgetstr("nd", NULL), 1, ft_putchar);
			info->x++;
		}
		info->x = screen.ws_col - 1;
	}
	else
		tputs(tgetstr("le", NULL), 1, ft_putchar);
	info->len--;
	return (0);
}
