/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_shift_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:28:39 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/30 19:52:46 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				p_s_down(t_shell *info)
{
	struct winsize		argp;
	int					x_goal;
	int					y_goal;

	ioctl(0, TIOCGWINSZ, argp);
	x_goal = argp.ws_col;
	y_goal = argp.ws_row + 1;
	while (info->command[info->len] && (x_goal < argp.ws_row ||
			y_goal < argp.ws_col))
	{
		info->len++;
		tputs(tgetstr("nd", NULL), 1, ft_putchar);
		ioctl(0, TIOCGWINSZ, argp);
	}
}
