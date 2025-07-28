#include "push_swap.h"

void swap(t_list **z, char *name)
{
	t_list	*first;
	t_list	*second;

	if (!z || !*z || !(*z)->next)
		return ;
	first = *z;
	second = first -> next;
	first -> next = second -> next;
	second -> next = first;
	*z = second;
	printf ("s%s\n", name);
	return ;
}

void rot(t_list **z, char *name)
{
	t_list	*start;

	if (!z || !*z || !(*z)->next)
		return ;
	start = *z;
	*z = (*z)-> next;
	start -> next = NULL;
	ft_lstlast(*z)-> next = start;
	printf ("r%s\n", name);
	return ;
}

void rot_silent(t_list **z)
{
	t_list	*start;

	if (!z || !*z || !(*z)->next)
		return ;
	start = *z;
	*z = (*z)-> next;
	start -> next = NULL;
	ft_lstlast(*z)-> next = start;
	//printf ("rotate %s\n", name);
	return ;
}

void double_rot(t_list **a, t_list **b)
{
	rot_silent (a);
	rot_silent(b);
	printf ("rr\n");
}

void rev_rot_silent(t_list **z)
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

void double_rev_rot(t_list **a, t_list **b)
{
	rev_rot_silent (a);
	rev_rot_silent (b);
	printf ("rrr\n");
}

void rev_rot(t_list **z, char *name)
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

	printf("rr%s\n", name);
}

void push(t_list **a, t_list **b, char *name)
{
	t_list *temp;

	if (!*b)
	{
		return ;
	}
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_front (a, temp);
	printf ("p%s\n", name);
}