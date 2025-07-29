/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_sort_functions_PII.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:31:38 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/29 18:05:42 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_silent(t_list **z)
{
	t_list	*start;

	if (!z || !*z || !(*z)->next)
		return ;
	start = *z;
	*z = (*z)-> next;
	start -> next = NULL;
	ft_lstlast(*z)-> next = start;
	return ;
}

void	double_rot(t_list **a, t_list **b)
{
	rot_silent (a);
	rot_silent(b);
	ft_printf ("rr\n");
}

void	rev_rot_silent(t_list **z)
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
}

void	double_rev_rot(t_list **a, t_list **b)
{
	rev_rot_silent (a);
	rev_rot_silent (b);
	ft_printf ("rrr\n");
}
