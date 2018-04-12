/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:56:34 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 16:47:50 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			manage_dquote2(t_shell *info)
{
	info->quote_len = 6;
	info->len++;
	info->x = 6;
}

void				manage_dquote(t_shell *info)
{
	int			buf;

	ft_print("\ndquote >");
	info->command = ft_strfreejoin(info->command, "\n", 1);
	manage_dquote2(info);
	init_term();
	while (42)
	{
		buf = 0;
		if (read(0, &buf, sizeof(int)))
		{
			if (check_press_quote(buf, info, 0))
			{
				check_quotes(info);
				if (info->dquote == 0)
					break ;
				ft_print("\ndquote >");
				info->command = ft_strfreejoin(info->command, "\n", 1);
				info->len++;
				info->quote_len = 6;
				info->x = 6;
			}
		}
	}
	init_term2();
}
