//2���� Ȥ�� 3���� ���� n���� ���� �־����� �Ÿ��� ���� ����� �� ���� ���� ã�� �˰����� �����϶�
//��� ���� ���� ���ϴ� ��� ����
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int test[10] = { 10, 20, 31, 41, 45, 60, 72, 84, 99, 110 }; // closest pair : (41, 45), distance = 4

struct point
{
	int x;
	int y;
}; //3���� ���� �Ÿ��� �˰� �ʹٸ� �� ����ü�� �̿��ϵ��� �ڵ带 ������ ��

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
		//�ߺ�üũ
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