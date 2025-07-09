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
	words_split = ft_split(argv[1], ' ');
	if (!words_split)
		ft_exit();
	while (words_split[i])
	{
		if (input_check (&words_split[i], 0) == -1)
		{
			free_string_array (words_split);
			free (words_split);
			ft_exit ();
		}
		i++;
	}
	return (words_split);
}

char **filter(int argc, char **argv)
{
	int i;

	if (argc <= 1)
		return (NULL);
	if (argc > 2)
	{
		if (input_check(argv, 1) == -1)
			ft_exit ();
		else
			return (++argv);
	}
	else if (argc == 2)
		return (one_arg(argv));
	return (NULL);
}
