/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:57:38 by maratana          #+#    #+#             */
/*   Updated: 2026/11/25 20:00:38 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
#include "push_swap.h"
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

int	split_arg(char *arg, char **result, size_t *k)
{
	int	j;
	int	begin;

	j = 0;
	while (arg[j])
	{
		while (is_space(arg[j]))
			j++;
		if (!arg[j])
			break ;
		begin = j;
		while (arg[j] && !is_space(arg[j]))
			j++;
		result[*k] = malloc(j - begin + 1);
		if (!result[*k])
			return (0);
		ft_strlcpy(result[(*k)++], arg + begin, j - begin + 1);
	}
	return (1);
}

char	**normalize_args(char **argv, int start)
{
	char	**result;
	size_t	k;
	int		i;

	result = calloc(count_tokens(argv, start) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	k = 0;
	i = start;
	while (argv[i])
	{
		if (!split_arg(argv[i], result, &k))
			return (free_args(result), NULL);
		i++;
	}
	return (result);
}

// int	validate_input(char **argv, t_bench *bench)
// {
// 	int		i;
// 	int		j;
// 	char	**args;

// 	i = 1;
// 	if (argv[i] && !mystrcmp(argv[i], "--bench"))
// 	{
// 		if (bench)
// 			bench->enabled = 1;
// 		i++;
// 	}
// 	if (is_flag(argv[i], bench))
// 		i++;
// 	args = normalize_args(argv, i);
// 	if (!args)
// 		return (0);
// 	if (!args[0])
// 		return (free_args(args), 2);
// 	j = 0;
// 	while (args[j])
// 	{
// 		if (!is_valid_num(args[j]) || !is_in_range(args[j]))
// 			return (free_args(args), 0);
// 		j++;
// 	}
// 	if (!validate_no_dupe(args))
// 		return (free_args(args), 0);
// 	free_args(args);
// 	return (1);
// }
