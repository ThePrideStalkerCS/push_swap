/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_turk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:28:13 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/25 12:14:02 by ccascava         ###   ########.fr       */
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
			return (position);
		position++;
		temp = temp->next;
	}
	return (-1);
}

void	manage_three(t_bench *bench, int largest_index)
{
	t_list	*temp;

	if (largest_index == 0)
		rotate(&bench->a, 'a', bench);
	else if (largest_index == 1)
		rev_rotate(&bench->a, 'a', bench);
	temp = bench->a;
	if (*(int *)temp->content > *(int *)temp->next->content)
		swap(&bench->a, 'a', bench);
}

void	sort_three_in_a(t_bench *bench)
{
	t_list	*temp;
	int		index;
	int		largest_rank;
	int		largest_index;

	temp = bench->a;
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
	if (!is_sorted(bench->a))
		manage_three(bench, largest_index);
}

void	assign_target(t_bench *bench)
{
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*smallest;
	t_list	*target;

	temp_b = bench->b;
	while (temp_b)
	{
		temp_a = bench->a;
		smallest = bench->a;
		target = NULL;
		temp_b->target = t(temp_a, temp_b, smallest, target);
		temp_b = temp_b->next;
	}
}

void	find_cost(t_bench *bench)
{
	int		pos_target;
	int		pos_b;
	int		cost_target;
	int		cost_b;
	t_list	*temp_b;

	temp_b = bench->b;
	while (temp_b)
	{
		pos_target = get_position(&bench->a, temp_b->target);
		pos_b = get_position(&bench->b, temp_b);
		if (pos_target <= lstsize(bench->a) / 2)
			cost_target = pos_target;
		else
			cost_target = lstsize(bench->a) - pos_target;
		if (pos_b <= lstsize(bench->b) / 2)
			cost_b = pos_b;
		else
			cost_b = lstsize(bench->b) - pos_b;
		temp_b->cost = cost_target + cost_b;
		temp_b = temp_b->next;
	}
}
