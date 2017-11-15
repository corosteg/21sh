/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:05:21 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/13 18:27:44 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/21sh.h"
#include <string.h>
#include <fcntl.h>

int main(int ac, char **av, char **env)
{
	int		cmd_fd[2];
	int		father;
	char	*cmd1[3];
	char	*cmd2[3];
	int		fd;

	cmd1[0] = strdup("/bin/ls");
	cmd1[1] = strdup("-laF");
	cmd1[2] = NULL;

	cmd2[0] = strdup("/bin/cat");
	cmd2[1] = strdup("-e");
	cmd2[2] = NULL;

	pipe (cmd_fd);
	fd = open("testing_output.txt", O_APPEND | O_RDWR, 0644);

	father = fork();
	if (father > 0)
		father = wait(NULL);
	if (father == 0)
	{
		dup2 (cmd_fd[1], 1);
		close(cmd_fd[0]);
		execve(cmd1[0], cmd1, env);
	}
	else
	{
		dup2(cmd_fd[0], 0);
		close(cmd_fd[1]);
		dup2(fd, 1);
		execve(cmd2[0], cmd2, env);
	}
}
