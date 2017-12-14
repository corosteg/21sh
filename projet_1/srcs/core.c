/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:23:59 by corosteg          #+#    #+#             */
/*   Updated: 2017/12/14 15:49:41 by corosteg         ###   ########.fr       */
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
	while (info->command[run])
	{
		if (info->command[run] == ';' || (info->command[run + 1] == '\0'))
		{
			if (info->command[run + 1] == '\0')
				exec_simpl_comm(info, ft_strndup(info->command, (run + 1)));
			else
				exec_simpl_comm(info, ft_strndup(info->command, (run)));
			//str = ft_strnew(ft_strlen(info->command));
			info->command = ft_strdup(&info->command[run + 1]);
			run = -1;
		}
		if (run != -1 && info->command[run] && (info->command[run] == '|' ||
				info->command[run] == '>'))
		{
			exec_pipe_comm(info, info->command, i, 0);
//			str = ft_strnew(ft_strlen(info->command));
			run = -1;
		}
		run++;
//		if (info->command[run] == '|')
//		{
//			ret = exec_pipe_comm(info, i, run);
//			i = run + 1;
//		}
	}
}
