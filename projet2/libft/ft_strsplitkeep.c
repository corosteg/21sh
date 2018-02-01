/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 21:10:21 by corosteg          #+#    #+#             */
/*   Updated: 2018/01/31 16:53:36 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../srcs/21sh.h"

int				one_of(char const *s, char *c, int nb)
{
	int		i;

	i = 0;
	if (s[nb] == '\0' || c == NULL)
		return (0);
	while (c[i])
	{
		if ((s[nb] == '0' || s[nb] == '1' || s[nb] == '2') && s[nb + 1] == '>')
		{
			if (s[nb + 2] == '&' || (s[nb + 2] == '&' && s[nb + 3] != ' '))
				return (1);
		}
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
		while (one_of(s, c, i))
			i++;
		if (s[i] != '\0')
			compteur++;
		while (s[i] && (!(one_of(s, c, i))))
			i++;
	}
	return (compteur);
}

static char			**ft_split(char const *s, char *c, char **str)
{
	int				i;
	int				count;
	int				count2;
	int				len;
	int				r;

	len = 0;
	i = 0;
	count = 0;
	r = 0;
	while (s[i])
	{
		count2 = 0;
		while (one_of(s, c, i))
			i++;
		while (s[i] && (!(one_of(s, c, i))))
		{
			if (s[i] == '\"')
				r++;
			i++;
		}
		if ((one_of(s, c, i)) && r == 1)
		{
			if (s[i] == s[i + 1])
				i = i + 2;
			else
				i++;
			r--;
		}
		while (s[i] && (!(one_of(s, c, i))))
			i++;
		str[count] = (char*)malloc(sizeof(char) * (i + 1));
		while (len < i)
			str[count][count2++] = s[len++];
		str[count++][count2] = '\0';
	}
	str[count] = NULL;
	return (str);
}

char				**ft_strsplitkeep(char const *s, char *c)
{
	char			**str;

	if (s == NULL)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_compte(s, c) + 1))))
		return (NULL);
	return (ft_split(s, c, str));
}
