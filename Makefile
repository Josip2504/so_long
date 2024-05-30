# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:47:19 by jsamardz          #+#    #+#              #
#    Updated: 2024/05/30 21:44:58 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = 
SRC = $(addprefix src/, main.c ft_maps.c utils.c game.c check_map.c)
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

fclean: clean
	@echo "fclean"
	@rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
