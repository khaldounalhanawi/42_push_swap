#include "push_swap.h"

int isnum(char *str)
{
	if (!str || *str == ' ')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (-5);
	}
	return (1);
}

void ft_exit(void *p1)
{
	if (p1)
		free ((void *)p1);
	write(2, "Error\n", 6);
	exit(1);
}

void *nullnfree(void *p1)
{
	if (p1)
		free ((void *)p1);
	return (NULL);
}

void free_string_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	return ;
}
