/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:08:34 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/28 20:50:33 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char			*ft_chardup(int c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[1] = '\0';
	str[0] = c;
	return (str);
}

int				check_press(int buf, t_shell *info, t_his *his)
{
	char	str[2];

	str[0] = (char)buf;
	str[1] = '\0';
	if (buf == 2117294875)
		p_delete(info);
	else if (buf == 4479771 && (info->len > 0))
		p_left(info);
	else if (buf == 4283163 && his != NULL)
		info->his = p_up(info, info->his);
	else if (buf == 4414235 && ((info->len) < ft_strlen(info->command)))
		p_right(info);
	else if (buf == 4348699)
		info->his = p_down(info, info->his);
	else if (buf == 32)
		p_space(info, " ");
	else if (buf == 27)
	{
		ft_print("j'entre\n");
		while (his)
		{
			ft_print("%s\n", his->command);
			his = his->next;
		}
	}
	else if  (buf == 127 && info->len > 0)
		p_backspace(info);
	else if ((buf > 32 && buf < 126) && (info->len == ft_strlen(info->command)))
		p_ascii(info, str, buf);
	else if ((buf > 32 && buf < 126) && (info->len < ft_strlen(info->command)))
		insert_ascii(info, str);
	else if (buf == 10)
		return (1);
	//printf("buf == %i\n", buf);
	//printf("y == %i\n", info->y);
	return (0);
}

t_his			*check_entry(t_shell *info, t_his *his)
{
	//char	*entry;
	int			buf;

	//entry = NULL;
	//tgoto(tgetstr("cm", NULL), 0, 0);
	tputs(tgetstr("im", NULL), 1, ft_putchar);
	//printf("%i\n", info->x);
	info->his = his;
	while (42)
	{
		buf = 0;
		if (read(0, &buf, sizeof(int)))
		{
			if (check_press(buf, info, his))
				break ;
		}
	}
	his = manage_his_list(his, info);
	tputs(tgetstr("ei", NULL), 1, ft_putchar);
	ft_print("\n     ");
	ft_print("%s\n", info->command);
	free(info->command);
	info->command = NULL;
	free(info);
	info = NULL;
	return (his);
}
