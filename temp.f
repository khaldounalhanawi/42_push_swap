#include <stdio.h>

int main ()
{
	int	i;
	int	before;
	int	after;

	int	size;

	int	arr[10] = {21,14,11,9,8,3,7,22,77,5};

	i = 0;
	before = -1;
	after = -1;
	size = 10;
	while (i < size)
	{
		if (arr[i] >= 0 && arr[i] <= 4)
		{
			if (i < size / 2 && before < 0)
					before = i;
			else if (i >= size / 2)
				after = i;
		}
		i++;
	}
	after = after - size;
	if (before >= 0 && -after > before)
		printf ("before %d\n", before);
	else
		printf ("after %d\n", after);
}


						if (guide (a, start, end) >= 0)
						{
							if (flag == 1)
							{
								printf ("guide is %d\n",guide (a, start, end));
								double_rot (a, b);
								flag = 0;
							}
							else
							{
								printf ("guide is %d\n",guide (a, start, end));
								rot (a, "a");
							}
						}
						else
						{
							printf ("guide is %d\n",guide (a, start, end));
							rev_rot (a, "a");
						}