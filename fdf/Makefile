CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L. -lmlx
NAME = fdf
OBJS = fdf.o bresenham.o mark.o
GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libmlx.dylib $(GNL_OBJS)
	$(CC) $(OBJS) $(GNL_OBJS) -o $@ $(LFLAGS)

test: test.c
	$(CC) test.c -o test -L./ -lmlx -g

clean:
	rm -rf *.o get_next_line/*.o

fclean: clean
	rm -rf $(NAME)

re:	fclean all