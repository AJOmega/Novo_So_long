/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:31:12 by jabreu-d          #+#    #+#             */
/*   Updated: 2024/02/14 21:16:03 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_protect(char *str, int n)
{
	if (!n)
	{
		str = malloc(2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	return (0);
}

char	*ft_25max(int n, int i, char *str, int sign)
{
	int	max;
	int	nbr;

	nbr = n;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	max = i - 1;
	str = malloc(i + 1 * 1);
	if (!str)
		return (0);
	if (sign == 1)
		str[0] = '-';
	i = max;
	while (n > 9)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	str[i] = n + '0';
	str[max + 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	str = NULL;
	str = ft_protect(str, n);
	if (str != NULL)
		return (str);
	if (n < 0)
	{
		i = 2;
		n *= -1;
		sign = 1;
	}
	else
	{
		i = 1;
		sign = 0;
	}
	str = ft_25max(n, i, str, sign);
	return (str);
}
