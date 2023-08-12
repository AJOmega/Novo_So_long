/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:58:31 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/08/12 22:49:36 by jabreu-d         ###   ########.fr       */
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
}		t_win; 

// Position struct

typedef struct s_Position
{
	int	row;
	int	col;
}	t_Position;


// Queue struct

typedef struct s_queue{
	t_Node	*array;
	int		front;
	int		rear;
	int		capacity;
	int		size;
}			t_Queue;

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

#endif