#include <stdio.h>
#include <iostream>
using namespace std;

int division(int n, int m) //Ư�� �ڿ���n�� m������ �ڿ������� �������� ǥ�������� ����� ��
{
	if (m == 1 || n == 1) return 1; // 1������ ǥ���ϴ� ����� �� = 1����
	
	//m�� �����ϴ� ����� ��
	int a=0;
	int div = n / m; //�ִ� m�� �ִ� ������� ��� �����Ѱ�
	for (int i = 1; i <= div; i++)
	{
		a += division(n - i*m, m - 1);
	}
	
	//m�� �������� �ʴ� ����� ��
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