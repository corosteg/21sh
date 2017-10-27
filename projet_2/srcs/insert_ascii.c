/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:58:47 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/27 20:24:54 by corosteg         ###   ########.fr       */
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
	free(str2);
	free(tmp2);
}

int					insert_ascii(t_shell *info, char *str)
{
	int		buf;
	char	*str2;
	int		insert_len;

	insert_len = info->len;
	str2 = ft_strdup(str);
	ft_putchar(str[0]);
	info->len++;
	while (42)
	{
		buf = 0;
		if (read(0, &buf, sizeof(int)) && (buf > 32 && buf < 127))
		{
			str[0] = (char)buf;
			str[1] = '\0';
			ft_putchar(buf);
			info->len++;
			str2 = ft_strfreejoin(str2, str, 1);
		}
		else if (buf < 33 || buf > 126)
			break;
	}
	if (str2 != NULL)
		modify_string(info, str2, insert_len);
	return (check_press(buf, info));
}
