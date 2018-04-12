/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:47:41 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/09 17:39:55 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env		*remv_var(t_env *rmv, t_env *list)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp = list;
	while (tmp->next && tmp->next != rmv)
		tmp = tmp->next;
	if (tmp->next)
		tmp2 = tmp->next;
	else
		tmp2 = NULL;
	tmp->next = tmp->next->next;
	free(tmp2->var);
	tmp2->var = NULL;
	free(tmp2);
	tmp2 = NULL;
	return (list);
}

int			check_as_var_u(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=' && str[i] != ' ')
		i++;
	if (str[i] == '=')
		return (1);
	else
		return (0);
}

static int	check_ft_envfunct_action(char **command2, t_env *list, int a)
{
	a = 0;
	if (!(ft_strncmp(command2[1], list->var, (ft_strclen(list->var, '='))))
	&& command2[2] != NULL)
		return (1);
	if (!(ft_strncmp(command2[1], list->var, (ft_strclen(list->var, '='))))
	&& command2[2] == NULL)
		return (2);
	return (0);
}

t_env		*ft_unsetenv(char **command, t_env *list, t_shell *info)
{
	t_env		*tmp;

	if (command[1] == NULL)
	{
		ft_putstr_fd("usage: unsetenv [VAR] to delete\n", info->fd_err);
		return (list);
	}
	if ((command[1] && command[2]) /*|| !(check_as_var_u(command[1]))*/)
	{
		ft_putstr_fd("usage: unsetenv [VAR] to delete\n", info->fd_err);
		return (list);
	}
	tmp = list;
	while (tmp)
	{
		if (check_ft_envfunct_action(command, tmp, 0) == 2)
		{
			remv_var(tmp, list);
			break ;
		}
		tmp = tmp->next;
	}
	return (list);
}
