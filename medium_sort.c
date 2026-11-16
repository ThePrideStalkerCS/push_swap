/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:00:08 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/16 11:54:11 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	search_and_push(t_list **a, t_list **b, int start, int end)
{
	t_list	*temp;
	t_list	*mover;

	temp = *a;
	while (temp)
	{
		if (temp->rank >= start && temp->rank <= end)
		{
			mover = temp;
			top_up(a, mover, 'a');
			push_b(a, b);
			organise_b(b, start, end);
			temp = *a;
			continue ;
		}
		temp = temp->next;
	}
}

t_list	*find_max(t_list **b)
{
	int		max_rank;
	t_list	*temp;
	t_list	*max;

	temp = *b;
	max = temp;
	max_rank = temp->rank;
	while (temp)
	{
		if (temp->rank > max_rank)
		{
			max = temp;
			max_rank = temp->rank;
		}
		temp = temp->next;
	}
	return (max);
}

void	clear_b(t_list **a, t_list **b)
{
	t_list	*max_b;

	while (*b)
	{
		max_b = find_max(b);
		top_up(b, max_b, 'b');
		push_a(a, b);
	}
}

void	med_sort(t_list **a, t_list **b, int size)
{
	int		*heap;
	int		number_of_buckets;
	int		bucket_len;
	int		start;
	int		end;

	heap = bubble(a, size);
	if (!heap)
		return ;
	number_of_buckets = create_buckets(size);
	bucket_len = size / number_of_buckets;
	if (size % number_of_buckets != 0)
		bucket_len++;
	start = 0;
	end = bucket_len - 1;
	while (start < size - 1)
	{
		search_and_push(a, b, start, end);
		start += bucket_len;
		end += bucket_len;
	}
	clear_b(a, b);
	free(heap);
}
