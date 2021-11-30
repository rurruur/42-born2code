NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_modules.c ft_printf_modules2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): ./libft/libft.a $(OBJS)
	ar x ./libft/libft.a
	ar rc $@ *.o

./libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
