/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:19:17 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/25 19:28:49 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "utils.h"

t_list	*init_a(char **argv);
double	compute_disorder(t_list *a);
void	print_list(t_list *lst_a, t_list *lst_b);
void	simple_sort(t_bench *bench);
int		is_sorted(t_list *lst);
void	complex_sort(t_bench *bench, int size);
void	med_sort(t_bench *bench, int size);
int		create_buckets(int size);
void	top_up(t_list **lst, t_list *temp, char c, t_bench *bench);
void	organise_b(t_list **b, int start, int end, t_bench *bench);
int		*bubble(t_bench *bench, int size);
int		get_position(t_list **lst, t_list *target);
void	manage_three(t_bench *bench, int largest_index);
void	sort_three_in_a(t_bench *bench);
void	assign_target(t_bench *bench);
void	find_cost(t_bench *bench);
void	sort_five(t_bench *bench);
t_list	*t(t_list *temp_a, t_list *temp_b, t_list *smallest, t_list *target);
void	inner_work(t_bench *bench);
void	move_cheapest(t_bench *bench, t_list *cheapest);
t_list	*find_cheapest(t_bench *bench);
int		get_start(char **argv, t_bench *bench);

#endif
