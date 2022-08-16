#include <stdio.h>
#define money 100

int bills[6]{ 1,2,5,10,20,50 };
int i;

int solution(int target, int types)
{
	if (target < 5) return 1; // 1만원짜리로밖에 지불할 수 없을 때
	if (types == 1) return 1; // 사용가능한 지폐가 1만원권 뿐일 경우

	int r=0;
	int n = target / bills[types - 1]; //target을 넘지 않는 선에서, 최대단위의 지폐를 몇개까지 사용할 수 있는가

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