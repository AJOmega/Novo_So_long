/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:58:05 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/08/12 23:46:10 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_keyboard(int keycode, t_win *window)
{
	if (keycode == KEY_ESC)
		return (exit_window(window));
	if (keycode == KEY_W || keycode == KEY_A \
		|| keycode == KEY_S || keycode == KEY_D)
	{
		window->map_ptr.map[window->map_ptr.y_player] \
		[window->map_ptr.x_player] = 0;
		start_movement(keycode, window);
	}
	
}
