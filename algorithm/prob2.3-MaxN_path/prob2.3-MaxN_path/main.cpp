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

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

// idea : 지나치는 순간 추가되는 n 값은 동일하다. 따라서 직전지점까지의 n의 합이 큰 경로를 역추적 하면 최대가 되는 경로를 알 수 있다.
int MaxN_recursive(int arr[][5], int m, int n)
{ // ** m행n열 = arr[m-1][n-1]
	int current = arr[m - 1][n - 1];

	if (m < 1 || n < 1)
	{
		printf("Wrong coordinates!\n");
		exit(0);
	} // 좌표 범위 불일치

	// starting point
	if (m == 1 && n == 1) return MaxNroute[m - 1][n - 1] = current;

	// edge of Map
	if (m == 1)
	{
		if(MaxNroute[m - 1][n - 2] > 0) // 저장된 값이 있다면
			return MaxNroute[m - 1][n - 1] = MaxNroute[m - 1][n - 2] + current;
		else // 저장된 값이 없다면
			return MaxNroute[m - 1][n - 1] = MaxN_recursive(Map, m, n - 1) + current;
	}
	else if (n == 1)
	{
		if (MaxNroute[m - 2][n - 1] > 0) // 저장된 값이 있다면
			return MaxNroute[m - 1][n - 1] = MaxNroute[m - 2][n - 1] + current;
		else // 저장된 값이 없다면
			return MaxNroute[m - 1][n - 1] = MaxN_recursive(Map, m - 1, n) + current;
	}

	// default
	return MaxNroute[m - 1][n - 1] = current + max(MaxN_recursive(Map, m - 1, n), MaxN_recursive(Map, m, n - 1));
} // 대소 비교과정을 max(a, b) 함수를 작성하여 코드를 간소화 할 수 있다

/*
int MaxN_DP(int arr[][5], int m, int n)
{
	int current = arr[m - 1][n - 1];

	int up, left;
	// (중복계산방지) 직전경로까지의 합 (up)
	if (MaxNroute[m - 2][n - 1] > 0)
		up = MaxNroute[m - 2][n - 1];
	else
		up = MaxN_recursive(Map, m - 1, n);
	// (중복계산방지) 직전경로까지의 합 (left)
	if (MaxNroute[m - 1][n - 2] > 0)
		left = MaxNroute[m - 1][n - 2];
	else
		left = MaxN_recursive(Map, m, n - 1);

	if (up > left) return MaxNroute[m - 1][n - 1] = up + arr[m - 1][n - 1];
	else return MaxNroute[m - 1][n - 1] = left + arr[m - 1][n - 1];
}
*/


// DP 모법답안
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