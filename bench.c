/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:55:16 by maratana          #+#    #+#             */
/*   Updated: 2026/11/23 13:21:44 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "utils.h"
#include <stdio.h>
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

void	display_bench(t_bench b)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	putfloat(b.disorder * 100, 2);
	write(2, "%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(b.operations, 2);
	write(2, "\n", 1);
	printf("[bench] sa: %i sb: %i ss: %i pa: %i pb: %i\n", b.sa, b.sb, b.ss,
		b.pa, b.pb);
	printf("[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n", b.ra, b.rb,
		b.rr, b.rra, b.rrb, b.rrr);
}

// int main (void)
// {
//     t_bench bench;
//     bench.disorder=0.33675;

//     display_bench(bench);
// }
