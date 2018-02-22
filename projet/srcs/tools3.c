/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:46:03 by corosteg          #+#    #+#             */
/*   Updated: 2018/02/22 20:33:15 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		reset_fd_tool(t_shell *info)
{
	close(0);
	close(info->fd_in);
	info->fd_in = dup(info->save_stdin);
	dup2(info->save_stdin, 0);
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
