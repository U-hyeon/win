#include <stdio.h>

long long Fibonacci(int n)
{
	if (n <= 0)
	{
		printf("Enter positive integer!\n");
		return -1;
	}

	if (n == 1 || n == 2) return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void main()
{
	for (int i = 1; i < 20; i++)
		printf("%d\n", Fibonacci(i));
}