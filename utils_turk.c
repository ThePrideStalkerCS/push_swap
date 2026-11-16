/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_turk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:28:13 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/16 11:50:28 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int	get_position(t_list **lst, t_list *target)
{
	int		position;
	t_list	*temp;

	temp = *lst;
	position = 0;
	while (temp)
	{
		if (temp == target)
		{
			return (position);
		}
		position++;
		temp = temp->next;
	}
	return (-1);
}

void	manage_three(t_list **a, int largest_index)
{
	t_list	*temp;

	if (largest_index == 0)
		rotate(a, 'a');
	else if (largest_index == 1)
		rev_rotate(a, 'a');
	temp = *a;
	if (*(int *)temp->content > *(int *)temp->next->content)
		swap(a, 'a');
}

void	sort_three_in_a(t_list **a)
{
	t_list	*temp;
	int		index;
	int		largest_rank;
	int		largest_index;

	temp = *a;
	largest_rank = temp->rank;
	largest_index = 0;
	temp = temp->next;
	index = 1;
	while (temp)
	{
		if (temp->rank > largest_rank)
		{
			largest_index = index;
			largest_rank = temp->rank;
		}
		index++;
		temp = temp->next;
	}
	if (!is_sorted(a))
		manage_three(a, largest_index);
}

void	assign_target(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*smallest;
	t_list	*target;
	int		smallest_rank;

	temp_b = *b;
	while (temp_b)
	{
		temp_a = *a;
		smallest = *a;
		smallest_rank = (*a)->rank;
		target = NULL;
		while (temp_a)
		{
			smallest = get_small(temp_a, smallest_rank, smallest);
			target = get_target(temp_a, temp_b, target);
			temp_a = temp_a->next;
		}
		if (target)
			temp_b->target = target;
		else
			temp_b->target = smallest;
		temp_b = temp_b->next;
	}
}

void	find_cost(t_list **a, t_list **b)
{
	int		pos_target;
	int		pos_b;
	int		cost_target;
	int		cost_b;
	t_list	*temp_b;

	temp_b = *b;
	while (temp_b)
	{
		pos_target = get_position(a, temp_b->target);
		pos_b = get_position(b, temp_b);
		if (pos_target <= lstsize(*a) / 2)
			cost_target = pos_target;
		else
			cost_target = lstsize(*a) - pos_target;
		if (pos_b <= lstsize(*b) / 2)
			cost_b = pos_b;
		else
			cost_b = lstsize(*b) - pos_b;
		temp_b->cost = cost_target + cost_b;
		temp_b = temp_b->next;
	}
}
