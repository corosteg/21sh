/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:37:55 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/09 19:07:51 by corosteg         ###   ########.fr       */
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
# define STOP		"\033[0m"
# define VERT		"\033[32m"
# define CYAN		"\033[36m"
# define RED		"\033[31m"
# define GRAS		"\033[1m"

typedef struct			s_shell
{
	int					x;
	int					y;
	int					len;
	int					is_his;
	int					no_move_his;
	struct s_his		*his;
	char				*command;
	char				*command2;
}						t_shell;

typedef struct			s_his
{
	char				*command;
	int					first;
	int					last;
	struct s_his		*next;
	struct s_his		*prev;
}						t_his;

void					p_home(t_shell *info);
void					p_end(t_shell *info);
void					press_string(t_shell *info);
void					init_term(void);
void					p_ascii_emulation(char *str, t_shell *info);
void					p_backspace(t_shell *info, int a);
void					p_delete(t_shell *info);
void					p_right(t_shell *info);
void					p_ascii(t_shell *info, char *str, int buf);
void					p_space(t_shell *info, char *str);
void					p_s_left(t_shell *info);
void					p_s_right(t_shell *info);
void					p_s_down(t_shell *info);
void					p_s_up(t_shell *info);
int						p_left(t_shell *info);
int						check_press(int buf, t_shell *info, t_his *his);
int						insert_ascii(t_shell *info, char *str);
t_shell					*init_info_list(t_shell *info);
t_his					*p_up(t_shell *info, t_his *his);
t_his					*check_entry(t_shell *info, t_his *his);
t_his					*manage_his_list(t_his *his, t_shell *info);
t_his					*p_down(t_shell *info, t_his *his);

#endif
