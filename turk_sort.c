/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:51:49 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/24 17:40:17 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

t_list	*find_cheapest(t_bench *bench)
{
	t_list	*cheapest;
	t_list	*temp_b;

	temp_b = bench->b;
	cheapest = bench->b;
	while (temp_b)
	{
		if (temp_b->cost < cheapest->cost)
			cheapest = temp_b;
		temp_b = temp_b->next;
	}
	return (cheapest);
}

void	move_cheapest(t_bench *bench, t_list *cheapest)
{
	int	pos_cheapest;
	int	pos_target;

	pos_cheapest = get_position(&bench->b, cheapest);
	pos_target = get_position(&bench->a, cheapest->target);
	while (cheapest != bench->b)
	{
		if (pos_cheapest <= lstsize(bench->b) / 2)
			rotate(&bench->b, 'b', bench);
		else
			rev_rotate(&bench->b, 'b', bench);
	}
	while (cheapest->target != bench->a)
	{
		if (pos_target <= lstsize(bench->a) / 2)
			rotate(&bench->a, 'a', bench);
		else
			rev_rotate(&bench->a, 'a', bench);
	}
}

t_list	*get_smallest(t_bench *bench)
{
	t_list	*temp;
	t_list	*smallest;
	int		smallest_rank;

	temp = bench->a;
	smallest = bench->a;
	smallest_rank = bench->a->rank;
	while (temp)
	{
		if (temp->rank < smallest_rank)
		{
			smallest = temp;
			smallest_rank = temp->rank;
		}
		temp = temp->next;
	}
	return (smallest);
}

void	move_smallest(t_bench *bench, t_list *smallest)
{
	int		position;
	t_list	*temp;

	temp = bench->a;
	position = 0;
	while (temp)
	{
		if (temp == smallest)
			break ;
		position++;
		temp = temp->next;
	}
	while (smallest != bench->a)
	{
		if (position <= lstsize(bench->a) / 2)
			rotate(&bench->a, 'a', bench);
		else
			rev_rotate(&bench->a, 'a', bench);
	}
}

void	complex_sort(t_bench *bench, int size)
{
	int		*heap;
	t_list	*cheapest;
	t_list	*smallest;

	heap = bubble(bench, size);
	if (heap == NULL)
		return ;
	while (lstsize(bench->a) > 3)
		push_b(&bench->a, &bench->b, bench);
	sort_three_in_a(bench);
	while (bench->b)
	{
		assign_target(bench);
		find_cost(bench);
		cheapest = find_cheapest(bench);
		move_cheapest(bench, cheapest);
		push_a(&bench->a, &bench->b, bench);
	}
	smallest = get_smallest(bench);
	move_smallest(bench, smallest);
	free(heap);
}
