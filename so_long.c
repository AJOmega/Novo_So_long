/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:58:05 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/07 22:05:27 by jabreu-d         ###   ########.fr       */
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
	build_map(window);
	return (0);
}

void	checks_ber(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (size < 5)
	{
		write (1, "wrong number of checks_ber\n", 27);
		exit(EXIT_FAILURE);
	}
	if (!(file[size - 1] == 'r' && file[size - 2] == 'e' \
	&& file[size - 3] == 'b' && file[size - 4] == '.'))
	{
		write (1, "wrong number of checks_ber\n", 27);
		exit(EXIT_FAILURE);
	}
}

void	initial_checks(int argc, int *fd, char *argv[])
{
	if (argc != 2)
	{
		(void) write (1, "wrong number of arguments\n", 27);
		exit(EXIT_FAILURE);
	}
	checks_ber(argv[1]);
	*fd = open(argv[1], O_RDONLY);
	if (*fd <= 0)
	{
		(void) write (1, "file is missing\n", 17);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	static t_win	window;
	int				fd;

	initial_checks(argc, &fd, argv);
	window.map_ptr.map = ft_create_map(window.map_ptr.map, fd, 0);
	if (!check_map(&window))
	{
		str_arr_free(&window);
		exit(0);
	}
	close(fd);
	window_init(&window);
	setup_images(&window);
	if (!window.mlx_ptr || !window.win_ptr)
		return (1);
	build_map(&window);
	mlx_hook(window.win_ptr, 2, (1L << 0), check_keyboard, &window);
	mlx_hook(window.win_ptr, 17, 0, exit_window, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
