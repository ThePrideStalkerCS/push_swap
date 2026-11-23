/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:14:11 by maratana          #+#    #+#             */
/*   Updated: 2026/11/23 15:14:05 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_bench
{
	int				enabled;
	double			disorder;
	int				flag;
	int				operations;
	int				sa;
	int				sb;
	int				ss;
	int				pb;
	int				pa;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_bench;

// ---LIST UTILS---
typedef struct s_list
{
	void			*content;
	int				rank;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;
void				rotate(t_list **lst, char c, t_bench *bench);
void				rotate_both(t_list **lst_a, t_list **lst_b, t_bench *bench);
void				rev_rotate(t_list **lst, char c, t_bench *bench);
void				rev_rotate_both(t_list **lst_a, t_list **lst_b,
						t_bench *bench);
void				push_a(t_list **lst_a, t_list **lst_b, t_bench *bench);
void				push_b(t_list **lst_a, t_list **lst_b, t_bench *bench);
void				swap(t_list **lst, char c, t_bench *bench);
t_list				*lstlast(t_list *lst);
void				lstadd_back(t_list **lst, t_list *new);
void				lstadd_front(t_list **lst, t_list *new);
t_list				*lstnew(void *content);
int					lstsize(t_list *lst);
void				lst_clear(t_list **lst);
// --- END LIST UTILS---
int					is_num(char c);
int					is_space(char c);
int					mystrcmp(char *s1, char *s2);
int					myatoi(char *s);
void				ft_putstr_fd(char *s, int fd);
void				display_bench(t_bench b);

#endif
