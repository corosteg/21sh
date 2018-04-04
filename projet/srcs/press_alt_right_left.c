/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_alt_right_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:20:40 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/04 17:37:20 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh.h"

int			p_a_left(t_shell *info)
{
	if (info->len == 0)
		return (0);
	if (info->end_cp == -1 && info->start_cp == -1)
	{
		info->end_cp = info->len;
		p_left2(info);
		info->start_cp = info->len;
	}
	else if (info->end_cp > info->start_cp)
	{
		info->end_cp--;
		p_left2(info);
		if (info->end_cp == info->start_cp)
		{
			info->end_cp = -1;
			info->start_cp = -1;
		}
	}
	else
	{
		info->start_cp--;
		p_left2(info);
	}
	tool_refresh(info);
	return (0);
}

int			p_a_right(t_shell *info)
{
	if (info->len == (int)ft_strlen(info->command))
		return (0);
	if (info->end_cp == -1 && info->start_cp == -1)
	{
		info->start_cp = info->len;
		p_right2(info);
		info->end_cp = info->len;
	}
	else if (info->end_cp > info->start_cp)
	{
		info->end_cp++;
		p_right2(info);
		if (info->end_cp == info->start_cp)
		{
			info->end_cp = -1;
			info->start_cp = -1;
		}
	}
	else
	{
		info->start_cp++;
		p_right2(info);
	}
	tool_refresh(info);
	return (0);
}
