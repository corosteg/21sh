/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 09:26:16 by paoroste          #+#    #+#             */
/*   Updated: 2018/04/14 18:52:19 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*epur_cmd(char *str, int i, int nb, int odd)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * (epur_len(str, 0, 0, 0) + 1));
	while (str[i] != '\0')
	{
		if (i > 0 && (str[i - 1] == '\"' || str[i - 1] == '\''))
			odd++;
		if (IS_SPACE(str[i]) && is_even(odd) == 1)
		{
			if (is_even(odd) == 1 && str[i + 1] != '\0')
				new[nb++] = '#';
			while (IS_SPACE(str[i]) && str[i + 1] != '\0')
				i++;
		}
		new[nb++] = str[i++];
	}
	if (new[nb - 1] == ' ')
		nb--;
	new[nb] = '\0';
	free(str);
	return (new);
}

t_parselex		*cutting(t_parselex *tmp, char *str)
{
	tmp->cutting = (char**)malloc(sizeof(char*) * 2);
	if ((str[0] == '0' || str[0] == '1' || str[0] == '2') && str[1] == '>'
			&& str[2] == '&')
		tmp->cutting[0] = ft_strndup(str, 3);
	else if ((str[0] == '0' || str[0] == '1' || str[0] == '2') && str[1]
			== '>')
		tmp->cutting[0] = ft_strndup(str, 2);
	else if (str[1] == str[0])
		tmp->cutting[0] = ft_strndup(str, 2);
	else
		tmp->cutting[0] = ft_strndup(str, 1);
	tmp->cutting[1] = NULL;
	tmp->next = NULL;
	tmp->next = (t_parselex*)malloc(sizeof(t_parselex));
	tmp = tmp->next;
	return (tmp);
}

t_parselex		*parselex(t_lexem *list, t_parselex *tmp)
{
	t_parselex	*newlist;

	tmp = (t_parselex*)malloc(sizeof(t_parselex));
	newlist = tmp;
	if (list->command[0] == ';')
	{
		newlist->cutting = (char**)malloc(sizeof(char*) * 2);
		newlist->cutting[0] = ft_strdup(list->command);
		newlist->cutting[1] = NULL;
	}
	else
		newlist->cutting = tool_lex1(list->command, "#&;|<>");
	list = list->next;
	newlist->next = NULL;
	while (list)
	{
		tmp->next = (t_parselex*)malloc(sizeof(t_parselex));
		tmp = tmp->next;
		if (one_ofs(list->command, "&;|<>", 0, 0))
			tmp = cutting(tmp, list->command);
		tmp->cutting = tool_lex1(list->command, "#&|;<>");
		tmp->next = NULL;
		list = list->next;
	}
	return (newlist);
}

t_parselex		*check_heredoc(t_parselex *list, t_shell *info)
{
	t_parselex		*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->cutting[0] && !ft_strcmp(tmp->cutting[0], "<<"))
			tmp->next->cutting[0] =
				manage_heredoc(info, tmp->next->cutting[0]);
		tmp = tmp->next;
	}
	return (list);
}

t_parselex		*parse_cmd(t_shell *info, int i, t_lexem *list, t_lexem *tmp)
{
	t_parselex	*list2;
	char		**tableau;

	if (info->command[0] == '\0')
		return (NULL);
	(tableau = tool_lex2(info->command, ";&|<>"));
	tmp = (t_lexem*)malloc(sizeof(t_lexem));
	list = tmp;
	list->command = ft_strdup(tableau[0]);
	list->next = NULL;
	/*int nb = 0;
	while (tableau[nb])
	{
		printf("1st: %s\n", tableau[nb]);
		nb++;
	}*/
	while (tableau[i])
	{
		tmp->next = (t_lexem*)malloc(sizeof(t_lexem));
		tmp = tmp->next;
		tmp->command = ft_strdup(tableau[i++]);
		tmp->next = NULL;
	}
	tmp = list;
	while (tmp)
	{
		tmp->command = epur_cmd(tmp->command, 0, 0, 0);
//		ft_putstr(tmp->command);
//		ft_putchar('\n');
		tmp = tmp->next;
	}
	list2 = parselex(list, NULL);
	free_lexem(list);
	free_c_tab(tableau);
	//return (list2);
	//return (list2);
	return (check_heredoc(list2, info));
}
