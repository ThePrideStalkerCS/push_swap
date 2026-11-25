/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_turk_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:47:10 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/25 12:38:02 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int	get_small_idx(t_list *temp, t_list *smallest)
{
	int	i;
	int	small_index;

	i = 0;
	small_index = 0;
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
	return (small_index);
}

void	rotate_to_top(int rotations, t_bench *bench, int small_index)
{
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
}

void	sort_five(t_bench *bench)
{
	t_list	*temp;
	t_list	*smallest;
	int		rotations;
	int		count;
	int		small_index;

	count = 0;
	while (count < 2)
	{
		smallest = bench->a;
		temp = bench->a;
		small_index = get_small_idx(temp, smallest);
		if (small_index <= lstsize(bench->a) / 2)
			rotations = small_index;
		else
			rotations = lstsize(bench->a) - small_index;
		rotate_to_top(rotations, bench, small_index);
		push_b(&bench->a, &bench->b, bench);
		count++;
	}
	sort_three_in_a(bench);
	push_a(&bench->a, &bench->b, bench);
	push_a(&bench->a, &bench->b, bench);
}

t_list	*t(t_list *temp_a, t_list *temp_b, t_list *smallest, t_list *target)
{
	while (temp_a)
	{
		if (temp_a->rank < smallest->rank)
			smallest = temp_a;
		if (temp_b->rank < temp_a->rank)
		{
			if (!target || temp_a->rank < target->rank)
				target = temp_a;
		}
		temp_a = temp_a->next;
	}
	if (target)
		return (target);
	else
		return (smallest);
}

void	inner_work(t_bench *bench)
{
	t_list	*cheapest;

	assign_target(bench);
	find_cost(bench);
	cheapest = find_cheapest(bench);
	move_cheapest(bench, cheapest);
	push_a(&bench->a, &bench->b, bench);
}
