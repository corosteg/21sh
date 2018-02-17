/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitmulti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:00:51 by paoroste          #+#    #+#             */
/*   Updated: 2018/02/14 16:10:43 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					one_of3(char const *s, char *c, int nb)
{
	int		i;

	i = 0;
	if (s[nb] == '\0' || c == NULL)
		return (0);
	while (c[i])
	{
		if ((s[nb] == '0' || s[nb] == '1' || s[nb] == '2') && s[nb + 1] == '>')
		{
			if (s[nb + 2] == '&' || (s[nb + 2] == '&' && s[nb + 3] != '#'))
				return (1);
		}
		if (nb > 2 && s[nb] != '#' && s[nb - 1] == '&' && s[nb - 2] == '>')
			return (1);
		if (s[nb] == '&' || s[nb] == '|' || s[nb] == '<' || s[nb] == '>')
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

static int			ft_compte(char const *s, char *c)
{
	unsigned int	i;
	int				compteur;

	i = 0;
	compteur = 0;
	while (s[i])
	{
		while (one_of3(s, c, i))
			i++;
		if (s[i] != '\0')
			compteur++;
		while (s[i] && (!(one_of3(s, c, i))))
			i++;
	}
	return (compteur);
}

int					fck_quote2(char const *s, int len, char *c)
{
	int		r;

	r = 0;
	while (s[len] && (!(one_of3(s, c, len))))
	{
		if (s[len] == '\"'/* || s[len] == '\''*/)
			r++;
		len++;
	}
	if ((one_of3(s, c, len)) && r == 1)
	{
		while (s[len] != '\"' /*|| s[len] != '\''*/)
			len++;
		len++;
	}
	return (len);
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
		while (one_of3(s, c, i))
			i++;
		len = i;
		len = fck_quote2(s, len, c);
		(s[i] == '\"' || s[i] == '\'') ? len-- : 0;
		(s[i] == '\"' || s[i] == '\'') ? i++ : 0;
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
