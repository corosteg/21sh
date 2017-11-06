/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:24:18 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/30 18:51:07 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_his			*his_next_null(t_shell *info, t_his *his)
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
	while (i < ft_strlen(info->command))
	{
		tputs(tgetstr("dc", NULL), 1, ft_putchar);
		i++;
	}
	ft_print("%s", his->command);
	info->len = ft_strlen(his->command);
	tmp = info->command2;
	info->command2 = ft_strdup(info->command);
	free(tmp);
	info->command = ft_strdup(his->command);
	his->last = 0;
	if (his->prev == NULL)
		his->first = 1;
	else
		his = his->prev;
	return (his);
}

t_his			*p_up2(t_shell *info, t_his *his)
{
	int		i;

	i = info->len;
	while (i > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar);
		i--;
	}
	i = 0;
	while (his->next && i < ft_strlen(his->next->command))
	{
		tputs(tgetstr("dc", NULL), 1, ft_putchar);
		i++;
	}
	ft_print("%s", his->command);
	info->len = ft_strlen(his->command);
	info->command = ft_strdup(his->command);
	his->last = 0;
	if (his->prev == NULL)
		his->first = 1;
	else
		his = his->prev;
	return(his);
}

t_his			*p_up(t_shell *info, t_his *his)
{
	if (his->next == NULL && !(his->first))
		return (his_next_null(info, his));
	if (his->prev == NULL && his->first)
		return (his);
	else
		return (p_up2(info, his));
	return (his);
}
