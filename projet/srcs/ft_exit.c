/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:50:31 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/10 17:21:46 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*void		free_list(t_env *list)
{
	t_env	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		ft_strdel(&(list)->var);
		free(list);
		list = tmp;
	}
}

void		free_e_path(t_env *list)
{
	t_env	*tmp;

	while (list->next != NULL)
	{
		tmp = list->next;
		ft_strdel(&(list)->var);
		free(list);
		list = tmp;
	}
}

void		free_str(char **array)
{
	int	i;

	if (array)
	{
		i = -1;
		while (array[++i])
		{
			ft_strdel(&array[i]);
			free(array[i]);
		}
		free(array);
	}
}*/

void		ft_exit(t_parselex *first, t_shell *info)
{
	free_info(info);
	free_lex(first);
	exit(0);
}

void		ft_exit2(t_shell *info)
{
	free_info(info);
	exit(0);
}
