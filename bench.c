/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:55:16 by maratana          #+#    #+#             */
/*   Updated: 2026/11/24 14:53:37 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>

static void	printoperations(t_bench b)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(b.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(b.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(b.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(b.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(b.pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(b.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(b.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(b.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(b.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(b.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(b.rrr, 2);
}

static void	putstrategy(t_bench bench)
{
	if (bench.flag == 1)
		ft_putstr_fd("Simple / O(nⁿ)", 2);
	else if (bench.flag == 2)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (bench.flag == 3)
		ft_putstr_fd("Complex / O(n log n)", 2);
	else if (bench.flag == 0)
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (bench.disorder < 0.20)
			ft_putstr_fd("O(nⁿ)", 2);
		else if (bench.disorder < 0.50)
			ft_putstr_fd("O(n√n)", 2);
		else if (bench.disorder >= 0.50)
			ft_putstr_fd("O(n log n)", 2);
	}
	ft_putstr_fd("\n", 2);
}

void	display_bench(t_bench b)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	putfloat(b.disorder * 100, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	putstrategy(b);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(b.operations, 2);
	ft_putstr_fd("\n", 2);
	printoperations(b);
}
