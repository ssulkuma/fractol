# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 13:22:21 by ssulkuma          #+#    #+#              #
#    Updated: 2022/04/11 11:07:06 by ssulkuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_FILES = main.c \
			draw.c \
			julia.c \
			mandelbrot.c \
			newton.c \
			burning_ship.c \
			complex.c \
			complex_2.c \
			key_events.c \
			mouse_events.c \
			menu.c \
			colors.c \
			reset.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
INCLUDES = -I ./minilibx -I ./libft
LIB = -L ./minilibx -lmlx -L ./libft -lft -lpthread
FLAGS = -Wall -Wextra -Werror -O3 -g
FRAMEWORK = -framework OpenGL -framework AppKit
HEADER = fractol.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER)
	make -C ./libft
	gcc $(FLAGS) -c $(SRC_FILES) $(INCLUDES)
	gcc $(FLAGS) -o $(NAME) $(OBJ_FILES) $(LIB) $(FRAMEWORK)

clean:
	make -C ./libft clean
	/bin/rm -f $(OBJ_FILES)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all
