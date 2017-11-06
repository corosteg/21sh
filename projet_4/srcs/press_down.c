/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:43:20 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/06 17:42:36 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"


static t_his			*his_prev_null(t_shell *info, t_his *his)
{
	int		i;
	char	*tmp;

	i = info->len;
	while (i > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar);
		i--;
	}
	i = 0;
	while (i < ft_strlen(his->command))
	{
		tputs(tgetstr("dc", NULL), 1, ft_putchar);
		i++;
	}
	his->first = 0;
	ft_print("%s", his->command);
	info->len = ft_strlen(his->command);
	tmp = info->command;
	info->command = ft_strdup(his->command);
	free(tmp);
	if (his->next == NULL)
		his->last = 1;
	else
		his = his->next;
	return (his);
}

static t_his			*p_down2(t_shell *info, t_his *his)
{
	int		i;
	char	*tmp;

	i = info->len;
	while (i > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar);
		i--;
	}
	i = 0;
	while (i < ft_strlen(his->prev->command))
	{
		tputs(tgetstr("dc", NULL), 1, ft_putchar);
		i++;
	}
	ft_print("%s", his->command);
	info->len = ft_strlen(his->command);
	tmp = info->command;
	info->command = ft_strdup(his->command);
	free(tmp);
	if (his->next == NULL)
		his->last = 1;
	else
		his = his->next;
	return(his);
}

static void				his_next_null(t_shell *info, t_his *his)
{
	int		i;
	char	*tmp;

	i = info->len;
	while (i > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar);
		i--;
	}
	i = 0;
	while (i < ft_strlen(his->command))
	{
		tputs(tgetstr("dc", NULL), 1, ft_putchar);
		i++;
	}
	tmp = info->command2;
	info->command = ft_strdup(info->command2);
	info->command2 = ft_strdup("\0");
	ft_print("%s", info->command);
	info->len = ft_strlen(info->command);
	free(tmp);
	his->last = 3;
	info->is_his = 0;
}

t_his					*p_down(t_shell *info, t_his *his)
{
	if (his->prev == NULL && !(his->last))
		return (his_prev_null(info, his));
	if (his->next == NULL && his->last)
		his_next_null(info, his);
	else
		return (p_down2(info, his));
	return (his);
}
