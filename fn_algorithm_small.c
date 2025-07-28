#include "push_swap.h"

static void update_three(t_list **z, t_list **first, t_list **second, t_list **third);

void algo_two(t_list **z)
{
	t_list	*first;
	t_list	*second;

	if (!z || !*z || !(*z)->next)
		return ;
	first = *z;
	second = first -> next;
	if (*(int *)first->content > *(int *)second->content)
		swap (z, "a");
	return ;
}

void algo_three(t_list **z)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!z || !*z || !(*z)->next)
		return ;
	update_three (z, &first, &second, &third);
	while (*(int *)first->content > *(int *)second->content
		|| *(int *)second->content > *(int *)third->content
		|| *(int *)first->content > *(int *)third->content)
	{
		if (*(int *)first->content > *(int *)second->content)
			swap (z, "a");
		update_three (z, &first, &second, &third);
		if (*(int *)second->content > *(int *)third->content)
			rev_rot (z, "a");
		update_three (z, &first, &second, &third);
	}
	return ;
}

static void update_three(t_list **z, t_list **first, t_list **second, t_list **third)
{
	*first = *z;
	*second = (*first) -> next;
	*third = (*second)-> next;
}