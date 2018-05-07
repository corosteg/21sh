/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:01:10 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 19:14:43 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			check_quote(char *str, int *i)
{
	while (str[*i] == '\'' || str[*i] == '\'')
		*i = *i + 1;
	while (str[*i] != '\'' && str[*i] != '\'')
		*i = *i + 1;
	while (str[*i] == '\'' || str[*i] == '\'')
		*i = *i + 1;
}

char			*str_quote(int *i, char *str)
{
	int		a;
	int		b;

	a = *i;
	if (str[*i] != '\"' && str[*i] != '\'')
		return (NULL);
	check_quote(str, i);
	b = *i - a;
	str = ft_strndup(&str[a], b);
	return (str);
}
