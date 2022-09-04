#include <stdio.h>
#include <iostream>
using namespace std;

#define HEIGHT 5

int pyramid[HEIGHT][HEIGHT]; 
//�Ƕ�̵� �������� ���ϴ� ������������ ��� ����� �� Ž��
//�����ö����� {0}, {0,1}, {0,1,2},... ������ ��ĭ������
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