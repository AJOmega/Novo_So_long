NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror #add flags after $(CC) when testing add $(FLAGS)

SRCS = get_next_line.c so_long.c init.c utils.c \
check_map.c build_map.c utils2.c movement.c \
exit.c floodfill.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
			cc $(OBJ) -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -Iinclude -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all