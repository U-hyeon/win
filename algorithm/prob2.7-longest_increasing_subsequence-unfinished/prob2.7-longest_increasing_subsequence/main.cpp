#include <stdio.h>

#define SIZE 20

int arr[SIZE] = { 10,20,1,9,11,19,2,8,12,18,5,15,4,6,14,16,3,7,13,17 };
int start[SIZE] = {};
int end[SIZE] = {};

void find_LIS(int A[], int n)
{
	int decrease[100] = {};
	int i=0, tmp;

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

	for (i = 0; i < n - 1; i++) printf("  [%d]", decrease[i]);
	printf("\n");
	
	int cnt_s = 0;
	int cnt_e = 0;
	if (decrease[0] != true)
	{
		printf("hit start 0\n");
		start[cnt_s] = 0;
		cnt_s++;
	}
	for (i = 0; i < n - 1; i++)
	{
		if ( !(decrease[i]) && decrease[i + 1] )
		{
			printf("hit end %d\n", i);
			end[cnt_e] == i;
			cnt_e++;
		}
		if ( decrease[i] && !(decrease[i + 1]) )
		{
			printf("hit start %d\n", i);
			start[cnt_s] == i;
			cnt_s++;
		}
	}

	printf("start [] : \n");
	for (i = 0; i < cnt_s; i++) printf("  [%d]", start[i]);
	printf("\nend [] : \n");
	for (i = 0; i < cnt_e; i++) printf("  [%d]", end[i]);
	printf("\n");
}

void main()
{
	find_LIS(arr, SIZE);
}