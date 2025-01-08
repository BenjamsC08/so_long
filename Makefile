# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 14:24:07 by benjamsc          #+#    #+#              #
#    Updated: 2025/01/08 11:20:35 by benjamsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
NAME = so_long
SRCS = srcs/check_map.c srcs/check_map_utils.c srcs/colors_utils.c srcs/draw.c srcs/enemy.c srcs/errors.c srcs/frees.c srcs/free_utils.c srcs/data/get_data.c srcs/get_map.c srcs/main.c srcs/map_management.c srcs/moove.c srcs/utils.c srcs/win_management.c srcs/data/player_data.c srcs/data/map_data.c srcs/data/enemy_data.c
OBJ = $(SRCS:.c=.o)
LIB_PATH = -Lmlx_linux -Llibft -L/usr/lib
LIB_NAME = -lmlx_Linux -lft -lXext -lX11 -lm -lz 
INCLUDE_PATH = -I/usr/include -Imlx_linux -Ilibft/includes -Iincludes

all: MLX LIBFT $(NAME)

MLX:
	@cd mlx_linux >> /dev/null && make >> /dev/null && cd .. >> /dev/null

LIBFT:
	@cd libft >> /dev/null && make >> /dev/null && cd .. >> /dev/null
%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE_PATH) -O3 -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)
clean:
	rm -rf *.o ./sources/*.o libft/srcs/*.o srcs/*.o
fclean: clean
	rm -rf $(NAME) libft/libft.a
re : fclean all
