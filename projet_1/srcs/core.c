/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:23:59 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/17 22:40:34 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh.h"

void				core(t_shell *info)
{
	int		run;
	int		i;
	int		ret;
	char	*str;

	i = 0;
	run = 0;
	ret = 1;
	str = ft_strnew(ft_strlen(info->command));
	while (info->command[run])
	{
		str[i] = info->command[run];
		if (info->command[run] == ';' || (info->command[run + 1] == '\0'))
		{
			if (info->command[run] == ';')
				str[i] = '\0';
			exec_simpl_comm(info, str);
			str = ft_strnew(ft_strlen(info->command));
			i = -1;
		}
		if (info->command[run] == '|')
		{
			exec_pipe_comm(info, str, i, 0);
			str = ft_strnew(ft_strlen(info->command));
			i = -1;
		}
		i++;
		run++;
//		if (info->command[run] == '|')
//		{
//			ret = exec_pipe_comm(info, i, run);
//			i = run + 1;
//		}
	}
	free(str);
}
