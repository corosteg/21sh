/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:14:13 by paoroste          #+#    #+#             */
/*   Updated: 2018/04/09 13:26:14 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				one_ofs(char *s, char *c, int nb, int i)
{
	if (s[nb] == '\0' || c == NULL)
		return (0);
	while (c[i])
	{
		if ((s[nb] == '0' || s[nb] == '1' || s[nb] == '2') && s[nb + 1] == '>')
			if (s[nb + 2] == '&' || (s[nb + 2] == '&' && s[nb + 3] == '-'))
				return (1);
		if ((s[nb] == '1' || s[nb] == '2') && s[nb + 1] == '>')
			return (1);
		else if (s[nb] == '&' || s[nb] == '|' || s[nb] == '<' || s[nb] == '>')
		{
			if (c[i] == s[nb] && c[i] == s[nb + 1])
				return (1);
		}
		if (c[i] == s[nb] && (s[nb] != '0' && s[nb] != '1' && s[nb] != '2'))
			return (1);
		i++;
	}
	return (0);
}

int		is_even(int nb)
{
	if (nb % 2 == 0)
		return (1);
	else
		return (0);
}

int		epur_len(char *str, int i, int nb, int odd)
{
	while (str[i])
	{
		if (i > 0 && str[i - 1] == '\"')
			odd++;
		if (IS_SPACE(str[i]) && is_even(odd) == 1)
		{
			if (is_even(odd) == 1 && str[i + 1] != '\0')
				nb++;
			while (IS_SPACE(str[i]) && str[i + 1] != '\0')
				i++;
		}
		nb++;
		i++;
	}
	return (nb);
}
