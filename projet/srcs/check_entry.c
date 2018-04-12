/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:08:34 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 14:37:38 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				check_press(int buf, t_shell *info, t_his *his)
{
	char	str[2];

	str[0] = (char)buf;
	str[1] = '\0';
	if (buf == DELETE_K)
		p_delete(info);
	else if (buf == LEFT_K && (info->len > 0))
		p_left(info);
	else if (buf == UP_K && his != NULL && !(info->no_move_his))
	{
		info->his = p_up(info, info->his);
		info->is_his = 1;
	}
	else if (buf == RIGHT_K && ((info->len) < (int)ft_strlen(info->command)))
		p_right(info);
	else if (buf == DOWN_K && his != NULL && his->last != 3 &&
			!(info->no_move_his))
		info->his = p_down(info, info->his);
	else if (check_copy(buf))
		print_cpy(buf, info);
	else if  (buf == BCKSPCE_K && info->len > 0)
		p_backspace(info, 0);
	else if ((buf > 32 && buf < 127) && (info->len == (int)ft_strlen(info->command)))
		p_ascii(info, str, buf);
	else if ((buf > 32 && buf < 127) && (info->len < (int)ft_strlen(info->command)))
		insert_ascii(info, str);
	else if (buf == SPCE_K)
		p_space(info, " ");
	else if (buf == SHIFTUP_K)
		p_s_up(info);
	else if (buf == SHIFTDWN_K)
		p_s_down(info);
	else if (buf == SHIFTRIGHT_K)
		p_s_right(info);
	else if (buf == SHIFTLEFT_K)
		p_s_left(info);
	else if (buf == ALTLEFT_K)
		p_a_left(info);
	else if (buf == ALTRIGHT_K)
		p_a_right(info);
	else if (buf == ALTC_K)
		p_a_c(info);
	else if (buf == ALTV_K)
		p_a_v(info);
	else if (buf == ALTX_K)
		p_a_x(info);
	else if (buf == HOME_K)
		p_home(info);
	else if (buf == END_K)
		p_end(info);
	else if (buf == 3)
	{
		free(info->command);
		info->command = ft_strdup("\0");
		return(1);
	}
	else if (buf == 4 && info->len == 0)
		ft_exit2(info);
	else if (buf == RET_K)
		return (1);
	return (0);
}


t_his			*check_entry(t_shell *info, t_his *his)
{
	int			buf;

	init_term();
	info->his = his;
	while (42)
	{
		buf = 0;
		if (read(STDIN_FILENO, &buf, sizeof(int)))
		{
			if (check_press(buf, info, his))
				break ;
		}
	}
	init_term2();
	check_quotes(info);
	if (info->quote == 1)
		manage_squote(info);
	if (info->dquote == 1)
		manage_dquote(info);
	his = manage_his_list(his, info);
	ft_print("\n");
	if (parse_command(info->command))
		core(info);
	return (his);
}
