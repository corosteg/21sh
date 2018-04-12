/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 23:09:40 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 17:41:48 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		swap_that(char **ta, int i)
{
	char		*tmp;

	tmp = ta[i];
	ta[i] = ta[i + 1];
	ta[i + 1] = tmp;
}

static char		*create_final_str(char **ta)
{
	int		i;
	char	*final;

	i = 1;
	final = ft_strdup(ta[0]);
	final = ft_strjoin(final, " ");
	while (ta[i])
	{
		final = ft_strjoin(final, ta[i]);
		final = ft_strjoin(final, " ");
		i++;
	}
	return (final);
}

static void		swap_at_final(char **ta, int *i)
{
	int		a;
	char	*tmp;
	char	*tmp2;

	a = 0;
	while (ta[a])
		a++;
	tmp = ta[a - 2];
	tmp2 = ta[a - 1];
	ta[a - 2] = ta[*i];
	ta[a - 1] = ta[*i + 1];
	ta[*i] = tmp;
	ta[*i + 1] = tmp2;
	*i = 1;
}

char			*parse_flag(char *str)
{
	char		**ta;
	char		*final;
	int			i;

	i = 0;
	while (str[i] && str[i] != '>' && str[i] != '<')
		i++;
	if (str[i] == '\0')
		return (str);
	i = 1;
	ta = ft_strsplit(str, ' ');
	while (ta[i + 2])
	{
		if (ta[i][0] == '>' || ta[i][0] == '<')
			swap_at_final(ta, &i);
		if (ta[i + 1] && ft_strcmp(ta[i], ta[i + 1]) > 0)
		{
			swap_that(ta, i);
			i = 1;
		}
		i++;
	}
	final = create_final_str(ta);
	return (final);
}
