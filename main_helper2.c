/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 19:25:50 by maratana          #+#    #+#             */
/*   Updated: 2026/11/25 19:28:54 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "validate.h"

int	get_start(char **argv, t_bench *bench)
{
	int	start;

	start = 1;
	if (!mystrcmp(argv[start], "--bench"))
	{
		bench->enabled = 1;
		start++;
	}
	if (is_flag(argv[start], bench))
		start++;
	return (start);
}
