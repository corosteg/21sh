/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:09:40 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 16:31:58 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void				free_env(t_env *list)
{
	t_env		*tmp;

	while (list)
	{
		free(list->var);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void					free_lex(t_parselex *list)
{
	t_parselex	*tmp;

	while (list)
	{
		free_c_tab(list->cutting);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void					free_info(t_shell *info)
{
	free(info->command);
	free(info->command2);
	free(info->cp_string);
	if (info->env_int == 1)
		free_env(info->env);
	free(info);
}

void					free_lexem(t_lexem *list)
{
	t_lexem		*tmp;

	while (list)
	{
		free(list->command);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void					free_c_tab(char **array)
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
}
