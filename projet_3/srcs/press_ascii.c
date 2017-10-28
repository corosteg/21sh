/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:28:34 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/26 20:58:38 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				p_ascii(t_shell *info, char *str, int buf)
{
	ft_putchar(buf);
	info->len++;
	if (info->command == NULL)
		info->command = ft_strdup(str);
	else
		info->command = ft_strfreejoin(info->command, str, 1);
}
