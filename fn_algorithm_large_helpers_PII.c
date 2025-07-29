/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_algorithm_large_helpers_PII.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:30:24 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/28 16:30:27 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cal_cost(t_list *a)
{
	int	val;

	if (!a)
		return ;
	while (a)
	{
		val = *(int *)a->order + *(int *)a->target->order;
		*(int *)a->cost = val;
		a = a->next;
	}
	return ;
}

t_list	*minimum_cost(t_list *a)
{
	int		min;
	t_list	*temp;

	min = 0;
	min = *(int *)a->cost;
	temp = a;
	while (a->next)
	{
		a = a->next;
		if (*(int *)a->cost < min)
		{
			min = *(int *)a->cost;
			temp = a;
		}
	}
	if (*(int *)a->cost < min)
	{
		min = *(int *)a->cost;
		temp = a;
	}
	return (temp);
}

t_list	*find_zero(t_list *a)
{
	while (a && *(int *)a->index != 0)
		a = a->next;
	return (a);
}

void	final_organize(t_list **a)
{
	t_list	*record;

	below_correct (*a);
	record = find_zero (*a);
	while (*a != record)
	{
		if (*(int *)record->half > 0)
			rot (a, "a");
		else
			rev_rot (a, "a");
	}
	return ;
}
