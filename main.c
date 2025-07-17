#include "push_swap.h"

int	*fn_intArr(char **p, int size);

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

static int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	char	**myarray;
	t_list	*my_list;
	int		*intArray;

	myarray = filter(argc, argv);
	if (!myarray)
		ft_exit (NULL);
	intArray = fn_intArr (myarray, arr_size(myarray));
	my_list = initiate_chain (intArray, arr_size(myarray));
	// if (!my_list)
	// {
		// free_string_array (myarray);
		// ft_exit (nullnfree (myarray));
	// }
	// algo_three (&my_list);

	chain_printer (my_list);
	algorithm (&my_list, arr_size(myarray));

	// if (algorithm (my_list, arr_size(myarray)) == -1)
	// 	ft_exit (NULL);
	return (0);
}

void chain_printer(t_list *my_list)
{
	while (my_list->next)
	{
		printf ("list says: >%d<\t", *(int *)(my_list -> content));
		printf ("index: >%d<\n", *(int *)(my_list -> index));
		my_list = my_list -> next;
	}
	printf ("list says: >%d< \t", *(int *)(my_list -> content));
	printf ("index: >%d<\n", *(int *)(my_list -> index));

	return ;
}

int	*fn_intArr(char **p, int size)
{
	int	i;
	int	*intArr;

	if (!p || !*p || !size)
		return (NULL);
	intArr = malloc (sizeof (int) * size);
	i = 0;
	while (i < size)
	{
		intArr[i] = ft_atoi((const char*)(p)[i]);
		i++;
	}
	// TODO : free p using string free arr
	return (intArr);
}