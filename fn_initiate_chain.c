#include "push_swap.h"

int	normalize (t_list *p);

t_list *initiate_chain (int *myarray, int size)
{
	t_list	*first_node;
	t_list	*current;
	int		i;

	i = 0;
	first_node = ft_lstnew (&myarray[i]);
	if (!first_node)
		return (nullnfree (&first_node));
	while (size > 1)
	{
		i ++;
		current = ft_lstnew (&myarray[i]);
		if (!current)
		{
			ft_lstclear (&first_node, free);
			return (nullnfree (NULL));
		}
		ft_lstadd_back(&first_node, current);
		size --;
	}
	normalize (first_node);
	return (first_node);
}

void	ft_arr_sort(t_list	**arr, int len)
{
	int	i;
	int	j;
	int	cur;
	int	next;
	t_list	*temp;

	i = 0;
	while (i < len - 1)
	{
		
		j = 0;
		while (j + 1 <= len - 1)
		{
			cur = *(int *)arr[j]->content;
			next = *(int *)arr[j + 1]->content;
			if (cur > next)
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

void print_index(t_list **arr, int len)
{
	int	i;
	int	*pi;

	i = 0;
	while (i < len)
	{
		pi = malloc (sizeof (int));
		*pi = i;
		arr[i]->index = pi;
		i++;
	}
	return ;
}

int	normalize (t_list *p)
{
	int		len;
	int		i;
	t_list	**arr;

	len = ft_lstsize (p);
	arr = malloc (sizeof (t_list*) * len);
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
	print_index (arr, len);
	free (arr);
	return (1);
}





