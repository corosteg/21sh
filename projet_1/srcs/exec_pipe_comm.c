/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_comm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 22:09:42 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/24 18:37:32 by corosteg         ###   ########.fr       */
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

static int		check_pipe(char *str)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (1);
		if (str[i] == ';')
			return (2);
		i++;
	}
	return (2);
}

static char		*next_command(char *str, t_shell *info)
{
	char		*result;
	int			i;

	i = 0;
	result = ft_strnew(ft_strlen(str));
	while (str[i] && str[i] != '|' && str[i] != ';')
	{
		result[i] = str[i];
		i++;
	}
	if (str[i])
		info->command = ft_strdup(&info->command[i + 1]);
	return (result);
}

int				exec_pipe_comm(t_shell *info, char *str, int i, int fd)
{
	int			ret;
	pid_t		father;
	int			status;
	char		**comm_tab;
	char		**env_tab;
	char		*bin_path;
	char		*command;
	int			pipefd[2];
	int			pipefd2[2];
	int			a;

	a = 0;
	pipe(pipefd);
	pipe(pipefd2);
	env_tab = alloc_tab(info->env);
	pipefd2[0] = dup(0);
	pipefd2[1] = dup(1);
	while ((ret = check_pipe(info->command)))
	{
		command = next_command(info->command, info);
		comm_tab = ft_strsplit(command, ' ');
		bin_path = look_for_bin(comm_tab[0], parse_path(info->env));
		father = fork();
		if (a > 0)
		{
//			close(pipefd[0]);
			dup2(pipefd[0], 0);
			close(pipefd[1]);
		}
		if (father > 0)
			wait(NULL);
		if (father == 0)
		{
			if (ret == 1)
			{
//				close(pipefd[1]);
				dup2(pipefd[1], 1);
				close(pipefd[0]);
			}
			if (execve(bin_path, comm_tab, env_tab))
			{
				ft_print("command not found: %s\n", comm_tab[0]);
				exit(father);
			}
		}
		if (ret == 2)
		{
//			dup2(0, pipefd2[0]);
//			dup2(1, pipefd2[1]);
			close(pipefd[1]);
			close(pipefd[0]);
//			close(0);
		//	close(0);
			break ;
		}
		a++;
	}
//	printf("\n%d\n", a);
//	comm_tab = ft_strsplit(command, ' ');
	return (0);
}
/*static void		exec(char **comm1, char **comm2, int fd, t_shell *info)
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
}*/
