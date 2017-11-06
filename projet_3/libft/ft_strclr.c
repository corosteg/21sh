/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:49:56 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/23 19:09:47 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int a;

	a = 0;
	if (s != 0)
	{
		while (s[a])
		{
			s[a] = '\0';
			a++;
		}
	}
	else
		a = 9;
}
