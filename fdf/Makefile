CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L. -lmlx
NAME = fdf
GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): fdf.c libmlx.dylib $(GNL_SRCS)
	$(CC) fdf.c $(GNL_SRCS) -o $@ $(LFLAGS)

clean:
	rm -rf *.o get_next_line/*.o