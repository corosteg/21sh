/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:35:47 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/09 16:46:29 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void			p_ascii_emulation(char *str, t_shell *info)
{
	int i;
	struct winsize		screen;


	i = 0;
	info->x = 5;
	info->y = 0;
	info->len = 0;
	ioctl(0, TIOCGWINSZ, &screen);
	while (str[i])
	{
		ft_putchar(str[i]);
		info->len++;
		info->x++;
		if (info->x > screen.ws_col - 1)
		{
			info->x = 0;
			tputs(tgetstr("do", NULL), 1, ft_putchar);
			tputs(tgetstr("cr", NULL), 1, ft_putchar);
			info->y++;
		}
		i++;
	}
}

void			press_string(t_shell *info)
{
	int		i;
	struct winsize		screen;

	i = 0;
	ioctl(0, TIOCGWINSZ, &screen);
	while (info->command[i])
	{
		ft_putchar(info->command[i]);
		info->len++;
		info->x++;
		if (info->x > screen.ws_col - 1)
		{
			info->x = 0;
			tputs(tgetstr("do", NULL), 1, ft_putchar);
			tputs(tgetstr("cr", NULL), 1, ft_putchar);
			info->y++;
		}
		i++;
	}
}
