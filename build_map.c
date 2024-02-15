/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:48:25 by jabreu-d          #+#    #+#             */
/*   Updated: 2024/02/14 23:32:21 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	build_map(t_win *window)
{
	int		x;
	int		y;
	char	*move_nbr;

	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			insert_image(window->map_ptr.map[y][x], x, y, window);
			x++;
		}
		y++;
	}
	insert_image('P', window->map_ptr.x_player, \
	window->map_ptr.y_player, window);
	move_nbr = ft_itoa(window->map_ptr.n_moves);
	mlx_string_put(window->mlx_ptr, window->win_ptr, 20, 
		(window->height * PIXEL + 15), 0xFFFFFF, move_nbr);
	free(move_nbr);
	return (0);
}

void	insert_image(char c, int x, int y, t_win *window)
{
	void	*img;

	img = window->imgs.floor_img;
	if (c == 'P')
		img = window->imgs.ply_img;
	else if (c == '1')
		img = window->imgs.wall_img;
	else if (c == 'C')
		img = window->imgs.item_img;
	if (c == 'E')
		img = window->imgs.exit_img;
	// if (c == 'e')
	// 	img = window->imgs.alt_exit_img;
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, \
	img, x * PIXEL, y * PIXEL);
}

void	setup_images(t_win	*window)
{
	int	size;

	window->imgs.ply_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./player.xpm", &size, &size);
	window->imgs.exit_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./exit.xpm", &size, &size);
	window->imgs.alt_exit_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./alt_exit.xpm", &size, &size);
	window->imgs.floor_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./floor.xpm", &size, &size);
	window->imgs.wall_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./wall.xpm", &size, &size);
	window->imgs.item_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./collectible.xpm", &size, &size);
	window->imgs.size = size;
}
