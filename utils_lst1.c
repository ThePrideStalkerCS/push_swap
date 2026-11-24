/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:11:46 by maratana          #+#    #+#             */
/*   Updated: 2026/11/24 14:56:19 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
}

void	lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	*lst = new;
	new->next = temp;
}

int	lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list	*lstlast(t_list *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	lst_clear(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (*lst == NULL)
	{
		return ;
	}
	temp = *lst;
	while (temp)
	{
		current = temp;
		temp = temp->next;
		free((int *)current->content);
		free(current);
	}
	*lst = NULL;
}
