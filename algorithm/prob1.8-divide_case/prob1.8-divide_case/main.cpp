#include <stdio.h>
#include <iostream>
using namespace std;

#define SIZE 200

int SAVE[SIZE][SIZE];
int CNT = 0, CHK = -1;

// idea : ������ ���� ���� ���������� ����� CNT�� �̿��� ���� �迭�� ����� ���� �ҷ��ͼ� ����

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
	if (CNT > 0) //���� �迭�� ����� ���� �ҷ��ͼ� ����
	{
		for (int i = 0; i < CHK-1; i++)
		{
			if(SAVE[CNT][i] <= 0)
				SAVE[CNT][i] = SAVE[CNT - 1][i];
		}
	}


	/*
	// **VALUE
	if (n == m) // 1�� ����ü
	{
		for (int i = CHK; i < CHK+n; i++)
		{
			SAVE[CNT][i] = 1; //������ ���Ҹ� ��� 1��
		}

		//����
		CHK--;
		CNT++; //���� �迭�� �̵�
		return;
	} // only 1 case
	*/
	

	// **return
	if (m == 1)
	{
		SAVE[CNT][CHK] = n; // no divide
		
		//����
		CHK--; // ���� ������ ���ư���
		return;
	}


	// **recursive
	for (int i = 1; i <= n - m + 1; i++)
	{
		SAVE[CNT][CHK] = i;
		divide(n - i, m - 1);
		CNT++; //���� �迭�� �̵�
	}
	//����
	CHK--;
	CNT--; //�ѹ��� ���� ������ ������ ��� ����
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
