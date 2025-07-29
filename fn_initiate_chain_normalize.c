/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_initiate_chain_normalize.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:31:32 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/29 17:13:50 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_arr_sort(t_list	**arr, int len);
static int	print_index(t_list **arr, int len);

int	normalize(t_list *p)
{
	int		len;
	int		i;
	t_list	**arr;

	len = ft_lstsize (p);
	arr = malloc (sizeof (t_list *) * len);
	if (!arr)
		return (-1);
	i = 0;
	while (i < len)
	{
		arr[i] = p;
		i++;
		p = p->next;
	}
	ft_arr_sort (arr, len);
	if (print_index (arr, len) == -1)
		return (-1);
	free (arr);
	return (1);
}

static void	ft_arr_sort(t_list	**arr, int len)
{
	int		i;
	int		j;
	t_list	*temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j + 1 <= len - 1)
		{
			if (*(int *)arr[j]->content > *(int *)arr[j + 1]->content)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	print_index(t_list **arr, int len)
{
	int	i;
	int	*pi;

	i = 0;
	while (i < len)
	{
		pi = malloc (sizeof (int));
		if (!pi)
		{
			free (arr);
			return (-1);
		}
		*pi = i;
		arr[i]->index = pi;
		i++;
	}
	return (1);
}
