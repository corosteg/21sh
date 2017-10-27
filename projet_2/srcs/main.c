/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:37:34 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/26 18:26:39 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

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

static t_shell		*init_info(t_shell *info)
{
	info = (t_shell*)malloc(sizeof(t_shell));
	info->command = NULL;
	info->x = 6;
	info->y = 0;
	info->len = 0;
	return (info);
}

int					main(int ac, char **av, char **env)
{
	t_shell		*info;

	info = init_info(info);
	(void)av;
//	check_signal();
	ft_print("21sh>");
	init_term();
	check_entry(info);
	return (ac);
}
