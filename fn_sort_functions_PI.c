/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_sort_functions_PI.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:31:38 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/29 18:03:49 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **z, char *name)
{
	t_list	*first;
	t_list	*second;

	if (!z || !*z || !(*z)->next)
		return ;
	first = *z;
	second = first -> next;
	first -> next = second -> next;
	second -> next = first;
	*z = second;
	ft_printf ("s%s\n", name);
	return ;
}

void	rot(t_list **z, char *name)
{
	t_list	*start;
	t_list	*last;

	if (!z || !*z || !(*z)->next)
		return ;
	if (ft_lstsize(*z) < 2)
		return ;
	start = *z;
	*z = (*z)->next;
	start->next = NULL;
	last = ft_lstlast(*z);
	if (!last || !last->index)
		return ;
	last->next = start;
	ft_printf("r%s\n", name);
}

void	rev_rot(t_list **z, char *name)
{
	t_list	*end;
	t_list	*before_last;

	if (!z || !*z || !(*z)->next)
		return ;
	before_last = *z;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	end = before_last->next;
	before_last->next = NULL;
	end->next = *z;
	*z = end;
	ft_printf("rr%s\n", name);
}

void	push(t_list **a, t_list **b, char *name)
{
	t_list	*temp;

	if (!*b)
	{
		return ;
	}
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_front (a, temp);
	ft_printf ("p%s\n", name);
}
