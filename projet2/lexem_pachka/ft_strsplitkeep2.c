/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 21:10:21 by corosteg          #+#    #+#             */
/*   Updated: 2018/01/29 19:40:35 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "21sh.h"
# define IS_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x == '\f')

static int				one_of5(char cmp, char *c, char cmp2)
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

static int			ft_compte2(char const *s, char *c)
{
	unsigned int	i;
	int				compteur;

	i = 0;
	compteur = 0;
	while (s[i])
	{
		while (one_of5(s[i], c, s[i + 1]))
			i++;
		if (s[i] != '\0')
			compteur++;
		while (s[i] && (!(one_of5(s[i], c, s[i + 1]))))
			i++;
	}
	return (compteur);
}

static char			**ft_split2(char const *s, char *c, char **str)
{
	int				i;
	int				count;
	int				count2;
	int				len;

	len = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		count2 = 0;
		while (one_of5(s[i], c, s[i + 1]))
			i++;
		while (IS_SPACE(s[i]))
			i++;
		if (s[i] == '\"' || s[i] == '\'')
			str[count++] = str_quote(&i, (char*)s);
		len = i;
		while (s[i] && (!(one_of5(s[i], c, s[i + 1]))))
			i++;
		str[count] = (char*)malloc(sizeof(char) * (i + 1));
		while (len < i)
			str[count][count2++] = s[len++];
		str[count++][count2] = '\0';
	}
	str[count] = NULL;
	return (str);
}

char				**ft_strsplitkeep2(char const *s, char *c)
{
	char			**str;

	if (s == NULL)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_compte2(s, c) + 1))))
		return (NULL);
	return (ft_split2(s, c, str));
}
