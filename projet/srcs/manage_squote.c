/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_squote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:56:11 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/11 19:24:08 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				manage_squote(t_shell *info)
{
	int			buf;

	ft_print("\nsquote >");
	info->command = ft_strfreejoin(info->command, "\n", 1);
	info->quote_len = 6;
	info->len++;
	info->x = 6;
	init_term();
	while (42)
	{
		buf = 0;
		if (read(0, &buf, sizeof(int)))
		{
			if (check_press_quote(buf, info, 0))
			{
				check_quotes(info);
				if (info->quote == 0)
					break ;
				ft_print("\nsquote >");
				info->command = ft_strfreejoin(info->command, "\n", 1);
				info->len++;
				info->quote_len = 6;
				info->x = 6;
			}
		}
	}
	init_term2();
}
