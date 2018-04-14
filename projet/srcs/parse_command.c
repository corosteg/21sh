/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:36:00 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/14 19:08:41 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		check_false(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return
		(ft_print("\n21sh: syntax error near unexpected token 'newline'\n"));
	if (str[i] == ';')
		return (ft_print("\n21sh: syntax error near unexpected token ';'\n"));
	if (str[i] == '|')
		return (ft_print("\n21sh: syntax error near unexpected token '|'\n"));
	if (str[i] == '>' && str[i + 1] == '>')
		return (ft_print("\n21sh: syntax error near unexpected token '>'\n"));
	if (str[i] == '<')
		return (ft_print("\n21sh: syntax error near unexpected token '<'\n"));
	return (0);
}

static int		check_false2(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return
		(ft_print("\n21sh: syntax error near unexpected token 'newline'\n"));
	if (str[i] == ';')
		return (ft_print("\n21sh: syntax error near unexpected token ';'\n"));
	if (str[i] == '&')
		return (ft_print("\n21sh: syntax error near unexpected token '&'\n"));
	if (str[i] == '<')
		return (ft_print("\n21sh: syntax error near unexpected token '<'\n"));
	return (0);
}

int				white_line(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	else if (str[i] == '|')
		return (ft_print("\n21sh: syntax error near unexpected token '|'\n"));
	else if (str[i] == '&')
		return (ft_print("\n21sh: syntax error near unexpected token '&'\n"));
	else if (str[i] == ';')
		return (ft_print("\n21sh: syntax error near unexpected token ';'\n"));
	else if (str[i] == '<')
		return (ft_print("\n21sh: syntax error near unexpected token '<'\n"));
	else if (str[i] == '>')
		return (ft_print("\n21sh: syntax error near unexpected token '>'\n"));
	else
		return (0);
}

int				parse2(char *str, int i)
{
	while (str[i])
	{
		if (str[i + 1] == '\0' && str[i] == ';')
			str[i] = '\0';
		if (str[i] == '#')
			return
			(ft_print("21sh: syntax error near unexpected token '#'\n"));
i//		if ((str[i] == '\"') && (str[i + 1] != ' ' || str[i + 1] != '\0'))
//			return
//			(ft_print("\n21sh: syntax error near unexpected token '\"'\n"));
//		if (str[i] == '\'' && (str[i + 1] != ' ' || str[i + 1] != '\0' || str[i+]))
//			return
//			(ft_print("\n21sh: syntax error near unexpected token '\''\n"));
		i++;
	}
	return (white_line(str, 0));
}

int				parse_command(char *str)
{
	int		i;

	i = 0;
	if (parse2(str, 0))
		return (0);
	while (str[i])
	{
		if (str[i] == '&')
			if (check_false(str, (i + 1)))
				return (0);
		if (str[i] == '>')
			if (check_false(str, (i + 1)))
				return (0);
		if (str[i] == '|')
			if (check_false2(str, (i + 1)))
				return (0);
		i++;
	}
	return (1);
}
