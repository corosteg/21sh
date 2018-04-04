#include "projet/srcs/21sh.h"
#include <string.h>

void		ft_sigstp(int i)
{
		(void)i;
		printf("signal\n");
		signal(SIGINT, SIG_IGN);
}

void		ft_sigp(int i)
{
	(void)i;
	printf("signal\n");
	signal(SIGPIPE, SIG_IGN);
}

void		ft_signal(void)
{
	signal(SIGINT, ft_sigstp);
	signal(SIGPIPE, ft_sigp);
}

int			main(int ac, char **av, char **env)
{
	char	*ta[3];
	char	*tab2[4];

	ft_signal();
	ta[0] = strdup("base64");
	ta[1] = strdup("/dev/random");
	ta[2] = NULL;

	tab2[0] = strdup("head");
	tab2[1] = strdup("-c");
	tab2[2] = strdup("1000");
	tab2[3] = NULL;

	int		fd[2];
//	int		save = dup(1);

	pipe(fd);
//	fd[0] |= FD_CLOEXEC;
//	fd[1] |= FD_CLOEXEC;
	int father = fork();
	if (father == 0)
	{
		dup2(fd[1], 1);
		if (execve("/usr/bin/base64", ta, env))
		{
			printf("execve no ok\n");
			exit(0);
		}
	}
	close(fd[1]);
	close(0);
	father = fork();
	if (father == 0)
	{
		//	dup2(save, 1);
		//	close(save);
		//fd[0] |= FD_CLOEXEC;
		dup2(fd[0], 0);
		if (execve("/usr/bin/head", tab2, env))
		{
			printf("execve2 no ok\n");
			exit(0);
		}
	}
	else
	{
		close(0);
//		close(save);
		close(fd[0]);
		wait(0);
		wait(0);
		printf("ok\n");
	}
}
