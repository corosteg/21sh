/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:56:56 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/11 19:40:50 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			sig_int(int i)
{
	i = 0;
}

void			check_signal(void)
{
	signal(SIGINT, sig_int);
}
