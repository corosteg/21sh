/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 09:26:16 by paoroste          #+#    #+#             */
/*   Updated: 2018/01/31 17:12:09 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh.h"
int				one_ofs(char cmp, char *c, char cmp2)
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

void		ft_freestrarr(char **arr)
{
	int		i;

	if (arr)
	{
		i = -1;
		while (arr[++i])
		{
			ft_strdel(&arr[i]);
			free(arr[i]);
		}
		free(arr);
	}
}

int		is_even(int nb)
{
	if (nb % 2 == 0)
		return (1);
	else
		return (0);
}

char	*epur_cmd(char *str, int i, int nb, int odd)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * (ft_strlen(str)));
	//while (IS_SPACE(str[i]))
	//	i++;
	while (str[i] != '\0')
	{
		if (i > 0 && str[i - 1] == '\"')
			odd++;
		if (IS_SPACE(str[i]))
		{
			if (is_even(odd) == 1)
				new[nb++] = '#';
			while (IS_SPACE(str[i]) && (is_even(odd) == 1))
				i++;
		}
		new[nb++] = str[i++];
	}
	new[nb] = '\0';
	return (new);
}

t_parselex		*parselex(t_lexem *list)
{
	t_parselex	*newlist;
	t_parselex	*tmp;

	tmp = (t_parselex*)malloc(sizeof(t_parselex));
	newlist = tmp;
	newlist->cutting = ft_splitmulti(list->command, "#&;|<>");
	list = list->next;
	newlist->next = NULL;
	//free(tableau);
	//ft_freestrarr(tableau);
	while (list)
	{
		tmp->next = (t_parselex*)malloc(sizeof(t_parselex));
		tmp = tmp->next;
		if (one_ofs(list->command[0], "&;|<>", list->command[1]))
		{
			tmp->cutting = (char**)malloc(sizeof(char*) * 2);
			if (list->command[1] == list->command[0])
				tmp->cutting[0] = ft_strndup(list->command, 2);
			else
				tmp->cutting[0] = ft_strndup(list->command, 1);
			tmp->cutting[1] = NULL;
			tmp->next = NULL;
			tmp->next = (t_parselex*)malloc(sizeof(t_parselex));
			tmp = tmp->next;
		}
		tmp->cutting = ft_splitmulti(list->command, "#&|;<>");
		tmp->next = NULL;
		list = list->next;
	}
	//tmp2 = newlist;
	//int i = 0;
	/*while (tmp2)
	{
		while (tmp2->cutting[i])
		{
			ft_print("tab[%d]: ", i);
			ft_putstr(tmp2->cutting[i]);
			ft_putchar('\n');
			i++;
		}
		i = 0;
		ft_putstr(""RED"maillon suivant:\n\n"STOP"");
		tmp2 = tmp2->next;
	}*/
	return (newlist);
}

t_parselex		*parse_cmd(char *command,int i, t_lexem *list, t_lexem *tmp)
{
	t_parselex	*list2;
	char		**tableau;
	t_lexem		*tmp2;

	tableau = ft_strsplitkeep(command, ";&|<>");
	tmp = (t_lexem*)malloc(sizeof(t_lexem));
	list = tmp;
	list->command = ft_strdup(tableau[0]);
	list->next = NULL;
	while (tableau[i])
	{
		tmp->next = (t_lexem*)malloc(sizeof(t_lexem));
		tmp = tmp->next;
		tmp->command = ft_strdup(tableau[i]);
		tmp->next = NULL;
		i++;
	}
	tmp2 = list;
	while (tmp)
	{
	//	printf("%s\n", tmp2->command);
		tmp->command = epur_cmd(tmp->command, 0, 0, 0);
		tmp = tmp->next;
	}
	while (tmp2)
	{
		ft_putstr(tmp2->command);
		ft_putchar('\n');
		tmp2 = tmp2->next;
	}
	list2 = parselex(list);
	return (list2);
}
