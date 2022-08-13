// calculate nCr
#define _CRT_SECURE_NO_WARNINGS //scanf error ����
#define MAXN 200
#include <stdio.h>
#include <time.h>

long long choose(int n, int r)
{
	if (r == 0 || n == r) return 1;

	return choose(n - 1, r - 1) + choose(n - 1, r);
}

long long choose2(int n, int r) //�ѹ� ���� ���� ����Ͽ� ������ ������ ��꿡 �ҿ�Ǵ� �ð��� ����
{
	static long long memo[MAXN][MAXN]; //���� ���� ������ �迭

	if (memo[n][r] > 0) //0���� ũ�ٴ� ���� ����� ���� �����Ѵ�
		return memo[n][r]; //����� �� ��ȯ

	if (r == 0 || n == r) 
		return memo[n][r] = 1; //���� ������ 1�� �����ϸ� ��ȯ

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