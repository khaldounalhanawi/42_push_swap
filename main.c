/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:31:44 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/31 13:40:19 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	*fn_intarr(char **p, int size);
static int	is_in(long val, int *intarr, int size);
static int	arr_size(char **arr);
static void	solve(int *intarray, int size);

int	main(int argc, char **argv)
{
	char	**myarray;
	int		*intarray;
	int		size;

	myarray = filter(argc, argv);
	if (!myarray)
		ft_exit (NULL);
	size = arr_size(myarray);
	intarray = fn_intarr (myarray, size);
	if (!intarray)
	{
		free_string_array (myarray);
		ft_exit (myarray);
	}
	free_string_array (myarray);
	free (myarray);
	solve (intarray, size);
	return (0);
}

static void	solve(int *intarray, int size)
{
	t_list	*my_list;

	my_list = initiate_chain (intarray, size);
	if (!my_list)
		ft_exit (intarray);
	if (size == 3)
	{
		algo_three (&my_list);
		ft_lstclear (&my_list, free);
	}
	else if (size == 2)
	{
		algo_two (&my_list);
		ft_lstclear (&my_list, free);
	}
	else
		algo_five (&my_list, size);
	free (intarray);
}

static int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	is_in(long val, int *intarr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (intarr[i] == (int)val)
			return (1);
		i++;
	}
	return (0);
}

static int	*fn_intarr(char **p, int size)
{
	int		i;
	int		*intarr;
	long	val;

	if (!p || !*p || !size)
		return (NULL);
	intarr = malloc (sizeof (int) * size);
	if (!intarr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		val = ft_atoi ((const char *)(p)[i]);
		if (val > INT_MAX || val < INT_MIN 
			|| is_in (val, intarr, i))
			return (nullnfree (intarr));
		intarr[i] = (int)val;
		i++;
	}
	return (intarr);
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
