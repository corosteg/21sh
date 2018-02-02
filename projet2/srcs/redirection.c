/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:08:35 by corosteg          #+#    #+#             */
/*   Updated: 2018/02/02 23:32:24 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_parselex				*redir_simpl(t_shell *info, t_parselex *list)
{
	if (list->next->next == NULL)
		return (NULL);
	printf("info->fd_out  --->%d%s\n", info->fd_out, list->next->next->cutting[0]);
	info->fd_out = open(list->next->next->cutting[0], O_CREAT | O_TRUNC
		| O_WRONLY, 0777);
	ft_print("info->fd_out2 --->%d\n", info->fd_out);
	exec_simpl(list->cutting, info);
	while (list && !(end_token_tool(list->cutting[0], info)))
		list = list->next;
	return (list);
}
