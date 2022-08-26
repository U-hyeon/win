//2차원 혹은 3차원 상의 n개의 점이 주어질때 거리가 가장 가까운 한 쌍의 점을 찾는 알고리즘을 제시하라
//모든 쌍의 점을 비교하는 방법 제외
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int test[10] = { 10, 20, 31, 41, 45, 60, 72, 84, 99, 110 }; // closest pair : (41, 45), distance = 4

struct point
{
	int x;
	int y;
}; //3차원 점의 거리를 알고 싶다면 이 구조체를 이용하도록 코드를 수정할 것

int closest_distance_naive(int arr[], int n)
{
	int i, j;
	int tmp;
	int r = 999;
	for (i=0; i<n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				tmp = abs(arr[i] - arr[j]);
				if (r > tmp) r = tmp;
			}
		}
	}
	return r;
}

int closest_distance_better(int arr[], int n)
{
	int i, j;
	int tmp;
	int r = 999;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i - j > -r && i - j < r)
			{
				if (i != j)
				{
					tmp = abs(arr[i] - arr[j]);
					if (r > tmp) r = tmp;
				}
			}
		}
	}
	return r;
}

void init(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10000;
		//중복체크
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) i--;
		}
	}
}

void main()
{
	int points[SIZE];
	init(points, SIZE);
	printf("naive solution : %d\n", closest_distance_naive(points, 10));
	printf("better solution : %d\n", closest_distance_better(points, 10));
}