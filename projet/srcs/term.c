/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:04:11 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/10 18:37:38 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				init_term(void)
{
	const char			*name;
	struct termios		term;

	if (!(name = getenv("TERM")))
		ft_putstr("getenv\n");
	if (tgetent(NULL, name) <= 0)
		ft_putstr("tgetent\n");
	if (tcgetattr(0, &term) == -1)
		ft_putstr("tcgetattr\n");
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VEOF] = 4;
	term.c_cc[VINTR] = 2;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		ft_putstr("tcsettatr\n");
}

void				init_term2(void)
{
	const char			*name;
	struct termios		term;

	if (!(name = getenv("TERM")))
		ft_putstr("getenv\n");
	if (tgetent(NULL, name) <= 0)
		ft_putstr("tgetent\n");
	if (tcgetattr(0, &term) == -1)
		ft_putstr("tcgetattr\n");
//	term.c_lflag &= ~(ICANON);
//	term.c_lflag &= ~(ECHO);
	term.c_lflag |= (ECHO);
	term.c_lflag |= (ICANON);
	term.c_lflag &= ~(ECHOCTL);
	term.c_cc[VMIN] = 1;
	term.c_cc[VEOF] = 4;
	term.c_cc[VINTR] = 3;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		ft_putstr("tcsettatr\n");
}
