NAME = 21sh

LIB_PATH = ./libft/

LIB = $(LIB_PATH)libft.a

FLAGS = -Wall -Werror -Wextra

SRCS = ./srcs/main.c\
	   ./srcs/check_entry.c\
	   ./srcs/press_backspace.c\
	   ./srcs/press_backspace2.c\
	   ./srcs/press_delete.c\
	   ./srcs/press_left.c\
	   ./srcs/press_right.c\
	   ./srcs/press_ascii.c\
	   ./srcs/insert_ascii.c\
	   ./srcs/press_space.c\
	   ./srcs/parse_command.c\
	   ./srcs/init_list.c\
	   ./srcs/manage_his_list.c\
	   ./srcs/press_up.c\
	   ./srcs/press_down.c\
	   ./srcs/press_shift_left.c\
	   ./srcs/press_shift_down.c\
	   ./srcs/press_shift_right.c\
	   ./srcs/press_shift_up.c\
	   ./srcs/press_home_or_end.c\
	   ./srcs/core.c\
	   ./srcs/core2.c\
	   ./srcs/redir_left_right.c\
	   ./srcs/tools.c\
	   ./srcs/tools2.c\
	   ./srcs/manage_all_quotes.c\
	   ./srcs/manage_dquote.c\
	   ./srcs/parse_path.c\
	   ./srcs/manage_squote.c\
	   ./srcs/press_alt_right_left.c\
	   ./srcs/press_alt_cvx.c\
	   ./srcs/check_funct.c\
	   ./srcs/exec.c\
	   ./srcs/exec_in_pipe.c\
	   ./srcs/signal.c\
	   ./srcs/manage_heredoc.c\
	   ./srcs/ft_cd.c\
	   ./srcs/ft_cd2.c\
	   ./srcs/ft_cd3.c\
	   ./srcs/ft_setenv.c\
	   ./srcs/ft_unsetenv.c\
	   ./srcs/ft_exit.c\
	   ./srcs/ft_echo.c\
	   ./srcs/ft_env.c\
	   ./srcs/copy.c\
	   ./srcs/free.c\
	   ./srcs/redirection.c\
	   ./srcs/redirection2.c\
	   ./srcs/check_builtin.c\
	   ./srcs/agregation.c\
	   ./srcs/tools3.c\
	   ./srcs/lexem2.c\
	   ./srcs/term.c\
	   ./srcs/tool_lex1.c\
	   ./srcs/tool_lex2.c\
	   ./srcs/parse_command2.c\
	   ./srcs/lexem.c

SRCO = ./main.o\
	   ./check_entry.o\
	   ./press_backspace.o\
	   ./press_backspace2.o\
	   ./press_delete.o\
	   ./press_left.o\
	   ./press_right.o\
	   ./press_ascii.o\
	   ./insert_ascii.o\
	   ./press_space.o\
	   ./parse_command.o\
	   ./init_list.o\
	   ./manage_his_list.o\
	   ./press_up.o\
	   ./press_down.o\
	   ./press_shift_left.o\
	   ./press_shift_down.o\
	   ./press_shift_right.o\
	   ./press_shift_up.o\
	   ./press_home_or_end.o\
	   ./core.o\
	   ./core2.o\
	   ./redir_left_right.o\
	   ./tools.o\
	   ./tools2.o\
	   ./manage_all_quotes.o\
	   ./manage_dquote.o\
	   ./parse_path.o\
	   ./manage_squote.o\
	   ./press_alt_right_left.o\
	   ./press_alt_cvx.o\
	   ./check_funct.o\
	   ./exec.o\
	   ./exec_in_pipe.o\
	   ./signal.o\
	   ./manage_heredoc.o\
	   ./ft_cd.o\
	   ./ft_cd2.o\
	   ./ft_cd3.o\
	   ./ft_setenv.o\
	   ./ft_unsetenv.o\
	   ./ft_exit.o\
	   ./ft_echo.o\
	   ./ft_env.o\
	   ./copy.o\
	   ./free.o\
	   ./redirection.o\
	   ./redirection2.o\
	   ./check_builtin.o\
	   ./agregation.o\
	   ./tools3.o\
	   ./lexem2.o\
	   ./term.o\
	   ./tool_lex1.o\
	   ./tool_lex2.o\
	   ./parse_command2.o\
	   ./lexem.o

all: $(NAME)

