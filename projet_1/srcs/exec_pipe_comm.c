/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_comm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 22:09:42 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/17 22:57:44 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				check_com(char c, char c2)
{
	if (c == '|')
		return (0);
	if (c == ';')
		return (0);
	if (c == '&')
		return (0);
	if (c == '>')
		return (0);
	if (c == '<')
		return (0);
	else
		return (1);
}

static void		exec(char **comm1, char **comm2, int fd, t_shell *info)
{
	pid_t		father;
	char		*str;
	int			i;

	str = ft_strdup(info->command);
	if (fd > 0)
	{
		while (check_com(info->command[i], info->command[i + 1]))
			i++;
	}
}

int				exec_pipe_comm(t_shell *info, char *str, int i, int fd)
{
	pid_t		father;
	char		**comm_tab;
	char		**comm_tab2;
	int			a;
	int			cmd_fd[2];

	str[i] = '\0';
	i++;
	comm_tab = ft_strsplit(str, ' ');
	info->command = ft_strdup(&info->command[i + 1]);
	while (check_com(info->command[i], info->command[i + 1]))
	{
		str[i] = info->command[i];
		i++;
	}
	str[i] = '\0';
	comm_tab2 = ft_strsplit(str, ' ');
	info->command = ft_strdup(&info->command[i + 1]);
	exec(comm_tab, comm_tab2, fd, info);
	return (0);
}
