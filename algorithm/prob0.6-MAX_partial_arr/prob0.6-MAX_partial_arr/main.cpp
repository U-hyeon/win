#include <stdio.h>
#define SIZE 20

void MAX_partial_arr(int arr[], int n, int p) // 0 <= i <= p <= j < n 에 대하여 배열의 i~j 까지의 원소의 합이 최대가 되는 i,j를 출력
{
	int i_max, j_max;
	int i,j;
	int sum, sum_tmp;

	// idea : i~p까지의 부분합이 최대가 되고 p~j까지의 부분합이 최대가 된다면 i~j까지의 부분합이 최대가 된다.
	int part1[SIZE];
	int part2[SIZE];
	
	sum = -999;
	for (i = p; i >= 0; i--)
	{
		sum_tmp = 0;
		for (j = i; j <= p; j++)
		{
			sum_tmp = sum_tmp + arr[j];
		}
		if (sum < sum_tmp)
		{
			i_max = i;
			sum = sum_tmp;
		}
	}

	sum = -999;
	for (i = p; i < n; i++)
	{
		sum_tmp = 0;
		for (j = p; j <= i; j++)
		{
			sum_tmp = sum_tmp + arr[j];
		}
		if (sum < sum_tmp)
		{
			j_max = i;
			sum = sum_tmp;
		}
	}
	
	printf("for point %d,	MAX : i=%d,		j=%d\n", p, i_max, j_max);
}

void main()
{
	int arr[20] = 
	{ -1,		// 0 
		23,		// 1
		5,		// 2
		37,		// 3
		-32,	// 4
		1,		// 5
		-8,		// 6
		-9,		// 7
		30,		// 8
		-40,	// 9
		10,		// 10
		-20,	// 11
		25,		// 12
		-15,	// 13
		2,		// 14
		3,		// 15
		6,		// 16
		7,		// 17
		-21,	// 18
		19		// 19
	};
	for (int i = 0; i < SIZE; i++)
	{
		MAX_partial_arr(arr, SIZE, i);
	}
}