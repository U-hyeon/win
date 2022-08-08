#include <stdio.h>
#define SIZE 10

void print_arr(int arr[], int len)
{
	for (int i=0 ; i<len ; i++)
	{
		printf("[%d] ",arr[i]);
	}
	printf("\n");
}

void main()
{
	int arr_int[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	print_arr(arr_int, SIZE);
}