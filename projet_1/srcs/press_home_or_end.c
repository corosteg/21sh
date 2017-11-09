/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_home_or_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:05:05 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/09 19:07:40 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void			p_home(t_shell *info)
{
	while (info->len > 0)
		p_left(info);
}

void			p_end(t_shell *info)
{
	while (info->len < ft_strlen(info->command))
		p_right(info);
}
