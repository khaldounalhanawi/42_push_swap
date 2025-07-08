# include <stdio.h>

int	ft_isnum(char *str);
int input_check(char **argv);

int main(int argc, char **argv)
{
	
	if (argc <= 1)
		return (0);
	// printf ("%d", ft_isnum(""));	
	printf("result is %d", input_check(argv));
	// check quality of input.. >(1) good  >(-1) return error
}

int	ft_isnum(char *str)
{
	if (!str || *str == ' ')
		return (0);
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == ' ')
			str++;
		else
			return (-5);
	}
	return (1);
}

int input_check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isnum(argv[i]) != 1)
		{
			return (-1);
		}
		i++;
	}
	return (1);
}