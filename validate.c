/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:57:38 by maratana          #+#    #+#             */
/*   Updated: 2026/11/04 17:39:41 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	is_flag(char *s)
{
	int		i;
	char	*flags[6];

	flags[0] = "--simple";
	flags[1] = "--medium";
	flags[2] = "--complex";
	flags[3] = "--adaptive";
	flags[4] = "--bench";
	flags[5] = NULL;
	i = 0;
	while (flags[i])
	{
		if (!mystrcmp(flags[i], s))
			return (1);
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
	while (argv[i])
	{
		if (is_flag(argv[i]))
			i++;
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

int	validate_input(char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i] && is_flag(argv[i]))
			i++;
		if (!argv[i])
			return (1);
		j = 0;
		while (is_space(argv[i][j]))
			j++;
		if (argv[i][j] && (argv[i][j] == '+' || argv[i][j] == '-'))
			j++;
		while (argv[i][j] && is_num(argv[i][j]))
			j++;
		if (argv[i][j] || !is_num(argv[i][j - 1]))
			return (0);
		i++;
	}
	if (!validate_no_dupe(argv))
		return (0);
	return (1);
}
