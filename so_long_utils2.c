/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:44:30 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/03 19:50:22 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	str_arr_free(t_win *window)
{
	int	i;

	i = 0;
	while (window->map_ptr[i])
	{
		free(window->map_ptr.map[i]);
		i++;
	}
	free(window->map_ptr.map);
}
