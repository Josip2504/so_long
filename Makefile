# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:47:19 by jsamardz          #+#    #+#              #
#    Updated: 2024/06/03 14:02:58 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
SRC = $(addprefix src/, main.c map_size.c input.c error.c parse_map.c map_path.c utils.c)
OBJ = $(SRC:.c=.o)
MLX_PATH = mlx
MLX_LIB = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = libft
LIBFT_H = -L$(LIBFT_PATH) -lft 
INCLUDES = -I$(MLX_PATH) -Iinclude -I$(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@echo "make"
	@make -C libft
	@make -C mlx
	@$(CC) $(OBJ) $(MLX_LIB) $(LIBFT_H) -o $(NAME)

clean:
	@echo "clean"
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@echo "fclean"
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
