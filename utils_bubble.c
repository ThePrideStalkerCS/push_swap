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

void	assign_rank(t_list **a, int *heap, int size)
{
	t_list	*temp;
	int		i;

	temp = *a;
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

int	*fill_array(t_list **a, int size)
{
	t_list	*temp;
	int		*heap;
	int		i;

	heap = malloc(size * sizeof(int));
	if (!heap)
		return (0);
	temp = *a;
	i = 0;
	while (temp && i < size)
	{
		heap[i] = *(int *)temp->content;
		temp = temp->next;
		i++;
	}
	return (heap);
}

void	swap_bubble(int *heap, int j)
{
	int	temporary;

	temporary = heap[j];
	heap[j] = heap[j + 1];
	heap[j + 1] = temporary;
}

int	*bubble(t_list **a, int size)
{
	int		*heap;
	int		i;
	int		j;

	heap = fill_array(a, size);
	if (!heap)
		return (0);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (heap[j] > heap[j + 1])
			{
				swap_bubble(heap, j);
			}
			j++;
		}
		i++;
	}
	assign_rank(a, heap, size);
	return (heap);
}
