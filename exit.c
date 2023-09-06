/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:13:28 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/06 20:26:35 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(t_win *window)
{
	write (1, "Closing game\n", 14);
	free_map(window->map_ptr.map, window);
	if (window->imgs.ply_img)
		mlx_destroy_image(window->mlx_ptr, window->imgs.ply_img);
	if (window->imgs.floor_img)
		mlx_destroy_image(window->mlx_ptr, window->imgs.floor_img);
	if (window->imgs.exit_img)
		mlx_destroy_image(window->mlx_ptr, window->imgs.exit_img);
	if (window->imgs.item_img)
		mlx_destroy_image(window->mlx_ptr, window->imgs.item_img);
	if (window->imgs.wall_img)
		mlx_destroy_image(window->mlx_ptr, window->imgs.wall_img);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit(EXIT_SUCCESS);
}
