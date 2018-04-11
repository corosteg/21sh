/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:43:25 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/11 20:16:55 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		print_var(char *command, t_env *list, int out)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = ft_strdup(&command[i]);
	while (list)
	{
		if (!(ft_strncmp(tmp, list->var, ft_strclen(list->var, '='))) &&
				(list->var[ft_strclen(list->var, '=')] + 1) != '\0' &&
				command != NULL)
			ft_putstr_fd(&list->var[ft_strclen(list->var, '=')] + 1, out);
		list = list->next;
	}
	free(tmp);
}

int			ft_echo(char **command, t_env *list, int out)
{
	int		i;
	int		nl;

	i = 0;
	nl = 0;
	if (!(command[i]))
		return (0);
	if (command[1] != NULL && !ft_strcmp(command[1], "-n"))
	{
		nl = 1;
		i++;
	}
	while (command[++i])
	{
		if (nl == 1 || i > 1 || i > 2)
			ft_putstr_fd(" ", out);
		if (command[i][0] == '$')
			print_var(command[i], list, out);
		else if (command[i][0] != '$')
			ft_putstr_fd(command[i], out);
	}
	if (nl != 1)
		ft_putstr_fd("\n", out);
	return (0);
}
