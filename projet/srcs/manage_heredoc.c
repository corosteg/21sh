/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:42:48 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 17:49:41 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		need_a_break(char *s1, char *s2)
{
	int		i;

	i = ft_strlen(s1);
	while (i > 0 && s1[i - 1] != '\n')
		i--;
	if (!(ft_strcmp(&s1[i], s2)))
	{
		s1[i] = '\0';
		return (1);
	}
	return (0);
}

int				control_d(int buf, t_shell *info)
{
	if (buf != 4)
		return (0);
	ft_print("%s", info->command);
	free(info->command);
	info->command = ft_strdup(" \0");
	return (1);
}

static void		manage_heredoc2(t_shell *info)
{
	ft_print("heredoc>");
	info->quote_len = 6;
	info->len = 1;
	info->x = 6;
	free(info->command);
	info->command = ft_strdup("\n");
	init_term();
}

static int		manage_heredoc3(t_shell *info, int buf, char *end)
{
	buf = 0;
	if (read(0, &buf, sizeof(int)))
	{
		if (control_d(buf, info))
			return (1);
		if (check_press_quote(buf, info, 1))
		{
			if (need_a_break(info->command, end))
				return (1);
			ft_print("\nheredoc>");
			info->command = ft_strfreejoin(info->command, "\n", 1);
			info->len++;
			info->quote_len = 6;
			info->x = 6;
		}
	}
	return (0);
}

char			*manage_heredoc(t_shell *info, char *end)
{
	int		buf;
	int		i;

	i = 0;
	buf = 0;
	while (i < info->y)
	{
		ft_print("\n");
		i++;
	}
	manage_heredoc2(info);
	while (42)
	{
		if (manage_heredoc3(info, buf, end))
			break ;
	}
	init_term2();
	ft_print("\n");
	buf = open("/tmp/21sh_heredoc", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_putstr_fd(&info->command[1], buf);
	free(end);
	return (ft_strdup("/tmp/21sh_heredoc"));
}
