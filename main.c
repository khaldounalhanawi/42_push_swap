#include "push_swap.h"

int main(int argc, char **argv)
{
	char **myarray;

	myarray = filter(argc, argv);
	if (!myarray)
		return (0);
	
	int i = 0;
	while (myarray[i])
	{
		printf("arr >%s<\n", myarray[i]);
		i++;
	}
}
