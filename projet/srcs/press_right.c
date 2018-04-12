/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:28:09 by corosteg          #+#    #+#             */
/*   Updated: 2018/01/24 16:32:07 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				p_right(t_shell *info)
{
	struct winsize		screen;

	info->x++;
	ioctl(0, TIOCGWINSZ, &screen);
	if (info->x > screen.ws_col - 1)
	{
		info->x = 0;
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		tputs(tgetstr("cr", NULL), 1, ft_putchar);
		info->len++;
		info->y++;
	}
	else
	{
		tputs(tgetstr("nd", NULL), 1, ft_putchar);
		info->len++;
	}
	if (info->start_cp != -1 || info->end_cp != -1)
	{
		info->start_cp = -1;
		info->end_cp = -1;
		tool_refresh(info);
	}
}

void				p_right2(t_shell *info)
{
	struct winsize		screen;

	info->x++;
	ioctl(0, TIOCGWINSZ, &screen);
	if (info->x > screen.ws_col - 1)
	{
		info->x = 0;
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		tputs(tgetstr("cr", NULL), 1, ft_putchar);
		info->len++;
		info->y++;
	}
	else
	{
		tputs(tgetstr("nd", NULL), 1, ft_putchar);
		info->len++;
	}
}
