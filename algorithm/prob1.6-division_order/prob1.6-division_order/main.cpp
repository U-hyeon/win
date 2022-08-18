#include <stdio.h>
#include <iostream>
using namespace std;

int division_order(int n, int m) //Ư�� �ڿ���n�� m������ �ڿ������� �������� ǥ�������� ����� ��
{
	if (n < m) m = n;
	if (m <= 1 || n <= 1) return 1; // 1������ ǥ���ϴ� ����� �� = 1����

	//m�� �����ϴ� ����� ��
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