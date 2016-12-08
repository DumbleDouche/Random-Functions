#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int r = 0;

	if (argc < 3)
	{
		printf("Missing Parameters, Usage: ./gcd \"number 1\" \"number 2\"\n");
		return (1);
	}
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);
	while (n2)
	{
		r = n1 % n2;
		n1 = n2;
		n2 = r;
	}
	printf("GCD is |%d|\n", n1);
	return (0);
}