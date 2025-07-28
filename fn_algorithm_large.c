#include "push_swap.h"

static void run (t_list **a, t_list **b);

int algo_five(t_list **my_list, int size)
{
	t_list	**a;
	t_list	**b;

	a = malloc (sizeof (t_list*));
	b = malloc (sizeof (t_list*));
	if (!b || !a)
	{
		nullnfree (a);
		nullnfree (b);
		return (-1);
	}
	*a = *my_list;
	reduce_a (a, b, size);
	run (a, b);
	final_organize (a);
	ft_lstclear (a, free);
	free (b);
	return (1);
}

static void calculate_new (t_list **a, t_list **b)
{
	find_target (*a, *b);
	tag (*a);
	tag (*b);
	below_correct (*a);
	below_correct (*b);
	cal_cost (*b);
}

static void run (t_list **a, t_list **b)
{
	int	condition;
	t_list *record;

	condition = 0;
	while (condition == 0 && (*b))
	{
		calculate_new (a, b);
		record = minimum_cost (*b);
		while ((*b))
		{
			if (hit (a, b, record))
			{
				condition = 1;
				break ;
			}
			if (double_action (a, b, record))
				continue;
			single_action (a, b, record);
		}
		condition = 0;
	}
}
