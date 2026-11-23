/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_med_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:20:25 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/23 13:22:22 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int	create_buckets(int size)
{
	int	buckets;

	buckets = 1;
	while ((buckets * buckets) < size)
		buckets++;
	return (buckets);
}

void	top_up(t_list **lst, t_list *temp, char c, t_bench *bench)
{
	int	position;

	position = get_position(lst, temp);
	while (temp != *lst)
	{
		if (position <= lstsize(*lst) / 2)
			rotate(lst, c, bench);
		else
			rev_rotate(lst, c, bench);
	}
}

void	organise_b(t_list **b, int start, int end, t_bench *bench)
{
	int	mid;

	mid = (start + end) / 2;
	if ((*b)->rank < mid)
		rotate(b, 'b', bench);
}
