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
int passed[SIZE_M][SIZE_N] = {}; //�������� 1

int max(int a, int b, int c, int d)
{
	if (a >= b && a >= c && a >= d) return a;
	else if (b >= c && b >= d) return b;
	else if (c >= d) return c;
	else return d;
}

int path(int m, int n)
{
	if (m == 0 && n == 0) return Map[m][n];
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
	int r = path(m, n);
	print_route(MaxNroute, m, n);
	printf("\nMaxN of all routes (recursive) : %d\n", r);
}