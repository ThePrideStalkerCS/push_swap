/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:57:38 by maratana          #+#    #+#             */
/*   Updated: 2026/11/24 15:47:43 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
#include <limits.h>
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

int	is_flag(char *s, t_bench *bench)
{
	int		i;
	char	*flags[5];

	flags[0] = "--adaptive";
	flags[1] = "--simple";
	flags[2] = "--medium";
	flags[3] = "--complex";
	flags[4] = NULL;
	if (!s)
		return (0);
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

static size_t	count_tokens(char **argv, int start)
{
	size_t	count;
	int		i;
	int		j;

	count = 0;
	i = start;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (is_space(argv[i][j]))
				j++;
			if (argv[i][j])
			{
				count++;
				while (argv[i][j] && !is_space(argv[i][j]))
					j++;
			}
		}
		i++;
	}
	return (count);
}
void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
char	**normalize_args(char **argv, int start)
{
	char	**result;
	size_t	count;
	size_t	k;
	int		i;
	int		j;
	int		begin;

	count = count_tokens(argv, start);
	result = calloc(count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	k = 0;
	i = start;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (is_space(argv[i][j]))
				j++;
			if (!argv[i][j])
				break ;
			begin = j;
			while (argv[i][j] && !is_space(argv[i][j]))
				j++;
			result[k] = malloc(j - begin + 1);
			if (!result[k])
				return (free_args(result), NULL);
			ft_strlcpy(result[k], argv[i] + begin, j - begin + 1);
			k++;
		}
		i++;
	}
	return (result);
}



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

int	validate_input(char **argv, t_bench *bench)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	if (argv[i] && !mystrcmp(argv[i], "--bench"))
	{
		if (bench)
			bench->enabled = 1;
		i++;
	}
	if (is_flag(argv[i], bench))
		i++;
	args = normalize_args(argv, i);
	if (!args)
		return (0);
	if (!args[0])
		return (free_args(args), 2);
	j = 0;
	while (args[j])
	{
		if (!is_valid_num(args[j]) || !is_in_range(args[j]))
			return (free_args(args), 0);
		j++;
	}
	if (!validate_no_dupe(args))
		return (free_args(args), 0);
	free_args(args);
	return (1);
}
