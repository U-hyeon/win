#include <stdio.h>
#include <iostream>
using namespace std;

int division(int n, int m) //특정 자연수n을 m이하의 자연수들의 조합으로 표현가능한 방법의 수
{
	if (m == 1 || n == 1) return 1; // 1만으로 표현하는 경우의 수 = 1가지
	
	//m을 포함하는 경우의 수
	int a=0;
	int div = n / m; //최대 m을 최대 몇번까지 사용 가능한가
	for (int i = 1; i <= div; i++)
	{
		a += division(n - i*m, m - 1);
	}
	
	//m을 포함하지 않는 경우의 수
	int b = division(n, m - 1);

	return a + b;
}

void main()
{
	int n, m;
	cout << "enter integer n : ";
	cin >> n;
	cout << "enter integer m : ";
	cin >> m;

	int result = division(n, m);

	cout << "division(" << n << ", " << m << ") = " << result;
}