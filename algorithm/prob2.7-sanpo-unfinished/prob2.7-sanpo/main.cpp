#include <stdio.h>
#include <iostream>
using namespace std;

// 지나온 경로의 모든 수 n을 합쳤을 때, 그 값이 최대가 되는 경로에서의 n의 합을 구하는 함수를 작성
#define SIZE_M 5 //행
#define SIZE_N 5 //열

int Map[SIZE_M][SIZE_N] = {
	{1,1,2,1,5},
	{1,4,4,3,1},
	{2,1,1,1,2},
	{1,3,5,1,1},
	{1,5,1,2,2}
}; // 한번의 이동에 x값과 y값중 하나만 +1, 뒤로 돌아갈수는 없다

int MaxNroute[SIZE_M][SIZE_N] = {}; //중복계산 방지
int passed[SIZE_M][SIZE_N] = {}; //지나가면 1

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
	} // 좌표 범위 불일치

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