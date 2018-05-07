/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_shift_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:27:42 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 18:52:33 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			p_s_right(t_shell *info)
{
	while (info->command[info->len] && info->command[info->len] != ' ')
		p_right(info);
	while (info->command[info->len] && info->command[info->len] == ' ')
		p_right(info);
}
