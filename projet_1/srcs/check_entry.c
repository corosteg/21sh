/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:08:34 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/17 21:24:47 by corosteg         ###   ########.fr       */
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

void			print_cpy(int buf, t_shell *info)
{
	int			ascii;
	char		str[5];
	char		tmp[2];
	int			i = 0;

	str[0] = buf % 128;
	str[1] = buf >> 8;
	str[2] = buf >> 16;
	str[3] = buf >> 24;
	str[4] = '\0';
	while (str[i])
	{
		tmp[0] = str[i];
		tmp[1] = '\0';
		p_ascii(info, tmp, (int)str[i]);
		i++;
	}
}

int				check_copy(int buf)
{
	char	check[4];
	int		i;

	i = 0;
	check[0] = buf % 128;
	check[1] = buf >> 8;
	check[2] = buf >> 16;
	check[3] = buf >> 24;
	while (i < 4)
	{
		if ((int)check[i] > 126 || (int)check[i] < 32)
			return (0);
		i++;
	}
	return (1);
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
	else if (buf == 4283163 && his != NULL && !(info->no_move_his))
	{
		info->his = p_up(info, info->his);
		info->is_his = 1;
	}
	else if (buf == 4414235 && ((info->len) < ft_strlen(info->command)))
		p_right(info);
	else if (buf == 4348699 && his != NULL && his->last != 3 &&
			!(info->no_move_his))
		info->his = p_down(info, info->his);
	else if (check_copy(buf))
		print_cpy(buf, info);
	else if  (buf == 127 && info->len > 0)
		p_backspace(info, 0);
	else if ((buf > 32 && buf < 126) && (info->len == ft_strlen(info->command)))
		p_ascii(info, str, buf);
	else if ((buf > 32 && buf < 126) && (info->len < ft_strlen(info->command)))
		insert_ascii(info, str);
	else if (buf == 32)
		p_space(info, " ");
	else if (buf == 16690)
		p_s_up(info);
	else if (buf == 16946)
		p_s_down(info);
	else if (buf == 17202)
		p_s_right(info);
	else if (buf == 17458)
		p_s_left(info);
	else if (buf == 4741915)
		p_home(info);
	else if (buf == 4610843)
		p_end(info);
	else if (buf == 10)
		return (1);
//	printf("buf == %i\n", buf);
	return (0);
}


t_his			*check_entry(t_shell *info, t_his *his)
{
	char		*tmp;
	int			buf;

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
	check_quotes(info);
	if (info->quote == 1)
		manage_squote(info);
	if (info->dquote == 1)
		manage_dquote(info);
	his = manage_his_list(his, info);
//	ft_print("\n     ");
//	ft_print("%s\n", info->command);
	if (parse_command(info->command))
		core(info);
	return (his);
}
