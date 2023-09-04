/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:22:22 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/03 19:18:39 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_init(t_win *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, \
	window->width * PIXELS, window->height * PIXELS, "So_Long");
}

char	**ft_create_map(char **map, int fd, int count)
{
	char	*str;

	str = get_next_line(fd);
	if (!str && count == 0)
	{
		write(1, "map is empty or invalid\n", 25);
		exit (0);
	}
	if (str)
		map = ft_create_map(map, fd, count + 1);
	if (!map && count != 0)
		map = malloc((count + 1) * (sizeof(char *)));
	map[count] = str;
	return (map);
}
