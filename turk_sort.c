/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:51:49 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/16 11:18:20 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

t_list	*find_cheapest(t_list **b)
{
	t_list	*cheapest;
	t_list	*temp_b;

	temp_b = *b;
	cheapest = *b;
	while (temp_b)
	{
		if (temp_b->cost < cheapest->cost)
			cheapest = temp_b;
		temp_b = temp_b->next;
	}
	return (cheapest);
}

void	move_cheapest(t_list **a, t_list **b, t_list *cheapest)
{
	int	pos_cheapest;
	int	pos_target;

	pos_cheapest = get_position(b, cheapest);
	pos_target = get_position(a, cheapest->target);
	while (cheapest != *b)
	{
		if (pos_cheapest <= lstsize(*b) / 2)
			rotate(b, 'b');
		else
			rev_rotate(b, 'b');
	}
	while (cheapest->target != *a)
	{
		if (pos_target <= lstsize(*a) / 2)
			rotate(a, 'a');
		else
			rev_rotate(a, 'a');
	}
}

t_list	*get_smallest(t_list **a)
{
	t_list	*temp;
	t_list	*smallest;
	int		smallest_rank;

	temp = *a;
	smallest = *a;
	smallest_rank = (*a)->rank;
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

void	move_smallest(t_list **a, t_list *smallest)
{
	int		position;
	t_list	*temp;

	temp = *a;
	position = 0;
	while (temp)
	{
		if (temp == smallest)
			break ;
		position++;
		temp = temp->next;
	}
	while (smallest != *a)
	{
		if (position <= lstsize(*a) / 2)
			rotate(a, 'a');
		else
			rev_rotate(a, 'a');
	}
}

void	complex_sort(t_list **a, t_list **b, int size)
{
	int		*heap;
	t_list	*cheapest;
	t_list	*smallest;

	heap = bubble(a, size);
	if (heap == NULL)
		return ;
	while (lstsize(*a) > 3)
		push_b(a, b);
	sort_three_in_a(a);
	while (*b)
	{
		assign_target(a, b);
		find_cost(a, b);
		cheapest = find_cheapest(b);
		move_cheapest(a, b, cheapest);
		push_a(a, b);
	}
	smallest = get_smallest(a);
	move_smallest(a, smallest);
	free(heap);
}
