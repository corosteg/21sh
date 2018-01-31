/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitmulti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:00:51 by paoroste          #+#    #+#             */
/*   Updated: 2018/01/29 12:50:40 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int				one_of3(char cmp, char *c, char cmp2)
{
	int		i;

	i = 0;
	if (cmp == '\0' || c == NULL)
		return (0);
	while (c[i])
	{
		if (cmp == '&' || cmp == '|' || cmp == '<' || cmp == '>')
		{
			if (c[i] == cmp && c[i] == cmp2)
				return (1);
		}
		if (c[i] == cmp)
			return (1);
		i++;
	}
	return (0);
}

static int			ft_compte(char const *s, char *c)
{
	unsigned int	i;
	int				compteur;

	i = 0;
	compteur = 0;
	while (s[i])
	{
		while (one_of3(s[i], c, s[i + 1]))
			i++;
		if (s[i] != '\0')
			compteur++;
		while (s[i] && (!(one_of3(s[i], c, s[i + 1]))))
			i++;
	}
	return (compteur);
}

static char			**ft_split(char const *s, char *c, char **str, int count)
{
	int				i;
	int				count2;
	int				len;

	i = 0;
	while (s[i])
	{
		count2 = 0;
		while (one_of3(s[i], c, s[i + 1]))
			i++;
		if (s[i] == '\"')
			while (s[i] != '\"')
				i++;
		len = i;
		while (s[len] && (!(one_of3(s[len], c, s[len + 1]))))
		{
			len++;
		}
		if (len > i)
		{
			str[count] = (char *)malloc(sizeof(char) * (len - i + 1));
			while (i < len)
				str[count][count2++] = s[i++];
			str[count++][count2] = '\0';
		}
	}
	str[count] = NULL;
	return (str);
}

char				**ft_splitmulti(char const *s, char *c)
{
	char			**str;

	if (s == NULL)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_compte(s, c) + 1))))
		return (NULL);
	return (ft_split(s, c, str, 0));
}
