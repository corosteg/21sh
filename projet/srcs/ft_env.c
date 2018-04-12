/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:31:23 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/10 14:33:41 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				ft_env(t_env *list, int out)
{
	while (list)
	{
		ft_putstr_fd(list->var, out);
		ft_putstr_fd("\n", out);
		list = list->next;
	}
}
