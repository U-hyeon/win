#include <stdio.h>

int factorial_naive(int n)
{
	if (n < 0)
	{
		printf("Negative integer!\n");
		return -1;
	}
	else if (n == 0 || n == 1) return n;
	else
	{
		int r = 1;
		for (int i = n; i > 0; i--)
		{
			r = r * i;
		}
		return r;
	}
} //Naive solution에서는 표현 가능한 범위를 넘어섰을때 값이 정상적으로 출력되지 않음

int factorial(int n) //recursive
{
	if (n < 0)
	{
		printf("Negative integer!\n");
		return -1;
	}
	else if (n == 0 || n == 1) return n;
	else
	{
		int r = n * factorial(n - 1);
		return r;
	}
} // 재귀적 호출에서는 stack overflow를 조심할것!

void main()
{
	printf("--NAIVE\n");
	printf("factorial(1) = %d\n", factorial_naive(1));
	printf("factorial(2) = %d\n", factorial_naive(2));
	printf("factorial(3) = %d\n", factorial_naive(3));
	printf("factorial(4) = %d\n", factorial_naive(4));
	printf("factorial(5) = %d\n", factorial_naive(5));
	
	printf("--RECURSIVE\n");
	printf("factorial(1) = %d\n", factorial(1));
	printf("factorial(2) = %d\n", factorial(2));
	printf("factorial(3) = %d\n", factorial(3));
	printf("factorial(4) = %d\n", factorial(4));
	printf("factorial(5) = %d\n", factorial(5));
}