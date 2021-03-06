/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_backspace2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:37:04 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 18:44:50 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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

void				p_backspace3(void)
{
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
}

void				p_backspace2(t_shell *info, struct winsize screen)
{
	info->y--;
	info->x = 0;
	tputs(tgetstr("up", NULL), 1, ft_putchar);
	while (info->x < screen.ws_col)
	{
		tputs(tgetstr("nd", NULL), 1, ft_putchar);
		info->x++;
	}
	p_space(info, " ");
	info->len--;
	info->command[ft_strlen(info->command) - 1] = '\0';
	tputs(tgetstr("up", NULL), 1, ft_putchar);
	while (info->x < screen.ws_col)
	{
		tputs(tgetstr("nd", NULL), 1, ft_putchar);
		info->x++;
	}
	info->x = screen.ws_col - 1;
}

void				p_backspace(t_shell *info, int a)
{
	struct winsize		screen;
	int					cursor;

	info->x--;
	ioctl(0, TIOCGWINSZ, &screen);
	if (info->x < 0)
		p_backspace2(info, screen);
	else
		tputs(tgetstr("le", NULL), 1, ft_putchar);
	info->len--;
	if (a != 1)
		modify_string(info);
	cursor = info->len;
	while (info->len > 0)
		p_left(info);
	p_backspace3();
	ft_print(""GRAS""VERT"21sh"RED">"STOP"");
	press_string(info);
	while (info->len > cursor)
		p_left(info);
	if (info->is_his && a != 1)
		info->no_move_his = 1;
}
