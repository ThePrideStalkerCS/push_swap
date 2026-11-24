/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bubble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:30:32 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/16 12:01:58 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

static void	assign_rank(t_bench *bench, int *heap, int size)
{
	t_list	*temp;
	int		i;

	temp = bench->a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (heap[i] == *(int *)temp->content)
			{
				temp->rank = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

static int	*fill_array(t_bench *bench, int size)
{
	t_list	*temp;
	int		*heap;
	int		i;

	heap = malloc(size * sizeof(int));
	if (!heap)
		return (NULL);
	temp = bench->a;
	i = 0;
	while (temp && i < size)
	{
		heap[i] = *(int *)temp->content;
		temp = temp->next;
		i++;
	}
	return (heap);
}

static void	swap_bubble(int *heap, int j)
{
	int	temporary;

	temporary = heap[j];
	heap[j] = heap[j + 1];
	heap[j + 1] = temporary;
}

int	*bubble(t_bench *bench, int size)
{
	int		*heap;
	int		i;
	int		j;

	heap = fill_array(bench, size);
	if (!heap)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (heap[j] > heap[j + 1])
				swap_bubble(heap, j);
			j++;
		}
		i++;
	}
	assign_rank(bench, heap, size);
	return (heap);
}
