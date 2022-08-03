#include <stdio.h>

void rotate_left(int A[], int start, int end); //start~end 왼쪽으로
void rotate_right(int A[], int start, int end); //start~end 왼쪽으로
void rotate_left_by_n(int A[], int start, int end, int n); //start~end 왼쪽으로 n만큼
void rotate_right_by_n(int A[], int start, int end, int n); //start~end 왼쪽으로 n만큼
void display_arr(int A[], int n);

void main()
{
	int A[9] = { 1,2,3,4,5,6,7,8,9 };
	display_arr( A, sizeof(A) / sizeof(int) );
	printf("-shift to left\n");
	rotate_left(A, 3, 7); 
	display_arr(A, sizeof(A) / sizeof(int));
	printf("-shift to right\n");
	rotate_right(A, 3, 7);
	display_arr(A, sizeof(A) / sizeof(int));
	printf("-shift to left by 3\n");
	rotate_left_by_n(A, 2, 7, 3);
	display_arr(A, sizeof(A) / sizeof(int));
	printf("-shift to right by 3\n");
	rotate_right_by_n(A, 2, 7, 3);
	display_arr(A, sizeof(A) / sizeof(int));
}

void display_arr(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void rotate_left(int A[], int start, int end) //start~end 왼쪽으로
{
	int tmp = A[start];
	for (int i = start; i < end; i++)
	{
		A[i] = A[i + 1];
	}
	A[end] = tmp;
}

void rotate_right(int A[], int start, int end) //start~end 왼쪽으로
{
	int tmp = A[end];
	for (int i = end; i > start; i--)
	{
		A[i] = A[i-1];
	}
	A[start] = tmp;
}

void rotate_left_by_n(int A[], int start, int end, int n) //start~end 왼쪽으로 n만큼
{
	int shift = n % (end - start); //n바퀴회전후 실질적인 이동수
	for (int i = 0; i < shift; i++) rotate_left(A, start, end);
}

void rotate_right_by_n(int A[], int start, int end, int n) //start~end 왼쪽으로 n만큼
{
	int shift = n % (end - start); //n바퀴회전후 실질적인 이동수
	for (int i = 0; i < shift; i++) rotate_right(A, start, end);
}