/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:53:25 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/28 20:36:14 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_shell				*init_info_list(t_shell *info)
{
	info = (t_shell*)malloc(sizeof(t_shell));
	info->command = NULL;
	info->command = ft_strdup("\0");
	info->x = 6;
	info->y = 0;
	info->len = 0;
	return (info);
}
