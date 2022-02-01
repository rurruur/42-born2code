NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c list_module.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): ./libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./libft -lft

./libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS) ./libft/*.o

fclean: clean
	rm -f $(NAME) ./libft/libft.a

re: fclean all