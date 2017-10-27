/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_backspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:53:40 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/26 19:18:16 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void			modify_string(t_shell *info)
{
	char	*str;
	char	*tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	tmp = info->command;
	str = (char*)malloc(sizeof(char) * ft_strlen(info->command));
	str[ft_strlen(info->command) - 1] = '\0';
	while (info->command[i])
	{
		if (i == info->len)
			i++;
		if (info->command[i] == '\0')
			break ;
		str[a] = info->command[i];
		i++;
		a++;
	}
	info->command = str;
	free(tmp);
}

void				p_backspace(t_shell *info)
{
	info->len--;
	modify_string(info);
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	tputs(tgetstr("dc", NULL), 1, ft_putchar);
}
