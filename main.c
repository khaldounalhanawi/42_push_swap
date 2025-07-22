#include "push_swap.h"

int	*fn_intArr(char **p, int size);

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
	if (arr_size(myarray) == 3)
		algo_three (&my_list);
	else
		algo_five (&my_list, arr_size(myarray));
	// chain_printer (my_list);
	//algorithm (&my_list, arr_size(myarray));

	// if (algorithm (my_list, arr_size(myarray)) == -1)
	// 	ft_exit (NULL);
	return (0);
}

void chain_printer(t_list *my_list)
{
	if (!(my_list))
		return;
	while (my_list->next)
	{
		printf ("list says: >%d<\t\t", *(int *)(my_list -> content));
		printf ("index: >%d<\t", *(int *)(my_list -> index));
		if (my_list -> target)
			printf ("target: >%d<\t", *(int *)(my_list -> target -> index));
		if (my_list -> order)
			printf ("\t\torder: >%d<\t", *(int *)(my_list -> order));
		if (my_list -> cost)
			printf ("\t\tcost: >%d<\t", *(int *)(my_list -> cost));
		my_list = my_list -> next;
		printf ("\n");
	}
	printf ("list says: >%d< \t\t", *(int *)(my_list -> content));
	printf ("index: >%d<\t", *(int *)(my_list -> index));
	if (my_list -> target)
		printf ("target: >%d<\t", *(int *)(my_list -> target -> index));
	if (my_list -> order)
		printf ("\t\torder: >%d<\t", *(int *)(my_list -> order));
	if (my_list -> cost)
		printf ("\t\tcost: >%d<\t", *(int *)(my_list -> cost));
	printf ("\n");
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