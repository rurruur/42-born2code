NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_modules.c ft_printf_modules2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): ./libft/libft.a $(OBJS)
	cp ./libft/libft.a $(NAME)
	ar rc $@ $(OBJS)

./libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS) ./libft/*.o

fclean: clean
	rm -f $(NAME) ./libft/libft.a

re: fclean all
