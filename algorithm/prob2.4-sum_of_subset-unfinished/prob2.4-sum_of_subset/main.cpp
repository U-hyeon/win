#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define SIZE 10

//int proper_subset[SIZE][SIZE];

int subset_sum_recursive(int subset[], int m, int n, int sum) // subset 집합에서 n개의 원소를 합쳐 sum을 만들수 있으면 TRUE, 아니면 FALSE
{
	if (m < n) return FALSE; // 포함해야 하는 원소의 수보다 전체원소의 수가 적다 => 더 볼것없이 FALSE
	if (sum < 0) return FALSE; // sum값을 모두 소모했다 => FALSE

	if (m == 0) // 모든 원소를 다 확인하였다
	{
		if (sum == 0) return TRUE; // sum값이 일치한다 => TRUE
		else return FALSE; // sum값이 일치하지 않는다 => FALSE
	}
	
	

	if (subset_sum_recursive(subset, m - 1, n, sum) == TRUE) // subset[m-1]을 포함하지 않은 경우에서 TRUE 발생 => TRUE
		return TRUE;
	else if (subset_sum_recursive(subset, m - 1, n - 1, sum - subset[m - 1]) == TRUE) // subset[m-1]을 포함하는 경우에서 TRUE 발생 => TRUE
		return TRUE;
	else 
		return FALSE;
}

int c[SIZE][SIZE];

void subset_sum_DP(int subset[], int m, int n, int sum) // 원소가 m개인 subset 집합에서 n개의 원소를 합쳐 sum을 만들수 있으면 TRUE, 아니면 FALSE
{
	int i, j;

	for (i = 0; i <= n; i++)
		c[i][0] = 1;

	for (i = 1; i <= m; i++)
		c[0][i] = 0;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			c[i][j] = 0;

			if (j >= subset[i - 1]) 
			{
				if (c[i - 1][j - subset[i - 1]] == 1)
					c[i][j] = 1;
			}

			if (c[i - 1][j] == 1)
				c[i][j] = 1;
		}
}

void init(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = (rand() % 100) + 1;
}

void main()
{
	int arr[SIZE];
	int n, sum;

	init(arr, SIZE);

	cout << "Enter n, sum : ";
	cin >> n >> sum;
	
	for (int i = 0; i < SIZE; i++) cout << "[" << arr[i] << "] ";
	cout << endl;

	int tmp = subset_sum_recursive(arr, SIZE, n, sum);
	subset_sum_DP(arr, SIZE, n, sum);

	//판정
	if (tmp == TRUE) cout << "possible!" << endl;
	else cout << "impossible!" << endl;


	//판정
	if (c[n][SIZE] == 1) cout << "possible!" << endl;
	else cout << "impossible!" << endl;
}