# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 00:14:46 by luevange          #+#    #+#              #
#    Updated: 2025/05/26 16:16:39 by luevange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -gdwarf-4

MLX_PATH = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx  -Imlx -Lmlx -lmlx -lX11 -lXext -lm
#-framework OpenGL -framework AppKit
SRCS = so_long.c init.c map_parser.c map_checker.c render.c player.c cleanup.c loading.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
	@echo "Compilation completed!"

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

all: $(NAME)

$(MLX_LIB):
	@make -C $(MLX_PATH)
	@echo "Using existing MiniLibX..."

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
