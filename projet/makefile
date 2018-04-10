# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corosteg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 13:49:12 by corosteg          #+#    #+#              #
#    Updated: 2018/04/10 14:25:28 by corosteg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
LIB_PATH = ./libft/
LIB = $(LIB_PATH)libft.a
FLAGS = -Wall -Werror -Wextra
SRCS = ./srcs/main.c\
	   ./srcs/check_entry.c\
	   ./srcs/press_backspace.c\
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
	   ./srcs/exec_simpl_comm.c\
	   ./srcs/redir_left_right.c\
	   ./srcs/tools.c\
	   ./srcs/exec_pipe_comm.c\
	   ./srcs/tools2.c\
	   ./srcs/manage_all_quotes.c\
	   ./srcs/manage_dquote.c\
	   ./srcs/parse_path.c\
	   ./srcs/manage_squote.c\
	   ./srcs/exec_pipe.c\
	   ./srcs/press_alt_right_left.c\
	   ./srcs/press_alt_cvx.c\
	   ./srcs/check_funct.c\
	   ./srcs/exec.c\
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
	   ./srcs/free.c\
	   ./srcs/redirection.c\
	   ./srcs/check_builtin.c\
	   ./srcs/agregation.c\
	   ./srcs/tools3.c\
	   ./srcs/lexem2.c\
	   ./srcs/lexem.c


all: $(NAME)

$(NAME):
		@echo "\033[31m" "compiling" [ $(NAME) ]
		make -C $(LIB_PATH)
		gcc $(FLAGS) $(SRCS) $(LIB) -ltermcap -o $(NAME)
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
		@echo "\033[32m" "                                                    "

cc:
		gcc $(SRCS) $(LIB) -g3 -ltermcap -o $(NAME)
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
		@echo "\033[32m" " "


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
		@echo "\033[32m" "                                                    "
clean:
		@echo "\033[34m" "Deleting"
		make -C $(LIB_PATH) clean

fclean:
		@echo "\033[34m" "Deleting"
		/bin/rm -f $(NAME)
		make -C $(LIB_PATH) fclean

re: fclean all
