# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 13:22:21 by ssulkuma          #+#    #+#              #
#    Updated: 2022/03/21 13:54:29 by ssulkuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_FILES = main.c events.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
HEADERS = -I ./minilibx -I ./libft
LIB = -L ./minilibx -lmlx -L ./libft -lft
FLAGS = -Wall -Wextra -Werror -fsanitize=address
FRAMEWORK = -framework OpenGL -framework AppKit
GCH = fractol.h.gch

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C ./libft
	gcc $(FLAGS) -c $(SRC_FILES) $(HEADERS)
	gcc $(FLAGS) -o $(NAME) $(OBJ_FILES) $(LIB) $(FRAMEWORK)

clean:
	make -C ./libft clean
	/bin/rm -f $(OBJ_FILES)
	/bin/rm -f $(GCH)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)
re: fclean all
