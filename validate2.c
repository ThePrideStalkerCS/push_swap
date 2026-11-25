/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 19:30:16 by maratana          #+#    #+#             */
/*   Updated: 2026/11/25 19:53:39 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "utils.h"

static int	validate_no_dupe(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (myatoi(args[i]) == myatoi(args[j]))
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
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (is_num(str[i]))
	{
		if (is_overflow(num, str[i] - '0', sign))
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	return (1);
}

int	validate_normalized(char **args)
{
	int	i;

	if (!args[0])
		return (2);
	i = 0;
	while (args[i])
	{
		if (!is_valid_num(args[i]) || !is_in_range(args[i]))
			return (0);
		i++;
	}
	if (!validate_no_dupe(args))
		return (0);
	return (1);
}
