NAME = cub3D

SRC = $(wildcard src/*.c)
OBJS := $(SRC:%.c=%.o)

CC = cc
RM = rm -f

MLX_LIB = minilibx-linux/libmlx_Linux.a
LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -Iincludes -Imlx_linux -g

MLX_FLAGS 	= -L ./lib/mlx -L/usr/lib/X11 -lXext -lX11

all: $(MLX_LIB) $(LIBFT) $(NAME)

$(LIBFT):
	git submodule update --init --recursive
	make -C libft

$(MLX_LIB):
	git submodule update --init --recursive
	make -C minilibx-linux

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C minilibx-linux/ clean
	make -C libft/ clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re