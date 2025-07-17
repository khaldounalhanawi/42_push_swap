#include "push_swap.h"

void migrate (t_list **a, t_list **b, int size);

int price_front (t_list *p, int start, int end)
{
	int	i;

	i = 0;
	while (p->next)
	{
		i++;
		if (*(int*)p->index >= start && *(int*)p->index < end)
			break;
		p = p->next;
	}
	return (i);
}

int guide (t_list **a, int start, int end)
{
	int	i;
	int	before;
	int	after;
	int	size;
	t_list	*p;

	if (!*a)
		return (-22);
	p = *a;
	i = 0;
	before = -1;
	after = -1;
	size = ft_lstsize (*a);
	while (p)
	{
		if (*p->index >= start && *p->index <= end)
		{
			if (i < size / 2 && before < 0)
					before = i;
			else if (i >= size / 2)
				after = i;
		}
		p = p->next;
		i++;
	}
	after = after - size;
	if (before >= 0 && (-1 * after) > before)
		return (before);
	else
		return (after);
}

int algorithm(t_list **mylist, int size)
{
	t_list	**a;
	t_list	**b;
	int		start;
	int		end;
	int		flag = 0;
	int		i;
	int		chunck;

	a = mylist;
	b = malloc (sizeof (t_list*));
	start = 0;
	end = 0;
	chunck = 7;
	while (*a)
	{
		i = 0;
		end += chunck;
		while (i < chunck && *a)
			{
				if (*(*a)->index >= start && *(*a)->index < end)
				{
					if (*b && *(*a)->index < *(*b)->index)
						flag = 1;
					push (b, a, "b");
					i++;
				}
				else
				{
				if (flag == 1)
				{
					double_rot (a, b);
					flag = 0;
				}
				else
				{
					rot (a, "a");
				}
				}
			}
		start += chunck;
	}
	//migrate (a, b, size);
	chain_printer (*b);
	return (0);
}

void migrate (t_list **a, t_list **b, int size)
{
	int	max;

	max = size - 1;
	while (max >= 0)
	{
		while (*(*b)->index != max && ft_lstsize (*b))
		{
			rot (b, "b");
		}
		push (a, b, "a");
		max--;
	}
	return ;
}