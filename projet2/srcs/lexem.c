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
int				one_ofs(char *s, char *c, int nb)
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

char	*epur_cmd(char *str, int i, int nb, int odd)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * (epur_len(str, 0, 0, 0) + 1));
	while (str[i] != '\0')
	{
		if (i > 0 && str[i - 1] == '\"')
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
	return (new);
}

t_parselex		*cutting(t_parselex *tmp, char *str)
{
		tmp->cutting = (char**)malloc(sizeof(char*) * 2);
		if ((str[0] == '0' || str[0] == '1' || str[0] == '2') && str[1] == '>'
		&& str[2] == '&' && str[3] != '#')
			tmp->cutting[0] = ft_strndup(str, 4);
		else if ((str[0] == '0' || str[0] == '1' || str[0] == '2') && str[1]
		== '>' && str[2] == '&')
			tmp->cutting[0] = ft_strndup(str, 3);
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

t_parselex		*parselex(t_lexem *list, t_parselex *tmp, int i)
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
		newlist->cutting = ft_splitmulti(list->command, "#&;|<>");
	list = list->next;
	newlist->next = NULL;
	while (list)
	{
		tmp->next = (t_parselex*)malloc(sizeof(t_parselex));
		tmp = tmp->next;
		if (one_ofs(list->command, "&;|<>", 0))
			tmp = cutting(tmp, list->command);
		tmp->cutting = ft_splitmulti(list->command, "#&|;<>");
		tmp->next = NULL;
		list = list->next;
	}
	return (newlist);
}

t_parselex		*parse_cmd(char *command,int i, t_lexem *list, t_lexem *tmp)
{
	t_parselex	*list2;
	char		**tableau;

	if (command[0] == '\0')
		return (NULL);
	(tableau = ft_strsplitkeep(command, ";&|<>"));
	tmp = (t_lexem*)malloc(sizeof(t_lexem));
	list = tmp;
	list->command = ft_strdup(tableau[0]);
	list->next = NULL;
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
		tmp = tmp->next;
	}
	list2 = parselex(list, NULL, 0);
	return (list2);
}
	/*tmp = list;
	while (tmp)
	{
		ft_putstr(tmp->command);
		ft_putstr("end\n");
		tmp = tmp->next;
	}*/
