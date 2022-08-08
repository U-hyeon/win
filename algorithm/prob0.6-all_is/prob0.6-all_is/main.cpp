#include <stdio.h>
#define SIZE 10

void print_arr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("[%d] ", arr[i]);
	}
	printf("\n");
}

int all_is(int arr[], int len, int k)
{
	int r=1;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] != k) r = 0;
	}

	return r;
}

void main()
{
	int arr_int1[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr_int2[SIZE] = { 3,3,3,3,3,3,3,3,3,3 };
	print_arr(arr_int1, SIZE);
	print_arr(arr_int2, SIZE);

	printf("--TRUE = 1, FALSE = 0\n");
	printf("arr2, 2 => [%d]\n", all_is(arr_int2, SIZE, 2));	
	printf("arr2, 3 => [%d]\n", all_is(arr_int2, SIZE, 3));

}