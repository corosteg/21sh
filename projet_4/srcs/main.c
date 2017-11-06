/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:37:34 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/06 17:42:50 by corosteg         ###   ########.fr       */
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


int					main(int ac, char **av, char **env)
{
	t_shell		*info;
	t_his		*his;

//	check_signal();
	(void)av;
	init_term();
	his = NULL;
	while(42)
	{
		info = init_info_list(info);
		ft_print("21sh>");
		his = check_entry(info, his);
	}
	return (ac);
}
