/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:46:12 by maratana          #+#    #+#             */
/*   Updated: 2026/11/24 15:43:39 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "validate.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

t_list	*init_a(char **argv)
{
	t_list	*ret;
	t_list	*new;
	int		i;
	int		*num;

	i = 0;
	ret = NULL;
	while (argv[i])
	{
		num = malloc(sizeof(int));
		if (!num)
			return (ft_lstclear(&ret, free), NULL);
		*num = myatoi(argv[i]);
		new = lstnew(num);
		if (!new)
			return (free(num), ft_lstclear(&ret, free), NULL);
		lstadd_back(&ret, new);
		i++;
	}
	return (ret);
}

static int	get_list_val(int lst_i, t_list *lst)
{
	int	i;

	i = 0;
	while (lst && lst_i != i)
	{
		lst = lst->next;
		i++;
	}
	return (*(int *)lst->content);
}

double	compute_disorder(t_list *a)
{
	float	mistakes;
	float	pairs;
	int		i;
	int		j;

	mistakes = 0;
	pairs = 0;
	i = 0;
	while (i < lstsize(a))
	{
		j = i + 1;
		while (j < lstsize(a))
		{
			pairs += 1;
			if (get_list_val(i, a) > get_list_val(j, a))
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / pairs);
}
