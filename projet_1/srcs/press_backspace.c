/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_backspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:53:40 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/09 17:34:17 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void			modify_string(t_shell *info)
{
	char	*str;
	char	*tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	tmp = info->command;
	str = (char*)malloc(sizeof(char) * ft_strlen(info->command));
	str[ft_strlen(info->command) - 1] = '\0';
	while (info->command[i])
	{
		if (i == info->len)
			i++;
		if (info->command[i] == '\0')
			break ;
		str[a] = info->command[i];
		i++;
		a++;
	}
	info->command = str;
	free(tmp);
}

void				p_backspace(t_shell *info, int a)
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
		p_space(info, " ");
		info->len--;
		info->command[ft_strlen(info->command) - 1] = '\0';
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
	if (a != 1)
		modify_string(info);
	tputs(tgetstr("dc", NULL), 1, ft_putchar);
	if (info->is_his && a != 1)
		info->no_move_his = 1;
}
