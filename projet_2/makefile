# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corosteg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 13:49:12 by corosteg          #+#    #+#              #
#    Updated: 2017/10/27 20:42:39 by corosteg         ###   ########.fr        #
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
	   ./srcs/press_space.c


all: $(NAME)

$(NAME):
		@echo "\033[31m" "compiling" [ $(NAME) ]
		make -C $(LIB_PATH)
		gcc $(FLAGS) $(SRCS) $(LIB) -ltermcap -o $(NAME)
		@echo "\033[32m" "    -------- 21sh has been Created --------"

cc:
		gcc $(SRCS) $(LIB) -g -ltermcap -o $(NAME)

sanitize:
		gcc $(SRCS) $(LIB) -g3 -fsanitize=address -ltermcap -o $(NAME)

clean:
		@echo "\033[34m" "Deleting"
		make -C $(LIB_PATH) clean

fclean:
		@echo "\033[34m" "Deleting"
		/bin/rm -f $(NAME)
		make -C $(LIB_PATH) fclean

re: fclean all
