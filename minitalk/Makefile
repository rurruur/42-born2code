CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L./libft -lft
SERVER = server
CLIENT = client
SERVER_SRCS = server.c

all: $(SERVER) $(CLIENT)

$(SERVER): server.c ./libft/libft.a
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(CLIENT): client.c ./libft/libft.a
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

./libft/libft.a:
	make -C libft

clean:
	rm -f *.o ./libft/*.o

fclean: clean
	rm -f $(SERVER) $(CLIENT) ./libft/libft.a

re: fclean all