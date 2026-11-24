/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:00:08 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/23 13:28:27 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	search_and_push(t_bench *bench, int start, int end)
{
	t_list	*temp;
	t_list	*mover;

	temp = bench->a;
	while (temp)
	{
		if (temp->rank >= start && temp->rank <= end)
		{
			mover = temp;
			top_up(&bench->a, mover, 'a', bench);
			push_b(&bench->a, &bench->b, bench);
			organise_b(&bench->b, start, end, bench);
			temp = bench->a;
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

void	clear_b(t_bench *bench)
{
	t_list	*max_b;

	while (bench->b)
	{
		max_b = find_max(&bench->b);
		top_up(&bench->b, max_b, 'b', bench);
		push_a(&bench->a, &bench->b, bench);
	}
}

void	med_sort(t_bench *bench, int size)
{
	int	*heap;
	int	number_of_buckets;
	int	bucket_len;
	int	start;
	int	end;

	heap = bubble(bench, size);
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
		search_and_push(bench, start, end);
		start += bucket_len;
		end += bucket_len;
	}
	clear_b(bench);
	free(heap);
}
