/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:01:10 by corosteg          #+#    #+#             */
/*   Updated: 2018/01/29 15:05:02 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/21sh.h"

void			check_quote(char *str, int *i)
{
	while (str[*i] == '\'' || str[*i] == '\"')
		*i= *i + 1;
	while (str[*i] != '\'' && str[*i] != '\'')
		*i = *i + 1;
	while (str[*i] == '\'' || str[*i] == '\"')
		*i= *i + 1;
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

/*int			main(void)
{
	int i = 3;
	printf("%s\n", str_quote(&i, "012\'\'\"\" koleine \'\'\"\""));
}*/
