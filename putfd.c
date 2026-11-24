/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:53:03 by maratana          #+#    #+#             */
/*   Updated: 2026/11/24 14:55:21 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	long	l;
	char	c;

	l = n;
	count = 1;
	if (l < 0)
	{
		l *= -1;
		write(fd, "-", 1);
		count++;
	}
	if (l > 9)
	{
		count += ft_putnbr_fd(l / 10, fd);
		ft_putnbr_fd(l % 10, fd);
	}
	else
	{
		c = l + '0';
		write(fd, &c, 1);
	}
	return (count);
}

void	putfloat(double f, int fd)
{
	long	integer;
	long	decimal;

	integer = (long)f;
	decimal = (long)((f - integer) * 100 + 0.500001);
	if (decimal == 100)
	{
		integer++;
		decimal = 0;
	}
	ft_putnbr_fd(integer, fd);
	write(fd, ".", 1);
	if (decimal < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(decimal, fd);
}
