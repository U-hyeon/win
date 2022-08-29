#include <stdio.h>
#include <iostream>
using namespace std;

// ������ ����� ��� �� n�� ������ ��, �� ���� �ִ밡 �Ǵ� ��ο����� n�� ���� ���ϴ� �Լ��� �ۼ�
#define SIZE_M 5 //��
#define SIZE_N 5 //��

int Map[SIZE_M][SIZE_N] = {
	{1,1,2,1,5},
	{1,4,4,3,1},
	{2,1,1,1,2},
	{1,3,5,1,1},
	{1,5,1,2,2}
}; // �ѹ��� �̵��� x���� y���� �ϳ��� +1, �ڷ� ���ư����� ����

int MaxNroute[SIZE_M][SIZE_N] = {}; //�ߺ���� ����

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

// idea : ����ġ�� ���� �߰��Ǵ� n ���� �����ϴ�. ���� �������������� n�� ���� ū ��θ� ������ �ϸ� �ִ밡 �Ǵ� ��θ� �� �� �ִ�.
int MaxN_recursive(int arr[][5], int m, int n)
{ // ** m��n�� = arr[m-1][n-1]
	int current = arr[m - 1][n - 1];

	if (m < 1 || n < 1)
	{
		printf("Wrong coordinates!\n");
		exit(0);
	} // ��ǥ ���� ����ġ

	// starting point
	if (m == 1 && n == 1) return MaxNroute[m - 1][n - 1] = current;

	// edge of Map
	if (m == 1)
	{
		if(MaxNroute[m - 1][n - 2] > 0) // ����� ���� �ִٸ�
			return MaxNroute[m - 1][n - 1] = MaxNroute[m - 1][n - 2] + current;
		else // ����� ���� ���ٸ�
			return MaxNroute[m - 1][n - 1] = MaxN_recursive(Map, m, n - 1) + current;
	}
	else if (n == 1)
	{
		if (MaxNroute[m - 2][n - 1] > 0) // ����� ���� �ִٸ�
			return MaxNroute[m - 1][n - 1] = MaxNroute[m - 2][n - 1] + current;
		else // ����� ���� ���ٸ�
			return MaxNroute[m - 1][n - 1] = MaxN_recursive(Map, m - 1, n) + current;
	}

	// default
	return MaxNroute[m - 1][n - 1] = current + max(MaxN_recursive(Map, m - 1, n), MaxN_recursive(Map, m, n - 1));
} // ��� �񱳰����� max(a, b) �Լ��� �ۼ��Ͽ� �ڵ带 ����ȭ �� �� �ִ�

/*
int MaxN_DP(int arr[][5], int m, int n)
{
	int current = arr[m - 1][n - 1];

	int up, left;
	// (�ߺ�������) ������α����� �� (up)
	if (MaxNroute[m - 2][n - 1] > 0)
		up = MaxNroute[m - 2][n - 1];
	else
		up = MaxN_recursive(Map, m - 1, n);
	// (�ߺ�������) ������α����� �� (left)
	if (MaxNroute[m - 1][n - 2] > 0)
		left = MaxNroute[m - 1][n - 2];
	else
		left = MaxN_recursive(Map, m, n - 1);

	if (up > left) return MaxNroute[m - 1][n - 1] = up + arr[m - 1][n - 1];
	else return MaxNroute[m - 1][n - 1] = left + arr[m - 1][n - 1];
}
*/


// DP ������
int from[SIZE_M][SIZE_N];
enum { LEFT, UP };

void MaxN_DP(int arr[][5], int m, int n)
{
	int i, j;

	arr[0][0] = Map[0][0];
	for (i = 1; i < m; i++)
	{
		arr[i][0] = arr[i - 1][0] + Map[i][0];
		from[i][0] = LEFT;
	}
	for (j = 1; j < n; j++)
	{
		arr[0][j] = arr[0][j - 1] + Map[0][j];
		from[0][j] = UP;
	}
	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (arr[i - 1][j] > arr[i][j - 1])
				from[i][j] = LEFT;
			else
				from[i][j] = UP;

			arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]) + Map[i][j];
		}
	}
}

void print_route(int arr[][5], int m, int n)
{
	if (m < 1 || n < 1)
	{
		printf("Wrong coordinates!\n");
		exit(0);
	} // ��ǥ ���� ����ġ

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("[%d] ", arr[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int m, n;
	cout << "Enter m , n : ";
	cin >> m >> n;

	printf("Map : \n");
	print_route(Map, m, n);
	printf("\n");

	printf("route : \n");
	int r = MaxN_recursive(Map, m, n);
	print_route(MaxNroute, m, n);
	printf("\nMaxN of all routes (recursive) : %d\n", r);

	
	// reset
	for (int i = 0; i < SIZE_M; i++)
		for (int j = 0; j < SIZE_N; j++)
			MaxNroute[i][j] = 0;

	printf("route : \n");
	MaxN_DP(MaxNroute, m, n);
	print_route(MaxNroute, m, n);
	printf("\nMaxN of all routes (Dynamic Programming) : %d\n", MaxNroute[m-1][n-1]);
	
}