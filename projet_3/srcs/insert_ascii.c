/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:58:47 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/03 19:54:36 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

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

int					insert_ascii(t_shell *info, char *str)
{
	int		buf;
	char	*str2;
	int		insert_len;
	struct winsize		screen;

	ioctl(0, TIOCGWINSZ, &screen);
	insert_len = info->len;
	str2 = ft_strdup(str);
	ft_putchar(str[0]);
	info->len++;
	info->x++;
	if (info->x >= screen.ws_col)
		info->x = 0;
	modify_string(info, str2, insert_len);
	if (info->is_his)
		info->no_move_his = 1;
	return (0);
}
