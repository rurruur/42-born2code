CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L./libft -lft
SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): server.c ./libft/libft.a
	$(CC) $(CFLAGS) server.c -o $@ $(LFLAGS)

$(CLIENT): client.c ./libft/libft.a
	$(CC) $(CFLAGS) client.c -o $@ $(LFLAGS)

./libft/libft.a:
	make -C libft

clean:
	rm -f *.o ./libft/*.o

fclean: clean
	rm -f $(SERVER) $(CLIENT) ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re $(SERVER) $(CLIENT)