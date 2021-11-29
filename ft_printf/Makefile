NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) ./libft/libft.a
	ar rcsT $@ $^

./libft/libft.a:
	make -C libft

bonus: $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
