/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agregation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:05:21 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/09 16:51:18 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				check_agregation(t_parselex *list, t_shell *info)
{
	if (list->next && list->next->next 
	&& !(ft_strcmp(list->next->cutting[0], "2>&")) 
	&& !(ft_strcmp(list->next->next->cutting[0], "1")))
	{
		info->fd_err = dup(info->fd_out);
		info->ag = 2;
	}
	else if (list->next && list->next->next 
	&& !(ft_strcmp(list->next->cutting[0], "2>&")) 
	&& !(ft_strcmp(list->next->next->cutting[0], "-")))
	{
		close(info->fd_err);
		close(2);
		info->ag = 0;
	}
//	else if (list->next && !(ft_strcmp(list->next->cutting[0], "2>&-")))
//		info->fd_out = dup(save_stderr);
//	else if (list->next && !(ft_strcmp(list->next->cutting[0], "1>&-")))
//		info->fd_out = dup(save_stderr);
	else if (list->next && list->next->next 
	&& !(ft_strcmp(list->next->cutting[0], "1>&")) 
	&& !(ft_strcmp(list->next->next->cutting[0], "-")))
	{
		close(1);
	//	info->fd_out = 0;
	}
	else if (list->next && list->next->next 
	&& !(ft_strcmp(list->next->cutting[0], "1>&")) 
	&& !(ft_strcmp(list->next->next->cutting[0], "2")))
	{
	//	info->fd_out = dup(info->save_stderr);
		info->ag2 = 1;
		info->ag = 2;
	}
	else
		return;
	delete_next_token(list);
}
