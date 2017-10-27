/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:28:25 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/27 20:38:03 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void			modify_string(t_shell *info, char *str2, int insert_len)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strndup(info->command, insert_len);
	tmp = ft_strfreejoin(tmp, str2, 1);
	tmp = ft_strfreejoin(tmp, &info->command[insert_len], 1);
	tmp2 = info->command;
	info->command = ft_strdup(tmp);
	free(tmp);
	free(tmp2);
}

int					p_left(t_shell *info)
{
	int		buf;
	char	str[2];
	char	*str2;
	int		i;
	int		insert_len;

	tputs(tgetstr("le", NULL), 1, ft_putchar);
	info->len--;
	str2 = NULL;
	i = 0;
	insert_len = info->len;
	while (42)
	{
		buf = 0;
		if (read(0, &buf, sizeof(int)) && (buf > 32 && buf < 127))
		{
			str[0] = (char)buf;
			str[1] = '\0';
			ft_putchar(buf);
			info->len++;
			if (str2 == NULL)
				str2 = ft_strdup(str);
			else
				str2 = ft_strfreejoin(str2, str, 1);
		}
		else if (buf == 4479771 && info->len > 0)
		{
			if (str2 != NULL)
				modify_string(info, str2, insert_len);
			tputs(tgetstr("le", NULL), 1, ft_putchar);
			info->len--;
			insert_len = info->len;
			free(str2);
			str2 = NULL;
			buf = 0;
		}
		else if ((buf < 33 || buf > 126) && (buf != 4479771) && buf != 0)
			break;
	}
	if (str2 != NULL)
	{
		modify_string(info, str2, insert_len);
		free(str2);
	}
	return (check_press(buf, info));
}
