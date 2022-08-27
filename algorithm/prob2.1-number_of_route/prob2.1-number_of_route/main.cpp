#include <stdio.h>

int path[5][5] = {
	{1,1,1,1,0},
	{1,1,1,1,1},
	{1,1,1,1,1},
	{1,0,1,1,1},
	{1,1,1,1,1}
};

int route[5][5] = {};

int NofR(int arr[][5], int x, int y)
{
	int i, j;
	route[0][0] = 1;
	for (i = 0; i <= x; i++)
	{
		if (path[i][0] != 0) route[i][0] = 1;
		else route[i][0] = 0;
	}
	for (j = 0; j <= y; j++) 
	{
		if (path[0][j] != 0) route[0][j] = 1;
		else route[0][j] = 0;
	}
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

	return route[x][y];
}

void print_route(int arr[][5], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("[%d] ", arr[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int n = NofR(path, 4, 4);
	print_route(route, 5, 5);
	printf("number of path : %d", n);
}