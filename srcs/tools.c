/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:35:47 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 19:16:59 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			p_ascii_emulation(char *str, t_shell *info)
{
	int					i;
	struct winsize		screen;

	i = 0;
	info->x = 5;
	info->y = 0;
	info->len = 0;
	ioctl(0, TIOCGWINSZ, &screen);
	while (str[i])
	{
		ft_putchar(str[i]);
		info->len++;
		info->x++;
		if (info->x > screen.ws_col - 1)
		{
			info->x = 0;
			tputs(tgetstr("do", NULL), 1, ft_putchar);
			tputs(tgetstr("cr", NULL), 1, ft_putchar);
			info->y++;
		}
		i++;
	}
}

t_env			*copy_env(char **env, t_env *list)
{
	t_env		*tmp;
	int			i;

	i = 1;
	list = (t_env*)malloc(sizeof(t_env));
	list->var = ft_strdup(env[0]);
	list->next = NULL;
	tmp = list;
	while (env[i])
	{
		tmp->next = (t_env*)malloc(sizeof(t_env));
		tmp = tmp->next;
		tmp->var = ft_strdup(env[i]);
		tmp->next = NULL;
		i++;
	}
	return (list);
}

void			press_string(t_shell *info)
{
	int					i;
	struct winsize		screen;

	i = 0;
	ioctl(0, TIOCGWINSZ, &screen);
	while (info->command[i])
	{
		if (i >= info->start_cp && i < info->end_cp)
			tputs(tgetstr("mr", NULL), 1, ft_putchar);
		ft_putchar(info->command[i]);
		tputs(tgetstr("me", NULL), 1, ft_putchar);
		info->len++;
		info->x++;
		if (info->x > screen.ws_col - 1)
		{
			info->x = 0;
			tputs(tgetstr("do", NULL), 1, ft_putchar);
			tputs(tgetstr("cr", NULL), 1, ft_putchar);
			info->y++;
		}
		i++;
	}
}

char			**alloc_tab(t_env *list)
{
	int			i;
	t_env		*tmp;
	char		**tab1;

	if (list == NULL)
		return (NULL);
	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (!(tab1 = (char**)malloc(sizeof(char*) * (i + 1))))
		return (0);
	tab1[i] = NULL;
	i = 0;
	while (list)
	{
		tab1[i] = ft_strdup(list->var);
		i++;
		list = list->next;
	}
	return (tab1);
}
