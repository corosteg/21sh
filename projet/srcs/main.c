/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:37:34 by corosteg          #+#    #+#             */
/*   Updated: 2018/02/13 19:02:22 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static t_shell				*init_info_list(t_shell *info, char **env)
{
	info = (t_shell*)malloc(sizeof(t_shell));
	info->command = ft_strdup("\0");
	info->command2 = ft_strdup("\0");
	info->cp_string = ft_strdup("\0");
	info->no_move_his = 0;
	info->exec_on_stdout = 0;
	info->start_cp = -1;
	info->end_cp = -1;
	info->exec_sign = 0;
	info->redir = 0;
	info->env = copy_env(env, info->env);
	info->x = 5;
	info->y = 0;
	info->quote = 0;
	info->dquote = 0;
	info->len = 0;
	info->save_stdin = dup(0);
	info->save_stdout = dup(1);
	info->save_stderr = dup(2);
	return (info);
}

static void				free_env(t_env *list)
{
	t_env		*tmp;

	while (list)
	{
		free(list->var);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

static void				free_info(t_shell *info)
{
//	free(info->command);
//	free(info->command2);
	free(info->cp_string);
	free_env(info->env);
}

void				ft_error(char *str)
{
	str = NULL;
}

void				init_term(void)
{
	const char			*name;
	struct termios		term;

	if (!(name = getenv("TERM")))
		ft_error("getenv");
	if (tgetent(NULL, name) <= 0)
		ft_error("tgetent");
	if (tcgetattr(0, &term) == -1)
		ft_error("tcgetattr");
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		ft_error("tcsetattr");
}


int					main(int ac, char **av, char **env)
{
	t_shell		*info;
	t_his		*his;
	char		**tab_env;

//	check_signal();
	(void)av;
	his = NULL;
	init_term();
	info = init_info_list(info, env);
	while(42)
	{
		ft_print(""GRAS""VERT"21sh"RED">"STOP"");
		his = check_entry(info, his);
		free(info->command);
		free(info->command2);
		tab_env = alloc_tab(info->env);
		free_info(info);
		info = init_info_list(info, tab_env);
		free_c_tab(tab_env);
	}
	return (ac);
}
