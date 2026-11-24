/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:57:38 by maratana          #+#    #+#             */
/*   Updated: 2026/11/24 15:05:56 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
#include <limits.h>

int	is_flag(char *s, t_bench *bench)
{
	int		i;
	char	*flags[5];

	flags[0] = "--adaptive";
	flags[1] = "--simple";
	flags[2] = "--medium";
	flags[3] = "--complex";
	flags[4] = NULL;
	i = 0;
	while (flags[i])
	{
		if (!mystrcmp(flags[i], s))
		{
			if (bench)
				bench->flag = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	validate_no_dupe(char **argv)
{
	int	val;
	int	i;
	int	j;

	i = 1;
	if (!mystrcmp(argv[i], "--bench"))
		i++;
	if (is_flag(argv[i], NULL))
		i++;
	while (argv[i])
	{
		val = myatoi(argv[i]);
		j = 1;
		while (argv[i + j])
		{
			if (val == myatoi(argv[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_valid_num(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!is_num(str[i]))
		return (0);
	while (is_num(str[i]))
		i++;
	return (str[i] == '\0');
}

static int	is_overflow(long num, int digit, int sign)
{
	if (sign == 1 && num > (INT_MAX - digit) / 10)
		return (1);
	if (sign == -1 && num > (-(long)INT_MIN - digit) / 10)
		return (1);
	return (0);
}
static int	is_in_range(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (is_num(str[i]))
	{
		if (is_overflow(num, str[i] - '0', sign))
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	return (1);
}

int	validate_input(char **argv, t_bench *bench)
{
	int	i;
	int	has_num;

	has_num = 0;
	i = 1;
	if (!mystrcmp(argv[i], "--bench"))
	{
		bench->enabled = 1;
		i++;
	}
	if (is_flag(argv[i], bench))
		i++;
	while (argv[i])
	{
		if (!is_valid_num(argv[i]) || !is_in_range(argv[i]))
			return (0);
		else
			has_num = 1;
		i++;
	}
	if (!has_num)
		return (2);
	if (!validate_no_dupe(argv))
		return (0);
	return (1);
}
