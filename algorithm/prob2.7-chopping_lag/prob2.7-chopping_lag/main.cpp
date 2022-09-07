#include <stdio.h>

int cost(int p, int length[]) // p = 자를 지점의 수, length[] = 잘린 이후 조각들의 길이가 순서대로 저장되어있다 (p = length원소의 수 - 1)
{
	int tmp, r=9999; // 초기 r = 충분히 큰 값
	int i,j;
	int length_before[100] = {}; //충분한 크기의 배열

	// IDEA : tree형태의 비용, bottom-up solution, 한번 작업에 인접한 두 node를 합치며 최종적으로 10

	// 최초 status
	if (p == 0) return 0;

	// process
	for (i = 0; i < p; i++) // 직전의 절단위치 결정
	{
		for (j = 0; j < i; j++) 
			length_before[j] = length[j];
		
		length_before[i] = length[i] + length[i + 1]; //자르기 전 길이
		
		for (j = i+1; j < p; j++)
			length_before[j] = length[j + 1]; // 배열 당기기

		tmp = length_before[i] + cost(p - 1, length_before); // 직전 절단비용 + 그 전까지의 누적 절단비용
		
		if (tmp < r) r = tmp;
	}

	return r;
}

void main()
{
	int a[4] = { 2,2,3,3 };
	printf("%d\n", cost(3, a));
}