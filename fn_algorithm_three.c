#include "push_swap.h"

void algo_three(t_list **z)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!z || !*z || !(*z)->next)
		return ;
	first = *z;
	second = first -> next;
	third = second -> next;
	while (*(int *)first->content > *(int *)second->content || *(int *)second->content > *(int *)third->content || *(int *)first->content > *(int *)third->content)
	{
		if (*(int *)first->content > *(int *)second->content)
			swap (z, "a");
		first = *z;
		second = first -> next;
		third = second -> next;
		if (*(int *)second->content > *(int *)third->content)
			rev_rot (z, "a");
		first = *z;
		second = first -> next;
		third = second -> next;
	}
	return ;
}

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

void finder (t_list *a, t_list *b)
{
	t_list *smallest_a;

	smallest_a = smallest (a);
	b ->target = NULL;
	while (a->next)
	{
		if (!b->target && *(int *)b->index < *(int *)a->index)
			b->target = a;
		else if (b->target && *(int *)b->index < *(int *)a->index && *(int *)b->target->index > *(int *)a->index)
			b->target = a;
		a = a->next;
	}
	if (!b->target)
	{
		if (*(int *)b->index < *(int *)a->index)
			b->target = a;
		else if (*(int *)b->index > *(int *)a->index)
			b->target = smallest_a;
	}
	else if (b->target && *(int *)b->index < *(int *)a->index && *(int *)b->target->index > *(int *)a->index)
		b->target = a;
}

void tag (t_list *a)
{
	int	i;
	int	*assign_a;

	i = 0;
	while (a->next)
	{
		assign_a = malloc (sizeof(int));
		*assign_a = i;
		a->order = assign_a;
		i ++;
		a = a->next;
	}
	assign_a = malloc (sizeof(int));
	*assign_a = i;
	a->order = assign_a;
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
	int	*half;

	i = 0;
	len = ft_lstsize (a);

	if (len == 1)
	{
		half = malloc (sizeof (int));
		*half = 1;
		a->half = half;
	}
	while (i < len)
	{
		half = malloc (sizeof (int));
		if (i > len / 2)
		{
			*(int *)a->order = len - i;
			*half = -1;
			a->half = half;
		}
		else
		{
			*half = 1;
			a->half = half;
		}
		if (a->next)
			a = a->next;
		else
			break;
		i++;
	}
}

void cal_cost (t_list *a)
{
	int	*val;

	if (!a)
		return;
	while (a->next)
	{
		val = malloc (sizeof(int));
		*val = *(int *)a->order + *(int *)a->target->order;
		a->cost = val;
		a = a->next;
	}
	val = malloc (sizeof(int));
	*val = *(int *)a->order + *(int *)a->target->order;
	a->cost = val;
	return ;
}

t_list *minimum_cost(t_list *a)
{
	int	min;
	t_list *temp;

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

t_list *find_zero(t_list *a)
{
	while (a && *(int *)a->index != 0)
	{
		a = a->next;
	}
	return (a);
}

void final_organize (t_list **a)
{
	t_list	*record;
	
	below_correct (*a);
	record = find_zero (*a);
	while (*a != record)
	{
		if (*(int *)record->half > 0)
		{
			rot (a, "a");
		}
		else
		{
			rev_rot (a, "a");
		}
	}
	return ;
}


int algo_five(t_list **mylist, int size)
{
	t_list	**a;
	t_list	**b;
	t_list	*record;
	int	condition;

	a = mylist;
	b = malloc (sizeof (t_list*));
	if (!b)
		return (-1);
	while (size > 3)
	{
		push (b, a, "b");
		size --;
	}
	algo_three (a);
	condition = 0;
	while (condition == 0 && (*b))
	{
		int show_b = *(int*)(*b)->index; // del this
		find_target (*a, *b);
		tag (*a);
		tag (*b);
		below_correct (*a);
		below_correct (*b);
		cal_cost (*b);
		record = minimum_cost (*b);

		while ((*b))
		{
			if (*(int *)(*b)->index == *(int *)record->index
			&& *(int *)(*a)->index == *(int *)record->target->index)
			{
				push (a, b, "a");
				condition = 1;
				break ;
			}
			
			if (*(int *)(*b)->index != *(int *)record->index 
				&& *(int *)record->half > 0
				&& *(int *)(*a)->index != *(int *)record->target->index
				&& *(int *)record->target->half > 0)
			{
				double_rot (a, b);
				continue;
			}

			if (*(int *)(*b)->index != *(int *)record->index 
				&& *(int *)record->half < 0
				&& *(int *)(*a)->index != *(int *)record->target->index
				&& *(int *)record->target->half < 0)
			{
				double_rev_rot (a, b);
				continue;
			}
			// single action
			if (*(int *)(*b)->index != *(int *)record->index 
				&& *(int *)record->half > 0)
			{
				rot (b, "b");
				continue;
			}
			if (*(int *)(*b)->index != *(int *)record->index 
				&& *(int *)record->half < 0)
			{
				rev_rot (b , "b");
				continue;
			}
			if (*(int *)(*a)->index != *(int *)record->target->index
				&& *(int *)record->target->half > 0)
			{
				rot (a, "a");
				continue;
			}
			if (*(int *)(*a)->index != *(int *)record->target->index
				&& *(int *)record->target->half < 0)
			{
				rev_rot (a , "a");
				continue;
			}
		}
		condition = 0;
	}
	final_organize (a);
	free (*b);
	free (b);

	// printf ("a after find target= \n");
	// chain_printer (*a);
	// printf ("b after find target= \n");
	// chain_printer (*b);
	return (1);
}

