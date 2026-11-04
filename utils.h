/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:14:11 by maratana          #+#    #+#             */
/*   Updated: 2026/11/04 17:36:21 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// ---LIST UTILS---
typedef struct s_list
{
	void			*content;
	int				rank;
	struct s_list	*next;
}					t_list;
void	rotate(t_list **lst, char c);
void	rotate_both(t_list **lst_a, t_list **lst_b);
void	rev_rotate(t_list **lst, char c);
void	rev_rotate_both(t_list **lst_a, t_list **lst_b);
void	push_a(t_list **lst_a, t_list **lst_b);
void	push_b(t_list **lst_a, t_list **lst_b);
void	swap(t_list **lst, char c);
t_list	*lstlast(t_list *lst);
void	lstadd_back(t_list **lst, t_list *new);
t_list	*lstnew(void *content);
unsigned int	lstsize(t_list *lst);


// --- END LIST UTILS---

int	is_num(char c);
int	is_space(char c);
int	mystrcmp(char *s1, char *s2);
int	myatoi(char *s);

#endif