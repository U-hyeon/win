#include <stdio.h>
#include <iostream>
using namespace std;

#define SIZE 200

int SAVE[SIZE][SIZE];
int CNT = 0, CHK = -1;

// idea : 루프를 돌며 상위 루프까지의 결과를 CNT를 이용해 직전 배열에 저장된 값을 불러와서 저장

void divide(int n, int m)
{
	CHK++;

	// **ERROR CHECK
	if (n < m)
	{
		printf("Can not divide!\n");
		return;
	}
	

	// **VALUE
	if (CNT > 0) //직전 배열에 저장된 값을 불러와서 저장
	{
		for (int i = 0; i < CHK; i++)
		{
			SAVE[CNT][i] = SAVE[CNT - 1][i];
		}
	}

	if (n == m) // 1의 집합체
	{
		for (int i = CHK; i < CHK+n; i++)
		{
			SAVE[CNT][i] = 1; //나머지 원소를 모두 1로
		}
	} // only 1 case

	if (m == 1) SAVE[CNT][CHK] = n; // no divide


	// **recursive
	for (int i = 1; i <= n - m + 1; i++)
	{
		SAVE[CNT][CHK] = i;
		divide(n - i, m - 1);
	}

	//공통
	CHK--;
	CNT++; //다음 배열로 이동
}

void print_divide(int n, int m)
{
	CNT = 0;
	divide(n, m);

	int i, j;
	int tmp;
	for (i = 0; i < CNT; i++)
	{
		for (j = 0; j < n; j++)
		{
			tmp = SAVE[i][j];
			if(tmp > 0)
				printf("%d ", tmp);
		}
		printf("\n");
	}
}

void main()
{
	int n, m;
	cout << "Enter n, m : ";
	cin >> n >> m;

	print_divide(n, m);
}
