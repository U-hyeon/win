#include <stdio.h>
#include <iostream>
using namespace std;

// k를 입력받아 파스칼 삼각형의 k번째 줄까지 출력하는 함수를 작성한다

int psc_tri(int n, int k)
{
	if (n < 1 || k < 1)
	{
		printf("No result!\n");
		return -1;
	}

	if (k == 1 || n == k) return 1;

	return psc_tri(n - 1, k - 1) + psc_tri(n - 1, k);
}

void print_psc_tri(int k)
{
	int i, j;
	int tmp;
	for (i = 1; i <= k; i++)
	{
		for (j = i; k-j > 0; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= i; j++)
		{
			tmp = psc_tri(i, j);
			printf("%d ", tmp);
			if (tmp < 100) printf(" ");
			if (tmp < 10) printf(" ");
		}
		printf("\n");
	}
}

void main()
{
	int k=0;
	printf("Enter k : ");
	cin >> k;
	print_psc_tri(k);
}