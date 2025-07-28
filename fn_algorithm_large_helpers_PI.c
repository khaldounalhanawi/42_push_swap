#include "push_swap.h"

t_list *smallest (t_list *a)
{
	int	smallest;
	t_list *record;

	smallest = *(int *)a->index;
	record = a;
	while (a->next)
	{
		if (*(int *)a->index < smallest)
		{
			smallest = *(int *)a->index;
			record = a;
		}
		a = a->next;
	}
	if (*(int *)a->index < smallest)
	{
		smallest = *(int *)a->index;
		record = a;
	}
	return (record);
} 

void	finder (t_list *a, t_list *b)
{
	t_list *smallest_a;

	smallest_a = smallest (a);
	b ->target = NULL;
	while (a)
		{
			if (!b->target && *(int *)b->index < *(int *)a->index)
				b->target = a;
			else if (b->target
				&& *(int *)b->index < *(int *)a->index
				&& *(int *)b->target->index > *(int *)a->index)
				b->target = a;
			a = a->next;
		}
		if (!b->target)
			b->target = smallest_a;
}

void tag (t_list *a)
{
	int	i;

	i = 0;
	while (a)
	{
		*(int *)a->order = i;
		i ++;
		a = a->next;
	}
}

void find_target (t_list *a, t_list *b)
{
	while (b->next)
	{
		finder (a, b);
		b = b->next;
	}
	finder (a, b);
	return ;
}

void below_correct (t_list *a)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize (a);

	if (len == 1)
		*(int *)a->half = 1;
	while (i < len && a)
	{
		if (i > len / 2)
		{
			*(int *)a->order = len - i;
			*(int *)a->half = -1;
		}
		else
			*(int *)a->half = 1;
		a = a->next;
		i++;
	}
}
