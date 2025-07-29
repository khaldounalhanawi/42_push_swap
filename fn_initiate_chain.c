/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_initiate_chain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:31:06 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/28 18:26:28 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*populate( t_list *first_node, int size, int *myarray);
static int		fill_half_order(t_list *first_node);
static int		fill_cost(t_list *first_node);

t_list	*initiate_chain(int *myarray, int size)
{
	t_list	*first_node;
	int		*val;
	int		i;

	i = 0;
	val = malloc (sizeof (int));
	if (!val)
		return (NULL);
	*val = myarray[i];
	first_node = ft_lstnew (val);
	if (!first_node)
		return (NULL);
	if (!populate (first_node, size, myarray))
		return (ft_lst_null_clear (&first_node));
	if (normalize (first_node) == -1)
		return (ft_lst_null_clear (&first_node));
	if (fill_half_order (first_node) == -1)
		return (ft_lst_null_clear (&first_node));
	if (fill_cost (first_node) == -1)
		return (ft_lst_null_clear (&first_node));
	return (first_node);
}

static t_list	*populate( t_list *first_node, int size, int *myarray)
{
	int		i;
	int		*val;
	t_list	*current;

	i = 0;
	while (size > 1)
	{
		i ++;
		val = malloc (sizeof (int));
		if (!val)
			return (NULL);
		*val = myarray[i];
		current = ft_lstnew (val);
		if (!current)
			return (NULL);
		ft_lstadd_back(&first_node, current);
		size --;
	}
	return (first_node);
}

static int	fill_half_order(t_list *first_node)
{
	int	*p;
	int	*o;

	while (first_node)
	{
		p = malloc (sizeof (int));
		o = malloc (sizeof (int));
		if (!p || !o)
		{
			nullnfree (p);
			nullnfree (o);
			return (-1);
		}
		*p = 0;
		*o = 0;
		first_node -> half = p;
		first_node -> order = o;
		first_node = first_node -> next;
	}
	return (1);
}

static int	fill_cost(t_list *first_node)
{
	int	*p;

	while (first_node)
	{
		p = malloc (sizeof (int));
		if (!p)
			return (-1);
		*p = 0;
		first_node -> cost = p;
		first_node = first_node -> next;
	}
	return (1);
}
