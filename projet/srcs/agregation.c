/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agregation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:05:21 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/06 14:39:42 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				check_agregation(t_parselex *list, t_shell *info)
{
	if (list->next && !(ft_strcmp(list->next->cutting[0], "2>&1")))
		info->fd_err = dup(info->save_stdout);
	else if (list->next && !(ft_strcmp(list->next->cutting[0], "2>&")))
		info->fd_err = dup(info->save_stdout);
//	else if (list->next && !(ft_strcmp(list->next->cutting[0], "2>&-")))
//		info->fd_out = dup(save_stderr);
//	else if (list->next && !(ft_strcmp(list->next->cutting[0], "1>&-")))
//		info->fd_out = dup(save_stderr);
	else if (list->next && !(ft_strcmp(list->next->cutting[0], "1>&2")))
		info->fd_out = dup(info->save_stderr);
	else
		return;
	delete_next_token(list);
}
