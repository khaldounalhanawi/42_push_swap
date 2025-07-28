#include "push_swap.h"


int	double_action(t_list **a, t_list **b, t_list *record)
{
	if (*(int *)(*b)->index != *(int *)record->index 
		&& *(int *)record->half > 0
		&& *(int *)(*a)->index != *(int *)record->target->index
		&& *(int *)record->target->half > 0)
	{
		double_rot (a, b);
		return (1);
	}

	if (*(int *)(*b)->index != *(int *)record->index 
		&& *(int *)record->half < 0
		&& *(int *)(*a)->index != *(int *)record->target->index
		&& *(int *)record->target->half < 0)
	{
		double_rev_rot (a, b);
		return (1);
	}
	return (0);
}

int	single_action(t_list **a, t_list **b, t_list *record)
{
	if (*(int *)(*b)->index != *(int *)record->index 
		&& *(int *)record->half > 0)
		rot (b, "b");
	if (*(int *)(*b)->index != *(int *)record->index 
		&& *(int *)record->half < 0)
		rev_rot (b , "b");
	if (*(int *)(*a)->index != *(int *)record->target->index
		&& *(int *)record->target->half > 0)
		rot (a, "a");
	if (*(int *)(*a)->index != *(int *)record->target->index
		&& *(int *)record->target->half < 0)
		rev_rot (a , "a");
	return (0);
}

void	reduce_a(t_list **a, t_list **b, int size)
{
	int	midian;

	midian = size / 2;
	while (size > 3)
	{
		push (b, a, "b");
		if (*(int*)(*b)->index > midian)
			rot (b, "b");
		size --;
	}
	algo_three (a);
}

int	hit(t_list **a, t_list **b, t_list *record)
{
	if (*(int *)(*b)->index == *(int *)record->index
			&& *(int *)(*a)->index == *(int *)record->target->index)
	{
		push (a, b, "a");
		return (1);
	}
	return (0);
}
