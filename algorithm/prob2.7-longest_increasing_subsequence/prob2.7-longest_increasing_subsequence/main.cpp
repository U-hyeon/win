#include <stdio.h>

#define SIZE 20

int arr[SIZE] = { 10,20,1,9,11,19,2,8,12,18,5,15,4,6,14,16,3,7,13,17 };
int start[SIZE] = {};
int end[SIZE] = {};

int find_LIS(int A[], int n)
{
	int decrease[100] = {};
	int i=0, tmp;

	// display A[ ]
	tmp = A[i];
	if (tmp < 10) printf("[%d]  ", tmp);
	else if (tmp >= 10 && tmp < 100) printf("[%d] ", tmp);

	for (i = 0; i < n - 1; i++)
	{
		tmp = A[i+1];
		if(tmp <10) printf("[%d]  ", tmp);
		else if (tmp >= 10 && tmp < 100) printf("[%d] ", tmp);

		if (A[i] > A[i + 1]) decrease[i] = true;
	}
	printf("\n");

	// display decrease[ ]
	for (i = 0; i < n - 1; i++) printf("  [%d]", decrease[i]);
	printf("\n");
	
	// find increasing subsequence(IS)
	int cnt_s = 0;
	int cnt_e = 0;
	if (decrease[0] != true)
	{
		start[cnt_s] = 0;
		cnt_s++;
	}
	for (i = 0; i < n - 1; i++)
	{
		if ( !(decrease[i]) && decrease[i + 1] )
		{
			end[cnt_e] = i;
			cnt_e++;
		}
		if ( decrease[i] && !(decrease[i + 1]) )
		{
			start[cnt_s] = i;
			cnt_s++;
		}
	}

	// display start/end point of IS
	printf("start [] : \n");
	for (i = 0; i < cnt_s; i++) printf("  [%d]", start[i]);
	printf("\nend [] : \n");
	for (i = 0; i < cnt_e; i++) printf("  [%d]", end[i]);
	printf("\n");

	//calculate the length of the longest IS
	int length = 0;
	for (i = 0; i < cnt_e; i++) // cnt_e를 기준으로
	{
		tmp = end[i] - start[i];
		if (tmp > length) length = tmp;
	}

	return length;
}

void main()
{
	int tmp = find_LIS(arr, SIZE);
	printf("the length of LIS = %d\n", tmp);
}