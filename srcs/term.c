/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:04:11 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/13 17:17:11 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				term_probleme(int i)
{
	if (i == 1)
		ft_putstr_fd("Probleme with tgetent ", 2);
	else if (i == 2)
		ft_putstr_fd("Probleme with tcgetattr ", 2);
	else if (i == 3)
		ft_putstr_fd("Probleme with tcsetattr ", 2);
	else if (i == 4)
		ft_putstr_fd("Probleme with getenv ", 2);
	ft_putstr_fd("please check the environement\n", 2);
	exit(0);
}

void				init_term(void)
{
	const char			*name;
	struct termios		term;

	if (!(name = getenv("TERM")))
		return (term_probleme(4));
	if (tgetent(NULL, name) <= 0)
		return (term_probleme(1));
	if (tcgetattr(0, &term) == -1)
		return (term_probleme(2));
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VEOF] = 4;
	term.c_cc[VINTR] = 2;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (term_probleme(3));
}

void				init_term2(void)
{
	const char			*name;
	struct termios		term;

	if (!(name = getenv("TERM")))
		return (term_probleme(4));
	if (tgetent(NULL, name) <= 0)
		return (term_probleme(1));
	if (tcgetattr(0, &term) == -1)
		return (term_probleme(2));
	term.c_lflag |= (ECHO);
	term.c_lflag |= (ICANON);
	term.c_lflag &= ~(ECHOCTL);
	term.c_cc[VMIN] = 1;
	term.c_cc[VEOF] = 4;
	term.c_cc[VINTR] = 3;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (term_probleme(3));
}
