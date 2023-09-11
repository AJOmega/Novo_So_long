/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:44:54 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/07 20:00:57 by jabreu-d         ###   ########.fr       */
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
	if (window->map_ptr.map[y][x] == '1')
		return (0);
	if (window->map_ptr.map[y][x] == 'E')
	{
		if (window->map_ptr.n_items == 0)
			return (2);
		return (0);
	}
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
