/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:46:12 by maratana          #+#    #+#             */
/*   Updated: 2026/11/24 14:55:47 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "validate.h"

t_list	*init_a(char **argv)
{
	t_list	*ret;
	t_list	*new;
	int		i;
	int		*num;

	i = 1;
	if (!mystrcmp(argv[i], "--bench"))
		i++;
	if (is_flag(argv[i], NULL))
		i++;
	num = malloc(sizeof(4));
	*num = myatoi(argv[i++]);
	ret = lstnew(num);
	while (argv[i])
	{
		if (is_flag(argv[i++], NULL))
			continue ;
		num = malloc(4);
		*num = myatoi(argv[i - 1]);
		new = lstnew(num);
		lstadd_back(&ret, new);
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
