NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c so_long.c init.c utils.c \
       check_map.c build_map.c utils2.c movement.c \
       exit.c floodfill.c

OBJS = $(SRCS:.c=.o)

MLX_LIB = ./minilibx-linux/libmlx.a

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(MLX_LIB) -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Iinclude -O3 -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all


r:
	make re && clear && valgrind ./so_long map2.ber
