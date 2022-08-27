#include <stdio.h>
#include <iostream>
using namespace std;

int path[5][5] = {
	{1,1,1,1,1},
	{1,1,0,0,1},
	{1,1,1,1,1},
	{1,1,1,0,1},
	{0,0,1,1,1}
};

int route[5][5] = {};

int NofR(int arr[][5], int m , int n)
{
	int i, j;
	route[0][0] = 1;
	
	//가장자리
	for (i = 1; i < m ; i++)
	{
		if (path[i][0] != 0) route[i][0] = route[i - 1][0];
		else route[i][0] = 0;
	}
	for (j = 1; j < n; j++)
	{
		if (path[0][j] != 0) route[0][j] = route[0][j - 1];
		else route[0][j] = 0;
	}
	
	//내부
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 5; j++)
		{
			if (arr[i][j] == 0)
				route[i][j] = 0;
			else
				route[i][j] = route[i - 1][j] + route[i][j - 1];
		}
	}

	return route[m -1][n-1];
}

void print_route(int arr[][5], int m , int n)
{
	for (int i = 0; i < m ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("[%d] ", arr[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int m , n;
	cout << "Enter m , n : ";
	cin >> m  >> n;

	printf("Map : \n");
	print_route(path, m , n);
	printf("\n");

	printf("route : \n");
	int r = NofR(path, m , n);
	print_route(route, m , n);
	printf("\nnumber of path : %d\n", r);
}