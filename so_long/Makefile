CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L./minilibx_mms -lmlx -L./libft -lft
NAME = so_long
SRCS = so_long.c check_map.c error.c
OBJS = $(SRCS:.c=.o)
GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libmlx.dylib libft.a $(GNL_OBJS)
	$(CC) $(OBJS) $(GNL_OBJS) -o $@ $(LFLAGS)

libft.a:
	make -C libft
	cp ./libft/libft.a .

libmlx.dylib:
	make -C minilibx_mms
	cp ./minilibx_mms/libmlx.dylib .

clean:
	rm -f $(OBJS) $(GNL_OBJS) libft/*.o minilibx_mms/*.o

fclean:
	make clean
	rm -f $(NAME) libft.a libmlx.dylib

re:
	make fclean
	make all

.PHONY: all clean fclean re