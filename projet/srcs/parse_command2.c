/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:05:54 by paoroste          #+#    #+#             */
/*   Updated: 2018/04/16 17:15:30 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				parse3(t_shell *info)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (info->command[i])
	{
		if (info->command[i] == ';')
		{
			a = i;
			a++;
			while (info->command[a] == ' ')
				a++;
			if (info->command[a] == ';')
				return (ft_print(
				"\n21sh: syntax error near unexpected token ';'\n"));
		}
		i++;
	}
	return (0);
}

void			parse2_2(t_shell *info)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (info->command[i])
	{
		if ((info->command[i] == '\"' || info->command[i] == '\'')
			&& info->command[i + 1] != ' ')
		{
			tmp = ft_strndup(info->command, i + 1);
			tmp = ft_strfreejoin(tmp, " ", 1);
			tmp = ft_strfreejoin(tmp, &info->command[i + 1], 1);
			tmp2 = info->command;
			info->command = ft_strdup(tmp);
			free(tmp);
			free(tmp2);
		}
		i++;
	}
}
