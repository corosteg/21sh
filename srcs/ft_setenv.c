/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:48:03 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/09 17:44:17 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env		*modif(t_env *list, char *str)
{
	char	*tmp;

	tmp = list->var;
	list->var = ft_strdup(str);
	free(tmp);
	return (list);
}

t_env		*add_var(t_env *list, char **command2)
{
	t_env	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_env*)malloc(sizeof(t_env));
	tmp = tmp->next;
	tmp->var = ft_strdup(command2[1]);
	tmp->next = NULL;
	return (list);
}

int			check_as_var(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
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
	if (!(ft_strncmp(command2[1], list->var, (ft_strclen(list->var, '=') + 1)))
	&& command2[2] != NULL)
		return (1);
	if (!(ft_strncmp(command2[1], list->var, (ft_strclen(list->var, '=') + 1)))
	&& command2[2] == NULL)
		return (2);
	return (0);
}

t_env		*ft_setenv(char **command, t_env *list, t_shell *info)
{
	t_env		*tmp;
	int			m;

	m = 0;
	if ((command[1] && command[2]) || !(check_as_var(command[1])))
	{
		ft_putstr_fd("usage: setenv [VAR=] new value\n", info->fd_err);
		ft_putstr_fd("       setenv [NEWVAR=] value\n", info->fd_err);
		return (list);
	}
	tmp = list;
	while (tmp)
	{
		if (command[1])
			if (check_ft_envfunct_action(command, tmp, 0) == 2)
			{
				modif(tmp, command[1]);
				m = 42;
			}
		tmp = tmp->next;
	}
	if (m == 0)
		list = add_var(list, command);
	return (list);
}
