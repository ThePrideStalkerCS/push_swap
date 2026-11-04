/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucketsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:16:59 by maratana          #+#    #+#             */
/*   Updated: 2026/11/04 16:55:34 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// -- BUCKETSORT --

static int create_buckets(int n)
{
	int	buckets;

	buckets = 0;
	while ((buckets + 1) * (buckets + 1) <= n)
	{
		buckets++;
	}
	printf("the lsit is spliti in %i buckets",buckets);
	return (buckets);
}
static int	find_min(t_list *lst)
{
	int	val;

	val = *(int *)lst->content;
	lst = lst->next;
	while (lst)
	{
		if (val > *(int *)lst->content)
		{
			val = *(int *)lst->content;
		}
		lst = lst->next;
	}
	return (val);
}

static int	find_max(t_list *lst)
{
	int	val;

	val = *(int *)lst->content;
	lst = lst->next;
	while (lst)
	{
		if (val < *(int *)lst->content)
		{
			val = *(int *)lst->content;
		}
		lst = lst->next;
	}
	return (val);
}

// static int getbucket(int val,int total_buckets)
// {
// 	int bucket;
// 	bucket = (val - )
// 	return 
// }
void	bucket_sort(void)
{
	int n=25;
	int buckets = findbukcets(n);

}

// #include <stdio.h>

// int	main(int argc, char** argv)
// {
// 	t_list *a=init_a(argc,argv,"--adaptive");
	
// }