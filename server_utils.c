/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:05:52 by skasmi            #+#    #+#             */
/*   Updated: 2022/04/04 23:21:40 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	w;

	w = 1;
	i = 0;
	m = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
		{
			w = w * (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		m = (m * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		exit(1);
	return (m * w);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[len])
	{
		write (1, &s[len], 1);
		len++;
	}
	return (len);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += (ft_putstr("-214748364"));
		n = 8;
	}
	if (n < 0)
	{
		len += (ft_putchar('-'));
		n = -n;
	}
	if (n > 9)
	{
		len += (ft_putnbr(n / 10));
		len += (ft_putnbr(n % 10));
	}
	else
		len += (ft_putchar(n + 48));
	return (len);
}
