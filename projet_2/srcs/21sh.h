/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:37:55 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/27 20:42:07 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include <termios.h>
# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termcap.h>
# include "../libft/libft.h"

typedef struct			s_shell
{
	int					x;
	int					y;
	int					len;
	char				*command;
}						t_shell;

char					*check_entry(t_shell *info);
void					init_term(void);
void					p_backspace(t_shell *info);
void					p_delete(t_shell *info);
void					p_right(t_shell *info);
void					p_ascii(t_shell *info, char *str, int buf);
int						check_press(int buf, t_shell *info);
int						insert_ascii(t_shell *info, char *str);
int						p_left(t_shell *info);
void					p_space(t_shell *info);

#endif
