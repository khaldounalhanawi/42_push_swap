# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	isnum(char *str);
int input_check(char **argv);

int main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	if (argc > 2)
	{
		if (input_check(argv) == -1)
		{
			write (2, "ERROR\n", 6);
			exit(1);
		}
	}
	else if (argc == 2)
	{
		// divide into spaces
		// run input check
	}
}

int	isnum(char *str)
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

int input_check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (isnum(argv[i]) != 1)
			return (-1);
		i++;
	}
	return (1);
}