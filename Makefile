# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:47:19 by jsamardz          #+#    #+#              #
#    Updated: 2024/05/29 15:03:31 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = $(addprefix src/, main.c)
OBJ = $(SRC:.c=.o)
MLX_PATH = mlx
MLX_LIB = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I$(MLX_PATH) -Iinclude

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@echo "make"
	@make -C mlx
	@$(CC) $(OBJ) $(MLX_LIB) -o $(NAME)
	
clean:
	@echo "clean"
	@rm -f $(OBJ)

fclean: clean
	@echo "fclean"
	@rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
