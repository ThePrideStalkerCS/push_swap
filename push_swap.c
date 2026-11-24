/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:17:14 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/24 17:04:12 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include "utils.h"
#include "validate.h"
#include <stdio.h>

int	is_sorted(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp && temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	simple_sort(t_bench *bench)
{
	t_list	*temp;

	while (is_sorted(bench->a) == 0)
	{
		while (bench->a)
		{
			if (bench->a->next)
			{
				temp = bench->a->next;
				if (*(int *)bench->a->content > *(int *)temp->content)
					swap(&bench->a, 'a', bench);
			}
			push_b(&bench->a, &bench->b, bench);
		}
		while (bench->b)
		{
			if (bench->b->next)
			{
				temp = bench->b->next;
				if (*(int *)bench->b->content < *(int *)temp->content)
					swap(&bench->b, 'b', bench);
			}
			push_a(&bench->a, &bench->b, bench);
		}
	}
}

void	adaptive_sort(t_bench *bench)
{
	if (bench->disorder < 0.20)
		simple_sort(bench);
	else if (bench->disorder < 0.50)
		med_sort(bench, lstsize(bench->a));
	else
		complex_sort(bench, lstsize(bench->a));
}

void	sort(t_bench *bench)
{
	if (bench->flag == 0)
		adaptive_sort(bench);
	else if (bench->flag == 1)
		simple_sort(bench);
	else if (bench->flag == 2)
		med_sort(bench, lstsize(bench->a));
	else if (bench->flag == 3)
		complex_sort(bench, lstsize(bench->a));
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




int	main(int argc, char **argv)
{
	int		valid;
	int		start;
	char	**args;
	t_bench	bench;

	bench = (t_bench){0};
	if (argc <= 1)
		return (0);
	start = 1;
	if (!mystrcmp(argv[start], "--bench"))
	{
		bench.enabled = 1;
		start++;
	}
	if (is_flag(argv[start], &bench))
		start++;
	args = normalize_args(argv, start);
	if (!args)
		return (1);
	valid = validate_normalized(args);
	if (valid == 0)
		write(2, "Error\n", 6);
	if (valid != 1)
		return (free_args(args), 0);
	bench.a = init_a(args);
	free_args(args);
	if (!bench.a)
		return (1);
	bench.disorder = compute_disorder(bench.a);
	sort(&bench);
	// print_list(bench.a, bench.b);
	if (bench.enabled)
		display_bench(bench);
	lst_clear(&bench.a);
	return (0);
}
// print_list(bench.a, bench.b);
// simple_sort(&bench);
// med_sort(&bench,lstsize(bench.a));
// complex_sort(&bench,lstsize(bench.a));