$(NAME):
		@echo "\033[31m" "compiling" [ $(NAME) ]
		make -C $(LIB_PATH)
		gcc $(FLAGS) -c $(SRCS)
		gcc $(FLAGS) $(SRCO) $(LIB) -ltermcap -o $(NAME)
		@echo "\033[32m" "       _________________________________________________________________"
		@echo "\033[32m" "    /    _____________________________________________________________    \ "
		@echo "\033[32m" "    |   |                                                             |   | "
		@echo "\033[32m" "    |   |  >_                                                         |   | "
		@echo "\033[32m" "    |   |                                                             |   | "
		@echo "\033[32m" "    |   |                                                             |   | "
		@echo "\033[32m" "    |   |                                                             |   | "
		@echo "\033[32m" "    |   |                                                             |   | "
		@echo "\033[32m" "    |   |    \033[31m           ________  ____         .__\033[32m                    |   | "
		@echo "\033[32m" "    |   |    \033[31m           \_____  \/_   |   _____|  |__\033[32m                 |   | "
		@echo "\033[32m" "    |   |    \033[31m            /  ____/ |   |  /  ___/  |  \ \033[32m               |   | "
		@echo "\033[32m" "    |   |    \033[31m           /       \ |   |  \___ \|   Y  \ \033[32m              |   | "
		@echo "\033[32m" "    |   |    \033[31m           \_______ \|___| /____  >___|  /  \033[32m             |   | "
		@echo "\033[32m" "    |   |    \033[31m                   \/           \/     \/    \033[32m            |   | "
		@echo "\033[32m" "    |   |                                                             |   | "
		@echo "\033[32m" "    |   |                                                             |   | "
		@echo "\033[32m" "    |   |                                                             |   | "
		@echo "\033[32m" "    |   |                                                             |   | "
		@echo "\033[32m" "    |   |                                                             |   | "
		@echo "\033[32m" "    |   |_____________________________________________________________|   | "
		@echo "\033[32m" "     \____________________________________________________________________/ "
		@echo "\033[32m" "                     \_______________________________________/ "
		@echo "\033[32m" "                  .---------------------------------------------. "
		@echo "\033[32m" "               _-'.... .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  ...\`-_ "
		@echo "\033[32m" "            _-'..... .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .....\`-_ "
		@echo "\033[32m" "         _-'....... .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\`__\`. .......\`-_ "
		@echo "\033[32m" "      _-'......... .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .........\`-_ "
		@echo "\033[32m" "   _-'........... .---.-. .-----------------------------. .-.---. ...........\`-_ "
		@echo "\033[32m" "  :-----------------------------------------------------------------------------: "
		@echo "\033[32m" "  \`-----------------------------------------------------------------------------' "
		@echo "\033[32m" " "
		@echo "\033[32m" " "
		@echo "\033[37m" " "


cc:
		gcc $(SRCS) $(LIB) -g3 -ltermcap -o $(NAME)
		@echo "\033[32m" "   ****   **           **"
		@echo "\033[32m" "  */// * ***          /**"
		@echo "\033[32m" " /    /*//**   ****** /**"
		@echo "\033[32m" "    ***  /**  **////  /******"
		@echo "\033[32m" "   *//   /** //*****  /**///**"
		@echo "\033[32m" "  *      /**  /////** /**  /**"
		@echo "\033[32m" " /****** **** ******  /**  /**"
		@echo "\033[32m" " ////// //// //////   //   //  "
		@echo "\033[32m" "                                                    "
		@echo "\033[37m" "                                                    "


sanitize:
		gcc $(SRCS) $(LIB) -g3 -fsanitize=address -ltermcap -o $(NAME)
		@echo "\033[32m" "   ****   **           **"
		@echo "\033[32m" "  */// * ***          /**"
		@echo "\033[32m" " /    /*//**   ****** /**"
		@echo "\033[32m" "    ***  /**  **////  /******"
		@echo "\033[32m" "   *//   /** //*****  /**///**"
		@echo "\033[32m" "  *      /**  /////** /**  /**"
		@echo "\033[32m" " /****** **** ******  /**  /**"
		@echo "\033[32m" " ////// //// //////   //   //  "
		@echo "\033[32m" "                                                    "
		@echo "\033[32m" "                                                    "
		@echo "\033[37m" "                                                    "
clean:
		@echo "\033[34m" "Deleting"
		make -C $(LIB_PATH) clean
		/bin/rm -f $(SRCO)

fclean:
		@echo "\033[34m" "Deleting"
		/bin/rm -f $(NAME)
		/bin/rm -f $(SRCO)
		make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
