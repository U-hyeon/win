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

	// **ERROR CHECK
	if (n < m)
	{
		printf("Can not divide!\n");
		return;
	}
	

	// **VALUE
	if (CNT > 0) //���� �迭�� ����� ���� �ҷ��ͼ� ����
	{
		for (int i = 0; i < CHK; i++)
		{
			SAVE[CNT][i] = SAVE[CNT - 1][i];
		}
	}

	if (n == m) // 1�� ����ü
	{
		for (int i = CHK; i < CHK+n; i++)
		{
			SAVE[CNT][i] = 1; //������ ���Ҹ� ��� 1��
		}
	} // only 1 case

	if (m == 1) SAVE[CNT][CHK] = n; // no divide


	// **recursive
	for (int i = 1; i <= n - m + 1; i++)
	{
		SAVE[CNT][CHK] = i;
		divide(n - i, m - 1);
	}

	//����
	CHK--;
	CNT++; //���� �迭�� �̵�
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
