#include <stdio.h>
#include <iostream>
using namespace std;

int division_order(int n, int m) //특정 자연수n을 m이하의 자연수들의 조합으로 표현가능한 방법의 수
{
	if (n < m) m = n;
	if (m <= 1 || n <= 1) return 1; // 1만으로 표현하는 경우의 수 = 1가지

	//m을 포함하는 경우의 수
	int r=0;

	for (int i = 1; i <= m; i++)
	{
		r += division_order(n - i, m);
	}

	return r;
}

void main()
{
	int n, m;
	cout << "enter integer n : ";
	cin >> n;
	cout << "enter integer m : ";
	cin >> m;

	int result = division_order(n, m);

	cout << "division(" << n << ", " << m << ") = " << result;
}