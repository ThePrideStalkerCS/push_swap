/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_turk_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:47:10 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/16 11:48:16 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

t_list	*get_small(t_list *temp_a, int small_rank, t_list *smallest)
{
	if (temp_a->rank < small_rank)
	{
		small_rank = temp_a->rank;
		smallest = temp_a;
	}
	return (smallest);
}

t_list	*get_target(t_list *temp_a, t_list *temp_b, t_list *target)
{
	if (temp_b->rank < temp_a->rank)
	{
		if (target == NULL || temp_a->rank < target->rank)
			target = temp_a;
	}
	return (target);
}
