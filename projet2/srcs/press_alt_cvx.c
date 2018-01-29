/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_alt_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:46:20 by corosteg          #+#    #+#             */
/*   Updated: 2018/01/24 17:45:34 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh.h"

void			p_a_c(t_shell *info)
{
	info->cp_string = ft_strndup(&info->command[info->start_cp],
			info->end_cp - info->start_cp);
}

static void			modify_string(t_shell *info, char *str2, int insert_len)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strndup(info->command, insert_len);
	tmp = ft_strfreejoin(tmp, str2, 1);
	tmp = ft_strfreejoin(tmp, &info->command[insert_len], 1);
	tmp2 = info->command;
	info->command = ft_strdup(tmp);
	free(tmp);
	free(str2);
	free(tmp2);
}

void			p_a_v(t_shell *info)
{
	int					buf;
	char				*str2;
	int					insert_len;
	int					cursor;
	struct winsize		screen;

	ioctl(0, TIOCGWINSZ, &screen);
	insert_len = info->len;
	str2 = ft_strdup(info->cp_string);
	cursor = info->len + 1 + ft_strlen(info->cp_string);
	modify_string(info, str2, insert_len);
	while (info->len > 0)
		p_left(info);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	press_string(info);
	while (info->len > cursor)
		p_left(info);
	if (info->is_his)
		info->no_move_his = 1;
}

int				p_a_x(t_shell *info)
{
	int		i;

	if (info->end_cp == -1 || info->start_cp == -1)
		return(0);
	i = info->end_cp - info->start_cp;
	while (i > 0)
	{
		p_backspace(info, 0);
		i--;
	}
	return(0);
}
