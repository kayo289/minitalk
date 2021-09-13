NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = ./src/server.c ./src/error.c
SRCS_CLIENT = ./src/client.c ./src/error.c

OBJS_SERVER = $(SRCS_SERVER:%.c=%.o)
OBJS_CLIENT = $(SRCS_CLIENT:%.c=%.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(MAKE) -C src/libft
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) -L. -L./src/libft $(OBJS_CLIENT) src/libft/libft.a

$(NAME_SERVER): $(OBJS_SERVER)
	$(MAKE) -C src/libft
	$(CC) $(CFLAGS) -o $(NAME_SERVER) -L. -L./src/libft $(OBJS_SERVER) src/libft/libft.a

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make clean -C src/libft

fclean: clean
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C src/libft

re: fclean all

.PHONY: all clean fclean re
