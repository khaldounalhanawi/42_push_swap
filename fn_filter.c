#include "push_swap.h"

static int input_check(char **argv, int type)
{
	int i;

	i = type;
	while (argv[i])
	{
		if (isnum(argv[i]) != 1)
			return (-1);
		i++;
	}
	return (1);
}

static char **one_arg(char **argv)
{
	int i;
	char **words_split;

	i = 0;
	words_split = ft_split(argv[1], ' '); //TODO make sure split frees evrythnng
	if (!words_split)
		ft_exit (NULL);
	while (words_split[i])
	{
		if (input_check (&words_split[i], 0) == -1)
		{
			free_string_array (words_split);
			free (words_split);
			ft_exit (NULL);
		}
		i++;
	}
	words_split[i] = NULL;
	return (words_split);
}

void	copy_arr(char **p, char **arr, int end)
{
	while (end)
	{
		*p++ = *arr++;
		end --;
	}
	*p = NULL;
}

char **filter(int argc, char **argv)
{
	char	**p;
	
	if (argc <= 1)
		exit (0);
	if (argc > 2)
	{
		if (input_check(argv, 1) == -1)
			ft_exit (NULL);
		else
		{
			p = malloc (sizeof (char *) * argc);
			if (!p)
				ft_exit (NULL);
			argv ++;
			copy_arr (p, argv, argc - 1);
			return (p);
		}
	}
	else if (argc == 2)
		return (one_arg(argv));
	return (NULL);
}
