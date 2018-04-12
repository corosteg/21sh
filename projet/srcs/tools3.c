/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:46:03 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/09 16:08:43 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		reset_fd_tool(t_shell *info)
{
	close(info->fd_in);
	close(info->fd_out);
	info->fd_in = dup(info->save_stdin);
	info->fd_out = dup(info->save_stdout);
	info->fd_err = dup(info->save_stderr);
	info->ag = 1;
	info->ag2 = 1;
}

void			free_list_path_tool(t_path *list)
{
	t_path		*tmp;

	while (list)
	{
		free(list->path);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
