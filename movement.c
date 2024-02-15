/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:44:54 by jabreu-d          #+#    #+#             */
/*   Updated: 2024/02/14 23:18:45 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_movement(int keycode, t_win *window)
{
	int	x;
	int	y;
	int	move_possible;

	x = window->map_ptr.x_player;
	y = window->map_ptr.y_player;
	if (keycode == KEY_W)
		y--;
	if (keycode == KEY_A)
		x--;
	if (keycode == KEY_S)
		y++;
	if (keycode == KEY_D)
		x++;
	move_possible = check_movement(x, y, window);
	if (move_possible)
	{
		window->map_ptr.n_moves++;
		ft_putnbr_fd(window->map_ptr.n_moves, 1);
		write(1, "\n", 1);
		if (move_possible == 2)
			move_possible = exit_window(window);
		else
			exec_move(x, y, window);
	}
}

int	check_movement(int x, int y, t_win *window)
{
	int	size;

	size = PIXEL;
	if (window->map_ptr.n_items == 0)
	{
		mlx_destroy_image(window->mlx_ptr, window->imgs.exit_img);
		window->imgs.exit_img = mlx_xpm_file_to_image(window->mlx_ptr, \
			"./alt_exit.xpm", &size, &size);
		mlx_clear_window(window->mlx_ptr, window->win_ptr);
		insert_image('P', window->map_ptr.x_player, \
		window->map_ptr.y_player, window);
	}
	if (window->map_ptr.map[y][x] == '1')
		return (0);
	if (window->map_ptr.map[y][x] == 'E' && window->map_ptr.n_items == 0)
	{
		return (2);
	}
	else if (window->map_ptr.map[y][x] == 'E')
		return (0);
	if (window->map_ptr.map[y][x] == 'C')
	{
		window->map_ptr.n_items--;
	}
	return (1);
}

void	exec_move(int new_x, int new_y, t_win *w)
{
	w->map_ptr.map[new_y][new_x] = 'P';
	w->map_ptr.map[w->map_ptr.y_player][w->map_ptr.x_player] = '0';
	w->map_ptr.y_player = new_y;
	w->map_ptr.x_player = new_x;
}
