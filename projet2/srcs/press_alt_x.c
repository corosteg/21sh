/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_alt_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:34:55 by corosteg          #+#    #+#             */
/*   Updated: 2018/01/24 17:41:30 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh"

int				p_a_x(t_shell *info)
{
	int		i;

	i = info->end_cp - info->start_cp;
	while (i > 0)
		p_right(t_shell *info);
	i = info->end_cp - info->start_cp;
	while (i > 0)
		p_backspace(info, 0);
}
