/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_turk_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:47:10 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/25 10:08:41 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	sort_five(t_bench *bench)
{
	t_list	*temp;
	t_list	*smallest;
	int		small_index;
	int		i;
	int		rotations;
	int		count;

	count = 0;
	while (count < 2)
	{
		smallest = bench->a;
		temp = bench->a;
		small_index = 0;
		i = 0;
		while (temp)
		{
			if (temp->rank < smallest->rank)
			{
				smallest = temp;
				small_index = i;
			}
			i++;
			temp = temp->next;
		}
		if (small_index <= lstsize(bench->a) / 2)
			rotations = small_index;
		else
			rotations = lstsize(bench->a) - small_index;
		while (rotations > 0)
		{
			if (small_index <= lstsize(bench->a) / 2)
			{
				rotate(&bench->a, 'a', bench);
				rotations--;
			}
			else
			{
				rev_rotate(&bench->a, 'a', bench);
				rotations--;
			}
		}
		push_b(&bench->a, &bench->b, bench);
		count++;
	}
	sort_three_in_a(bench);
	push_a(&bench->a, &bench->b, bench);
	push_a(&bench->a, &bench->b, bench);
}
