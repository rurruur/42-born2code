CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = ./minilibx_opengl
MLX_FLAG = -framework OpenGL -framework Appkit
LFLAGS = -L$(MLX) -lmlx $(MLX_FLAG) -L./libft -lft
NAME = so_long
SRCS = so_long.c check_map.c set_modules.c hook.c
OBJS = $(SRCS:.c=.o)
GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX)/libmlx.a ./libft/libft.a $(GNL_OBJS)
	$(CC) $(OBJS) $(GNL_OBJS) -o $@ $(LFLAGS)

./libft/libft.a:
	make -C libft

$(MLX)/libmlx.a:
	make -C $(MLX)

clean:
	rm -f $(OBJS) $(GNL_OBJS) libft/*.o $(MLX)/*.o

fclean:
	make clean
	rm -f $(NAME) ./libft/libft.a $(MLX)/libmlx.a

re:
	make fclean
	make all

.PHONY: all clean fclean re