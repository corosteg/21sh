/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:37:55 by corosteg          #+#    #+#             */
/*   Updated: 2018/04/12 13:18:11 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include <fcntl.h>
# include <termios.h>
# include <dirent.h>
# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termcap.h>
# include "../libft/libft.h"
# include "../libft/keys.h"
# define STOP		"\033[0m"
# define VERT		"\033[32m"
# define CYAN		"\033[36m"
# define RED		"\033[31m"
# define GRAS		"\033[1m"

struct s_shell			*g_info;

typedef struct			s_env
{
	char				*var;
	struct s_env		*next;
}						t_env;

typedef struct			s_shell
{
	int					x;
	int					y;
	int					len;
	int					is_his;
	int					no_move_his;
	int					quote;
	int					dquote;
	int					quote_len;
	int					start_cp;
	int					end_cp;
	int					pipefd[2];
	int					pipefd2[2];
	int					exec_on_stdout;
	int					save_stdin;
	int					save_stdout;
	int					save_stderr;
	int					fd_out;
	int					fd_in;
	int					fd_err;
	int					exec_sign;
	int					redir;
	int					father;
	int					kill;
	int					his_int;
	int					env_int;
	int					ag;
	int					ag2;
	struct s_his		*his;
	struct s_env		*env;
	char				*cp_string;
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

typedef struct			s_path
{
	char				*path;
	struct s_path		*next;
}						t_path;

typedef struct			s_parselex
{
	char				**cutting;
	struct s_morelex	*more;
	struct s_parselex	*next;
}						t_parselex;

typedef struct			s_lexem
{
	char				*command;
	struct s_lexem		*next;
}						t_lexem;

void					p_home(t_shell *info);
void					exec_in_pipe(char **com, t_shell *info,
							t_parselex *first, int i);
int						core(t_shell *info);
void					p_end(t_shell *info);
void					press_string(t_shell *info);
void					p_quote_delete(t_shell *info);
void					init_term(void);
void					p_ascii_emulation(char *str, t_shell *info);
void					p_backspace(t_shell *info, int a);
void					p_quote_backspace(t_shell *info, int i);
void					p_heredoc_backspace(t_shell *info);
void					p_delete(t_shell *info);
void					p_right(t_shell *info);
void					p_right2(t_shell *info);
void					init_term(void);
void					init_term2(void);
int						p_left(t_shell *info);
int						p_left2(t_shell *info);
void					p_ascii(t_shell *info, char *str, int buf);
void					p_space(t_shell *info, char *str);
void					p_s_left(t_shell *info);
void					p_s_right(t_shell *info);
void					p_s_down(t_shell *info);
void					p_s_up(t_shell *info);
void					exec_redir(char **com, t_shell *info,
							int fd, t_parselex *first);
int						p_a_left(t_shell *info);
int						p_a_right(t_shell *info);
int						end_token_tool(char *str);
int						check_builtin(char **command, t_shell *info,
							int out, t_parselex *first);
void					free_c_tab(char **array);
void					manage_squote(t_shell *info);
void					manage_dquote(t_shell *info);
void					check_quotes(t_shell *info);
void					print_cpy(int buf, t_shell *info);
void					press_quote_string(t_shell *info);
void					p_quote_home(t_shell *info);
void					p_quote_space(t_shell *info, char *str);
void					p_s_quote_left(t_shell *info);
void					tool_refresh(t_shell *info);
void					p_a_c(t_shell *info);
void					p_a_v(t_shell *info);
void					exec_simpl(char **com, t_shell *info, t_parselex *first,
							char **env);
void					free_list_path_tool(t_path *list);
void					exec_pipe(t_shell *info, char *command,
							int a, char **env_tab);
void					reset_fd_tool(t_shell *info);
char					**alloc_tab(t_env *list);
char					*look_for_bin(char *co, t_path *e_path,
							DIR *rep, char *tmp);
char					*parse_flag(char *str);
char					*manage_heredoc(t_shell *info, char *end);
int						insert_quote_ascii(t_shell *info, char *str);
int						check_press(int buf, t_shell *info, t_his *his);
int						insert_ascii(t_shell *info, char *str);
int						exec_simpl_comm(t_shell *info, char *command);
int						exec_pipe_comm(t_shell *info, char *str,
							int i, int fd);
int						quote_n(t_shell *info);
int						check_copy(int buf);
int						check_press_quote(int buf, t_shell *info, int i);
int						parse_command(char *str);
int						p_a_x(t_shell *info);
int						one_ofs(char *s, char *c, int nb, int i);
int						is_even(int nb);
int						epur_len(char *str, int i, int nb, int odd);
void					ft_env(t_env *list, int out);
t_parselex				*parse_cmd(t_shell *info, int i,
							t_lexem *list, t_lexem *tmp);
t_parselex				*redir_doble(t_shell *info, t_parselex *list,
							t_parselex *first);
t_parselex				*redir_simpl(t_shell *info, t_parselex *list,
							t_parselex *first);
t_parselex				*redir_left(t_shell *info, t_parselex *list,
							t_parselex *first);
t_parselex				*redir_heredoc(t_shell *info, t_parselex *list,
							t_parselex *first);
t_parselex				*redir_left_and_right(t_shell *info,
							t_parselex *list, t_parselex *first);
t_parselex				*delete_next_token(t_parselex *list);
t_env					*copy_env(char **env, t_env *list);
t_path					*parse_path(t_env *list);
t_his					*p_up(t_shell *info, t_his *his);
t_his					*check_entry(t_shell *info, t_his *his);
t_his					*manage_his_list(t_his *his, t_shell *info);
t_his					*p_down(t_shell *info, t_his *his);
char					*findhome(t_env *env);
char					*findoldpwd(t_env *env);
int						ft_get_arg(char **command2);
t_env					*ft_unsetenv(char **command, t_env *list,
							t_shell *info);
t_env					*ft_setenv(char **command, t_env *list, t_shell *info);
t_env					*set_env(char *path, t_env *env, char *arg, int p);
t_env					*ft_cd(char *command2, t_env *env, t_shell *info);
t_env					*ft_cd_pars(char **command2, t_env *env, char *home,
							t_shell *info);
char					*home_path(char *dest, char *src);
void					ft_exit(t_parselex *first, t_shell *info);
void					ft_exit2(t_shell *info);
void					cd_error(int i, char *str, t_shell *info);
void					check_signal(void);
void					free_info(t_shell *info);
void					free_lex(t_parselex *list);
void					free_lexem(t_lexem *list);
void					check_agregation(t_parselex *list, t_shell *info);
int						ft_echo(char **command, t_env *list, int out);
char					**tool_lex1(const char *s, char *c);
char					**tool_lex2(const char *s, char *c);

#endif
