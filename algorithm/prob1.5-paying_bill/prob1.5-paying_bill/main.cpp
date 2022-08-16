#include <stdio.h>
#define money 100

int bills[6]{ 1,2,5,10,20,50 };
int i;

int solution(int target, int types)
{
	if (target < 5) return 1; // 1����¥���ιۿ� ������ �� ���� ��
	if (types == 1) return 1; // ��밡���� ���� 1������ ���� ���

	int r=0;
	int n = target / bills[types - 1]; //target�� ���� �ʴ� ������, �ִ������ ���� ����� ����� �� �ִ°�

	for (i = 0; i <= n; i++)
		r += solution(target - (i * bills[types - 1]), types - 1);
	
	return r;
}

void main()
{
	// Naive solution
	int count = 0, i0, i1, i2, i3, i4;

	for (i0 = money; i0 >= 0; i0 -= bills[0])
		for (i1 = i0; i1 >= 0; i1 -= bills[1])
			for (i2 = i1; i2 >= 0; i2 -= bills[2])
				for (i3 = i2; i3 >= 0; i3 -= bills[3])
					for (i4 = i3; i4 >= 0; i4 -= bills[4])
						if (i4 % bills[5] == 0)
							count++;

	printf("-Naive solution\ncount = %d\n", count);
	
	// Recursive solution
	printf("\n-Recursive solution\ncount = %d\n",solution(money, 6));
}