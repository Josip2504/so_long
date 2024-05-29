# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:47:19 by jsamardz          #+#    #+#              #
#    Updated: 2024/05/29 16:22:16 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = $(addprefix src/, main.c ft_maps.c)
OBJ = $(SRC:.c=.o)
MLX_PATH = mlx
MLX_LIB = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = libft
LIFT_H = -L$(LIBFT_PATH)
INCLUDES = -I$(MLX_PATH) -Iinclude -I$(LIBFT_PATH)

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
