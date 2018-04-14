/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitmulti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:00:51 by paoroste          #+#    #+#             */
/*   Updated: 2018/04/14 18:54:51 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					one_3(char const *s, char *c, int nb)
{
	int		i;

	i = 0;
	if (s[nb] == '\0' || c == NULL)
		return (0);
	while (c[i])
	{
		if ((s[nb] == '0' || s[nb] == '1' || s[nb] == '2') && s[nb + 1] == '>')
			if (s[nb + 2] == '&' || (s[nb + 2] == '&' && s[nb + 3] == '-'))
				return (1);
		if ((s[nb] == '1' || s[nb] == '2') && s[nb + 1] == '>')
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

static int			compte(char const *s, char *c)
{
	unsigned int	i;
	int				compteur;
	int				r;

	i = 0;
	r = 0;
	compteur = 0;
	while (s[i])
	{
		if (r == 1)
		{
			while ((s[i] != '\"' || s[i] != '\'') && s[i] != '\0')
				i++;
			r = 0;
		}
		while (one_3(s, c, i))
			i++;
		if (s[i] != '\0')
			compteur++;
		while (s[i] && (!(one_3(s, c, i))))
		{
			if (s[i] == '\"' || s[i] == '\'')
				r++;
			i++;
		}
	}
	return (compteur);
}

int					quote2(char const *s, int len, char *c)
{
	int		r;
	int		i;

	r = 0;
	i = 0;
	while (one_3(s, c, len))
		len++;
	while (s[len] && (!(one_3(s, c, len))))
	{
		if (s[len] == '\"' || s[len] == '\'')
			r++;
		len++;
	}
	if ((one_3(s, c, len)) && r == 1)
	{
		while ((s[len] != '\"' || s[len] != '\'') && s[len] != '\0')
			len++;
		len++;
	}
	return (len);
}

static char			**split(char const *s, char *c, char **str, int count)
{
	int				i;
	int				count2;
	int				len;

	i = 0;
	while (s[i])
	{
		count2 = 0;
		while (one_3(s, c, i))
			i++;
		len = i;
		len = quote2(s, len, c);
		(s[i] == '\"' || s[i] == '\'') ? len-- : 0;
		(s[i] == '\"' || s[i] == '\'') ? i++ : 0;
		if (len > i)
		{
			str[count] = (char *)malloc(sizeof(char) * (len - i + 1));
			while (i < len)
				s[i] != '#' ? str[count][count2++] = s[i++] : i++;
			str[count++][count2] = '\0';
		}
	}
	str[count] = NULL;
	return (str);
}

char				**tool_lex1(char const *s, char *c)
{
	char			**str;

	if (s == NULL)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (compte(s, c) + 1))))
		return (NULL);
	return (split(s, c, str, 0));
}
