// calculate nCr
#define _CRT_SECURE_NO_WARNINGS //scanf error 방지
#define MAXN 200
#include <stdio.h>
#include <time.h>

long long choose(int n, int r)
{
	if (r == 0 || n == r) return 1;

	return choose(n - 1, r - 1) + choose(n - 1, r);
}

long long choose2(int n, int r) //한번 계산된 값을 기억하여 다음에 동일한 계산에 소요되는 시간을 없앰
{
	static long long memo[MAXN][MAXN]; //계산된 값을 저장할 배열

	if (memo[n][r] > 0) //0보다 크다는 것은 저장된 값이 존재한다
		return memo[n][r]; //저장된 값 반환

	if (r == 0 || n == r) 
		return memo[n][r] = 1; //계산된 값으로 1을 저장하며 반환

	return memo[n][r] = choose2(n - 1, r - 1) + choose2(n - 1, r);
}

void main()
{
	int n, r, tmp;
	double start, end;

	printf("input n, r: ");
	scanf("%d %d", &n, &r);

	start = clock();
	tmp = choose2(n, r);
	end = clock();

	printf("%lld	-time : %fms\n", tmp, end-start);

	start = clock();
	tmp = choose2(n, r);
	end = clock();

	printf("%lld	-time : %fms\n", tmp, end - start);
}