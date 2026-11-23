/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:19:17 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/16 11:49:45 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "utils.h"

t_list	*init_a(char **argv);
void	print_list(t_list *lst_a, t_list *lst_b);
void	bubble_sort(t_list **a, t_list **b,t_bench *bench);
int		is_sorted(t_list **lst);
void	complex_sort(t_list **a, t_list **b, int size);
void	med_sort(t_list **a, t_list **b, int size);
int		create_buckets(int size);
void	top_up(t_list **lst, t_list *temp, char c);
void	organise_b(t_list **b, int start, int end);
int		*bubble(t_list **a, int size);
int		get_position(t_list **lst, t_list *target);
int		*fill_array(t_list **a, int size);
void	assign_rank(t_list **a, int *heap, int size);
void	manage_three(t_list **a, int largest_index);
void	sort_three_in_a(t_list **a);
void	assign_target(t_list **a, t_list **b);
void	find_cost(t_list **a, t_list **b);
t_list	*get_small(t_list *temp_a, int small_rank, t_list *smallest);
t_list	*get_target(t_list *temp_a, t_list *temp_b, t_list *target);

#endif
