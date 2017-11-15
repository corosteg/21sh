/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_squote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:56:11 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/15 02:38:21 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				manage_squote(t_shell *info)
{
	int			buf;

	ft_print("\nsquote >");
	info->command = ft_strfreejoin(info->command, "\n", 1);
	while (42)
	{
		buf = 0;
		if (read(0, &buf, sizeof(int)))
		{
			if (check_press_quote(buf, info))
			{
				check_quotes(info);
				if (info->quote == 0)
					break ;
				ft_print("\nsquote >");
				info->command = ft_strfreejoin(info->command, "\n", 1);
			}
		}
	}
}
