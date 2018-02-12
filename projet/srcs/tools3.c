/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:46:03 by corosteg          #+#    #+#             */
/*   Updated: 2018/02/05 19:18:24 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		reset_fd_tool(t_shell *info)
{
	close(info->fd_in);
	close(info->fd_out);
	info->fd_in = dup(info->save_stdin);
	info->fd_out = dup(info->save_stdout);
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
