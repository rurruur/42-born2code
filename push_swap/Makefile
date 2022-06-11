NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c set_info.c quick_sort.c list_modules.c hard.c check.c hard_modules.c commands.c create.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re