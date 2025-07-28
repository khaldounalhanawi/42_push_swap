#include "push_swap.h"
#include <limits.h>

static int	*fn_intArr(char **p, int size);
static int	is_in (long val,int *intArr,int size);
static int	arr_size(char **arr);
static void solve(int *intArray, int size);

int main(int argc, char **argv)
{
	char	**myarray;
	int		*intArray;
	int		size;

	myarray = filter(argc, argv);
	if (!myarray)
		ft_exit (NULL);
	size = arr_size(myarray);
	intArray = fn_intArr (myarray, size);
	if (!intArray)
	{
		free_string_array (myarray);
		ft_exit (myarray);
	}
	free_string_array (myarray);
	free (myarray);
	solve (intArray, size);
	return (0);
}

static void solve(int *intArray, int size)
{
	t_list	*my_list;
	
	my_list = initiate_chain (intArray, size);
	if (!my_list)
		ft_exit (intArray);
	free (intArray);	
	if (size == 3)
		algo_three (&my_list);
	else if (size == 2)
		algo_two (&my_list);
	else
		algo_five (&my_list, size);
}

static int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	is_in (long val,int *intArr,int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		if (intArr[i] == (int)val)
			return (1);
		i++;
	}
	return (0);
}

static int	*fn_intArr(char **p, int size)
{
	int		i;
	int		*intArr;
	long	val;

	if (!p || !*p || !size)
		return (NULL);
	intArr = malloc (sizeof (int) * size);
	if (!intArr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		val = ft_atoi((const char*)(p)[i]);
		if (val > INT_MAX || val < INT_MIN 
			|| is_in (val, intArr, i))
			return (nullnfree (intArr));
		intArr[i] = (int)val;
		i++;
	}
	return (intArr);
}

// void chain_printer(t_list *my_list)
// {
// 	if (!(my_list))
// 		return;
// 	while (my_list->next)
// 	{
// 		printf ("list says: >%d<\t\t", *(int *)(my_list -> content));
// 		printf ("index: >%d<\t", *(int *)(my_list -> index));
// 		if (my_list -> target)
// 			printf ("target: >%d<\t", *(int *)(my_list -> target -> index));
// 		if (my_list -> order)
// 			printf ("\t\torder: >%d<\t", *(int *)(my_list -> order));
// 		if (my_list -> cost)
// 			printf ("\t\tcost: >%d<\t", *(int *)(my_list -> cost));
// 		my_list = my_list -> next;
// 		printf ("\n");
// 	}
// 	printf ("list says: >%d< \t\t", *(int *)(my_list -> content));
// 	printf ("index: >%d<\t", *(int *)(my_list -> index));
// 	if (my_list -> target)
// 		printf ("target: >%d<\t", *(int *)(my_list -> target -> index));
// 	if (my_list -> order)
// 		printf ("\t\torder: >%d<\t", *(int *)(my_list -> order));
// 	if (my_list -> cost)
// 		printf ("\t\tcost: >%d<\t", *(int *)(my_list -> cost));
// 	printf ("\n");
// 	return ;
// }