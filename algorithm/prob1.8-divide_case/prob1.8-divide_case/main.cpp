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
	printf("n=%d, m=%d\nCNT=%d, CHK=%d\n\n", n, m, CNT, CHK);
	
	// **ERROR CHECK
	if (n < m)
	{
		printf("Can not divide!\n");
		return;
	}
	
	
	// **load
	if (CNT > 0) //직전 배열에 저장된 값을 불러와서 저장
	{
		for (int i = 0; i < CHK-1; i++)
		{
			if(SAVE[CNT][i] <= 0)
				SAVE[CNT][i] = SAVE[CNT - 1][i];
		}
	}


	/*
	// **VALUE
	if (n == m) // 1의 집합체
	{
		for (int i = CHK; i < CHK+n; i++)
		{
			SAVE[CNT][i] = 1; //나머지 원소를 모두 1로
		}

		//공통
		CHK--;
		CNT++; //다음 배열로 이동
		return;
	} // only 1 case
	*/
	

	// **return
	if (m == 1)
	{
		SAVE[CNT][CHK] = n; // no divide
		
		//공통
		CHK--; // 상위 루프로 돌아간다
		return;
	}


	// **recursive
	for (int i = 1; i <= n - m + 1; i++)
	{
		SAVE[CNT][CHK] = i;
		divide(n - i, m - 1);
		CNT++; //다음 배열로 이동
	}
	//공통
	CHK--;
	CNT--; //한번에 여러 루프가 해제될 경우 보정
}

void print_divide(int n, int m)
{
	printf("print (%d, %d)\n", n, m);
	CNT = 0;
	divide(n, m);
	CNT++;

	int i, j;
	int tmp;
	for (i = 0; i < CNT; i++)
	{
		printf("CNT = %d\n", i);
		for (j = 0; j < m; j++)
		{
			tmp = SAVE[i][j];
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
