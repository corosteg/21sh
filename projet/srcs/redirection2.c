/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:10:48 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 19:10:56 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_parselex			*delete_next_token(t_parselex *list)
{
	t_parselex		*tmp;

	tmp = list->next;
	list->next = list->next->next;
	free_c_tab(tmp->cutting);
	free(tmp);
	tmp = list->next;
	list->next = list->next->next;
	free_c_tab(tmp->cutting);
	free(tmp);
	return (list);
}

t_parselex			*redir_left(t_shell *info, t_parselex *list,
						t_parselex *first)
{
	char	*ta[3];

	if (list->next->next == NULL)
		return (NULL);
	ta[0] = ft_strdup("/bin/cat");
	ta[1] = ft_strdup(list->next->next->cutting[0]);
	ta[2] = NULL;
	exec_in_pipe(ta, info, first, 1);
	free(ta[0]);
	free(ta[1]);
	list = delete_next_token(list);
	return (list);
}

t_parselex			*redir_heredoc(t_shell *info, t_parselex *list,
						t_parselex *first)
{
	char	*ta[3];

	if (list->next->next == NULL)
		return (NULL);
	ta[0] = ft_strdup("/bin/cat");
	ta[1] = ft_strdup(list->next->next->cutting[0]);
	ta[2] = NULL;
	exec_in_pipe(ta, info, first, 1);
	list = delete_next_token(list);
	free(ta[0]);
	free(ta[1]);
	return (list);
}
