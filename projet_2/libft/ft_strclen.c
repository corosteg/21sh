/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcln.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:10:44 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/25 21:53:51 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strclen(char *str, char c)
{
	int		a;

	a = 0;
	if (str == NULL)
		return (0);
	while ((str[a] != '\0') && str[a] && str[a] != c)
		a++;
	return (a);
}
