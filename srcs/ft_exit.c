/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:50:31 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/13 16:48:57 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_exit(t_parselex *first, t_shell *info)
{
	free_info(info);
	free_lex(first);
	exit(0);
}

void		ft_exit2(t_shell *info)
{
	free_info(info);
	init_term2();
	exit(0);
}
