//2차원 혹은 3차원 상의 n개의 점이 주어질때 거리가 가장 가까운 한 쌍의 점을 찾는 알고리즘을 제시하라
//모든 쌍의 점을 비교하는 방법 제외
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 10000

int test[10] = { 10, 20, 31, 41, 45, 60, 72, 84, 99, 110 }; // closest pair : (41, 45), distance = 4

struct point
{
	int x;
	int y;
}; //3차원 점의 거리를 알고 싶다면 이 구조체를 이용하도록 코드를 수정할 것

double distance(point a, point b)
{
	float r, x, y;
	x = a.x - b.x;
	y = a.y - b.y;
	r = sqrt( pow(x,2) + pow(y,2) );
	return r;
}
//----------------------------------------------------------------------------------------------

double closest_distance_naive(int arr[], int n)
{
	int i, j;
	double tmp;
	double r = 999999;
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

double closest_distance_naive(point arr[], int n)
{
	int i, j;
	double tmp;
	double r = 999999;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				tmp = distance(arr[i], arr[j]);
				if (r > tmp) r = tmp;
			}
		}
	}
	return r;
}
//----------------------------------------------------------------------------------------------

double closest_distance_better(int arr[], int n)
{
	int i, j;
	double tmp;
	double r = 999999;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i] - arr[j] > -r && arr[i] - arr[j] < r)
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

double closest_distance_better(point arr[], int n)
{
	int i, j;
	double tmp;
	double r = 999999;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if ( (arr[i].x - arr[j].x > -r && arr[i].x - arr[j].x < r) && (arr[i].y - arr[j].y > -r && arr[i].y - arr[j].y < r))
			{
				if (i != j)
				{
					tmp = distance(arr[i], arr[j]);
					if (r > tmp) r = tmp;
				}
			}
		}
	}
	return r;
}
//----------------------------------------------------------------------------------------------

void init(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (SIZE * 100);
		//중복체크
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) i--;
		}
	}
}

void init(point arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i].x = rand() % (SIZE * 100);
		arr[i].y = rand() % (SIZE * 100);
		//중복체크
		for (int j = 0; j < i; j++)
		{
			if (arr[i].x == arr[j].x && arr[i].y == arr[j].y) i--;
		}
	}
}
//----------------------------------------------------------------------------------------------

void main()
{
	//int points[SIZE];
	point points[SIZE];
	double start, end, time, tmp;

	init(points, SIZE);

	start = clock() / CLOCKS_PER_SEC;
	tmp = closest_distance_naive(points, SIZE);
	end = clock() / CLOCKS_PER_SEC;
	time = end - start;
	printf("naive solution : %2.f, time spend : %f ms\n", tmp, time);

	start = clock() / CLOCKS_PER_SEC;
	tmp = closest_distance_better(points, SIZE);
	end = clock() / CLOCKS_PER_SEC;
	time = end - start;
	printf("better solution : %2.f, time spend : %f ms\n", tmp, time);
}