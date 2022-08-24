#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3000

int find_reversal_naive(int A[], int n) // n=순열의 크기
{
	int cnt = 0;
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
			if (A[i] > A[j]) cnt++;
	}
	return cnt;
} // O(n^2) algorithm

int find_reversal_naive_2(int A[], int n) // n=순열의 크기
{
	int cnt = 0;
	int i, j;

	for (i = 1; i < n; i++) // i = distance
	{
		for (j = 0; j < n - i; j++) // j = start position 
			if (A[j] > A[j+i]) cnt++;
	}
	return cnt;
} // O(n^2) algorithm

int find_reversal_recursive(int A[], int start, int length)
{
	int cnt = 0;
	int i;
	/*
	if (start >= SIZE)
	{
		printf("Error!\n");
		exit(0);
	}
	*/
	if (length <= 1) return 0;

	for (i = 1; i < length; i++)
	{
		if ( A[start] > A[start + i] ) cnt++;
	}
	cnt += find_reversal_recursive(A, start + 1, length - 1);

	return cnt;
}

void init(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % SIZE + 1;
	}
}

void main()
{
	int arr[SIZE] = { };
	int tmp;
	double start, end, time;

	init(arr, SIZE);
	/*
	printf("arr\n ");
	for (int i = 0; i < SIZE; i++)
		printf("[%d] ", arr[i]);
	printf("\n");
	*/
	printf("Naive solution : \n");
	start = clock();
	tmp = find_reversal_naive(arr, SIZE);
	end = clock();
	time = end - start;
	printf("number of reversal : %d, time spend : %f\n", tmp, time);
	
	printf("Naive solution - distance : \n");
	start = clock();
	tmp = find_reversal_naive_2(arr, SIZE);
	end = clock();
	time = end - start;
	printf("number of reversal : %d, time spend : %f\n", tmp, time);

	printf("recursive solution : \n");
	start = clock();
	tmp = find_reversal_recursive(arr, 0, SIZE);
	end = clock();
	time = end - start;
	printf("number of reversal : %d, time spend : %f\n", tmp, time);
}