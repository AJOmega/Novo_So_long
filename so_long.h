/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:58:31 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/03 19:50:35 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"

// Sprite Size

# define PIXEL	 		64

// write xev on terminal to find keycode

			// Movement

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364	

			// Close Window

# define KEY_Q				113
# define KEY_ESC  			65307

			// Define 

# define WALL				'1'
# define PLAYER				'P'
# define EXIT				'E'
# define COLLECTIBLE		'C'
# define FLOOR				'0'

// Window struct

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	t_map	map_ptr;
	t_img	imgs;
}	t_win;
// Position struct

typedef struct s_Position
{
	int	row;
	int	col;
}	t_Position;

// Map Struct

typedef struct map
{
	char			**map;
	int				x_player;
	int				y_player;
	int				x_exit;
	int				y_exit;
	int				n_items;
	int				n_moves;
}			t_map;

// Images struct

typedef struct s_img
{
	int		size;
	void	*ply_img;
	void	*exit_img;
	void	*wall_img;
	void	*floor_img;
	void	*item_img;
}			t_img;

// Floodfill

typedef struct s_floodfill{
	char	**map;
	int		total;
	char	target;
}			t_floodfill;


//exit.c
int		exit_window(t_win *window);
void	clean_map(char **map);

//inits.c
char	**ft_create_map(char **map, int fd, int count);
void	window_init(t_win *window);

//checker.c
int		check_map(t_win	*window);
int		map_is_rectangular(t_win	*window);
int		map_is_surrounded(t_win	*window);
int		map_has_components(t_win	*window);

//utils.c
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
int		ft_strlen(char *str);
int		ft_blank_strlen(char *str);
char	*ft_strdup(const char *s);
// int		is_invalid_char(char c);
// char	*ft_strchr(const char *str, int c);

//utils2.c
void	str_arr_free(t_win *window);
//void	*ft_memset(void *s, int c, size_t n);
//void	print_number(int number, int fd);

//map_build.c
int		build_map(t_win *window);
void	insert_image(char c, int i, int j, t_win *win);
void	setup_images(t_win	*window);

//movement.c
void	start_movement(int keycode, t_win *window);
int		check_movement(int x, int y, t_win *w);
void	exec_move(int new_x, int new_y, t_win *w);

//floodfill.c
void	flood_fill(t_floodfill *f, int x, int y);
int		init_floodfill(t_win *win, char c, int n_items);
char	**create_map(t_win *win);
void	free_map(char **map, t_win *win);

//utils3.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		indchr(char *str, int c);







#endif