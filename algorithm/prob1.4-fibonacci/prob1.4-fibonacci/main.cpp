#include <stdio.h>
#include <stdlib.h>
#define MAXN 200

long long Fibonacci(int n) //recursive를 통한 top down 방식의 계산
{
	if (n <= 0)
	{
		printf("Enter positive integer!\n");
		return -1;
	}

	if (n == 1 || n == 2) return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

long long Fibonacci2(int n) //한번 계산한 값을 기억, 이후 동일과정생략
{
	static long long memo[MAXN];

	if (memo[n] > 0)
		return memo[n];

	if (n == 1 || n == 2)
		return memo[n]=1;

	return memo[n] = Fibonacci2(n - 1) + Fibonacci2(n - 2);
}

long long Fibonacci3(int n) //non-recursive bottom up 방식의 계산
{
	long long i, f_i, f_i_1, t;
	if (n == 1 || n == 2)
		return 1;

	f_i_1 = 1;
	f_i = 1;
	for (i = 3; i <= n; i++)
	{
		t = f_i;
		f_i = f_i_1 + f_i;
		f_i_1 = t;
	}
	return f_i;
}

void main()
{
	int tmp;
	for (int i = 1; i < 20; i++)
	{
		tmp = rand() % 40;
		printf("Fibonacci(%d) = %d\n", i, Fibonacci3(i));
	}
}