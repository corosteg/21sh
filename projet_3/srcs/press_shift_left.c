/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_shift_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:28:00 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/03 18:43:37 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void			p_s_left(t_shell *info)
{
	while(info->command[info->len] != ' '
			&& info->len > 0)
		p_left(info);
	while(info->command[info->len] == ' '
			&& info->len > 0)
		p_left(info);
}
