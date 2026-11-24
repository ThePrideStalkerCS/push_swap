/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:02:13 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/24 15:02:34 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa & sb maratana
void	swap(t_list **lst, char c, t_bench *bench)
{
	t_list	*temp;

	if (!*lst || !(*lst)->next)
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
	if (!bench->enabled && bench->operations!=0)
			write(1, "\n", 1);
	if (c == 'a')
	{
		if (!bench->enabled)
			ft_printf("sa");
		bench->sa++;
	}
	else if (c == 'b')
	{
		if (!bench->enabled)
			ft_printf("sb");
		bench->sb++;
	}
	bench->operations++;
}

//pa & pb ccascava
void	push_a(t_list **lst_a, t_list **lst_b, t_bench *bench)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*temp;

	if (!(*lst_b))
		return ;
	head_b = *lst_b;
	temp = head_b->next;
	head_a = *lst_a;
	head_b->next = head_a;
	*lst_a = head_b;
	*lst_b = temp;
	if (!bench->enabled && bench->operations!=0)
			write(1, "\n", 1);
	if (!bench->enabled)
		ft_printf("pa");
	bench->pa++;
	bench->operations++;
}

void	push_b(t_list **lst_a, t_list **lst_b, t_bench *bench)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*temp;

	if (!(*lst_a))
		return ;
	head_b = *lst_b;
	head_a = *lst_a;
	temp = head_a->next;
	head_a->next = head_b;
	*lst_b = head_a;
	*lst_a = temp;
	if (!bench->enabled && bench->operations!=0)
			write(1, "\n", 1);
	if (!bench->enabled)
		ft_printf("pb");
	bench->pb++;
	bench->operations++;
}
//ss ccascava
// void	swap_both(t_list **lst_a, t_list **lst_b, t_bench *bench)
// {
// 	swap(lst_a, 'a', bench);
// 	swap(lst_b, 'b', bench);
// 	bench->ss++;
// 	bench->operations++;
// }