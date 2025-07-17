#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	*fn_intArr(char **p, int size);

int	main()
{
	int	*intArr;
	char	**p;

	p = malloc ((sizeof (char *)) * 3);

	p[0] = "1";
	p[1] = "9";
	p[2] = "3";

	intArr = fn_intArr (p, 3);
	int i = 0;
	while (i < 3)
	{
		printf ("%d\n", intArr[i]);
		i++;
	}
}

int	*fn_intArr(char **p, int size)
{
	int		i;
	int		*intArr;

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