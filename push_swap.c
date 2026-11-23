/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:17:14 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/23 17:33:42 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include "utils.h"
#include "validate.h"
#include <stdio.h>

//inits stack a by maratana
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
int	get_list_val(int lst_i, t_list *lst)
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

void	print_list(t_list *lst_a, t_list *lst_b)
{
	while (lst_a || lst_b)
	{
		if (lst_a)
		{
			ft_printf("%d ", *(int *)lst_a->content);
			lst_a = lst_a->next;
		}
		if (lst_b)
		{
			ft_printf("%d", *(int *)lst_b->content);
			lst_b = lst_b->next;
		}
		printf("\n");
	}
	ft_printf("_ _\n");
	ft_printf("%c %c\n", 'a', 'b');
}

int	is_sorted(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
void	simple_sort(t_list **a, t_list **b, t_bench *bench)
{
	t_list	*temp;

	while (is_sorted(a) == 0)
	{
		while (*a)
		{
			if ((*a)->next)
			{
				temp = (*a)->next;
				if (*(int *)(*a)->content > *(int *)temp->content)
					swap(a, 'a', bench);
			}
			push_b(a, b, bench);
		}
		while (*b)
		{
			if ((*b)->next)
			{
				temp = (*b)->next;
				if (*(int *)(*b)->content < *(int *)temp->content)
					swap(b, 'b', bench);
			}
			push_a(a, b, bench);
		}
	}
}
void	adaptive_sort(t_list **a, t_list **b, t_bench *bench)
{
	if (bench->disorder < 0.20)
		simple_sort(a, b, bench);
	else if (bench->disorder < 0.50)
		med_sort(a, b, lstsize(*a), bench);
	else if (bench->disorder >= 0.50)
		complex_sort(a, b, lstsize(*a), bench);
	return ;
}
void	sort(t_list **a, t_list **b, t_bench *bench)
{
	if (bench->flag == 0)
		adaptive_sort(a, b, bench);
	else if (bench->flag == 1)
		simple_sort(a, b, bench);
	else if (bench->flag == 2)
		med_sort(a, b, lstsize(*a), bench);
	else if (bench->flag == 3)
		complex_sort(a, b, lstsize(*a), bench);
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		valid;
	t_bench	bench;

	bench = (t_bench){0};
	//---- VALDATION -----
	if (argc <= 1)
		return (0);
	valid = validate_input(argv, &bench);
	if (valid == 0)
		write(2, "Error\n", 6);
	if (valid == 2 || valid == 0)
		return (0);
	//---- END VALDATION -----
	a = init_a(argv);
	b = NULL;
	bench.disorder = compute_disorder(a);
	// print_list(a, b);
	sort(&a,&b,&bench);
	// print_list(a, b);
	if (bench.enabled)
		display_bench(bench);
	lst_clear(&a);
}
