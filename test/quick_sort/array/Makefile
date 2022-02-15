NAME = quick_sort
CC = gcc
CFALGS = -Wall -Wextra -Werror
SRCS = quick_sort.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): ./libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./libft -lft

./libft/libft.a:
	make -C libft

%.o: %.c quick_sort.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) ./libft/*.o

fclean: clean
	rm -f $(NAME) ./libft/libft.a

re: fclean all