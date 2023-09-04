/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:48:25 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/03 19:02:44 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	build_map(t_win *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->height)
	{
		j = 0;
		while (j < window->width)
		{
			insert_image(window->map_ptr.map[i][j], j, i, window);
			j++;
		}
		i++;
	}
	return (i);
}

void	insert_image(char c, int j, int i, t_win window)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win->ptr, \
		window->imgs.ply_img, i * PIXEL, j * PIXEL);
	}
	if (c == '1')
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win->ptr, \
		window->imgs.wall_img, i * PIXEL, j * PIXEL);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win->ptr, \
		window->imgs.item_img, i * PIXEL, j * PIXEL);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win->ptr, \
		window->imgs.exit_img, i * PIXEL, j * PIXEL);
	}
	if (c == '0')
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win->ptr, \
		window->imgs.floor_img, i * PIXEL, j * PIXEL);
	}
}

void	setup_images(t_win	*window)
{
	int	size;

	window->imgs.ply_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./capybara.xpm", &size, &size);
	window->imgs.exit_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./water.xpm", &size, &size);
	window->imgs.floor_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./relva.xpm", &size, &size);
	window->imgs.wall_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./pedra.xpm", &size, &size);
	window->imgs.item_img = mlx_xpm_file_to_image(window->mlx_ptr, \
	"./guarana-lata.xpm", &size, &size);
	window->imgs.size = size;
}