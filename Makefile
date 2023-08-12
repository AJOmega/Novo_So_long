NAME = So_long

CC	= cc

FLAGS = -Wall -Wextra -Werror

SRCS = so_long.c

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