/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:57:38 by maratana          #+#    #+#             */
/*   Updated: 2026/11/23 13:21:54 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	is_flag(char *s, t_bench *bench)
{
	int		i;
	char	*flags[5];

	flags[0] = "--simple";
	flags[1] = "--medium";
	flags[2] = "--complex";
	flags[3] = "--adaptive";
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
		if (!is_valid_num(argv[i]))
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
