CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L. -lmlx
NAME = so_long
SRCS = so_long.c check_map.c error.c
OBJS = $(SRCS:.c=.o)
GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libmlx.a ./libft/libft.a $(GNL_OBJS)
	$(CC) $(OBJS) $(GNL_OBJS) -o $@ $(LFLAGS)

./libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS) $(GNL_OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re