#include <stdio.h>
#include <iostream>
using namespace std;

#define HEIGHT 5

int pyramid[HEIGHT][HEIGHT]; 
//피라미드 정점에서 최하단 까지내려오는 모든 경로의 수 탐색
//내려올때마다 {0}, {0,1}, {0,1,2},... 식으로 한칸씩증가
//

int routes(int h, int n)
{
	if (h < n) return 0;
	if (h == 0 || n == 0 || n == h) return 1; // (line 1) or (left edge) or (right edge)

	return routes(h - 1, n - 1) + routes(h - 1, n);
}

int routes_to_line(int h)
{
	int r = 0;
	for (int i = 0; i <= h; i++) r += routes(h, i);
	return r;
}

void main()
{
	for (int i = 0; i <= HEIGHT; i++)
	{
		for (int j = 0; j < HEIGHT - i; j++) cout << "  ";

		for (int j = 0; j <= i; j++)
		{
			printf("[%d] ", routes(i, j));
		}
		cout << endl;
	}

	cout << "all routes : " << routes_to_line(HEIGHT) << endl;
}