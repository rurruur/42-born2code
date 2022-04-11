CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L. -lmlx
NAME = fdf

all: $(NAME)

$(NAME): fdf.c libmlx.dylib
	$(CC) fdf.c -o $@ $(LFLAGS)
