/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:47:35 by maratana          #+#    #+#             */
/*   Updated: 2026/11/16 11:32:41 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

//ra & rb maratana
void	rotate(t_list **lst, char c,t_bench *bench)
{
	t_list	*first;

	first = *lst;
	*lst = first->next;
	first->next = NULL;
	lstadd_back(lst, first);
	if (c == 'a')
	{
		write(1, "ra\n", 4);
		bench->ra++;
		bench->operations++;
	}
	else if (c == 'b')
	{
		write(1, "rb\n", 4);
		bench->rb++;
		bench->operations++;
	}
	else
		ft_printf("%s", "error! This stack doesnt exist\n");
}

//rr maratana
void	rotate_both(t_list **lst_a, t_list **lst_b,t_bench *bench)
{
	rotate(lst_a, 'a',bench);
	rotate(lst_b, 'b',bench);
	bench->rr++;
	bench->operations++;
}

//rra & rrb maratana
void	rev_rotate(t_list **lst, char c,t_bench *bench)
{
	t_list	*l;
	t_list	*prev;

	l = lstlast(*lst);
	prev = *lst;
	while (prev->next != l)
		prev = prev->next;
	prev->next = NULL;
	lstadd_front(lst, l);
	if (c == 'a')
	{
		write(1, "rra\n", 4);
		bench->rra++;
		bench->operations++;
	}
	else if (c == 'b')
	{
		write(1, "rrb\n", 4);
		bench->rrb++;
		bench->operations++;
	}
	else
		ft_printf("%s", "error! This stack doesnt exist\n");
}

//rrr maratana
void	rev_rotate_both(t_list **lst_a, t_list **lst_b, t_bench *bench)
{
	rev_rotate(lst_a, 'a',bench);
	rev_rotate(lst_b, 'b',bench);
	bench->rrr++;
	bench->operations++;
}
