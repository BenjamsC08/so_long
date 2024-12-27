CC = cc
FLAGS = -Wall -Wextra -Werror -g3
NAME = so_long
SRCS = check_map.c check_map_utils.c colors_utils.c errors.c frees.c get_data.c get_map.c main.c map_management.c draw.c win_management.c moove.c enemy.c free_utils.c
OBJ = $(SRCS:.c=.o)
LIB_PATH = -Lmlx_linux -Llibft -L/usr/lib
LIB_NAME = -lmlx_Linux -lft -lXext -lX11 -lm -lz 
INCLUDE_PATH = -I/usr/include -Imlx_linux -Ilibft/includes -Iincludes

all: MLX LIBFT $(NAME)

MLX:
	@cd mlx_linux >> /dev/null && ./configure >> /dev/null && cd .. >> /dev/null

LIBFT:
	@cd libft >> /dev/null && make >> /dev/null && cd .. >> /dev/null
%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE_PATH) -O3 -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)
clean:
	rm -rf *.o ./sources/*.o libft/srcs/*.o
fclean: clean
	rm -rf $(NAME) libft/libft.a
re : fclean all
