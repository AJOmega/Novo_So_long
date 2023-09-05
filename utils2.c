/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:44:30 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/09/05 20:20:12 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	str_arr_free(t_win *window)
{
	int	i;

	i = 0;
	while (window->map_ptr.map[i])
	{
		free(window->map_ptr.map[i]);
		i++;
	}
	free(window->map_ptr.map);
}

int	is_invalid_char(char c)
{
	if (ft_strchr("PEC10", c))
		return (0);
	write (1, "invalid char\n", 14);
	return (1);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == (unsigned char) c)
		return ((char *) &str[i]);
	return (0);
}
