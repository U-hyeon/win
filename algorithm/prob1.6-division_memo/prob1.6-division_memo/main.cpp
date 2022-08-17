#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXN 200

int division(int n, int m) //Ư�� �ڿ���n�� m������ �ڿ������� �������� ǥ�������� ����� ��
{
	static int memo[MAXN][MAXN]; // �ѹ� ���� ���� ���
	
	if (n < m) m = n;

	if (memo[n][m] > 0) // ���� �����ϸ�
		return memo[n][m];
	if (m <= 1 || n <= 1) return memo[n][m] = 1; // 1������ ǥ���ϴ� ����� �� = 1����
	

	//m�� �����ϴ� ����� ��
	int a = 0;
	int div = n / m; //�ִ� m�� �ִ� ������� ��� �����Ѱ�
	for (int i = 1; i <= div; i++)
	{
		a += division(n - i * m, m - 1);
	}

	//m�� �������� �ʴ� ����� ��
	int b = division(n, m - 1);

	return memo[n][m] = a + b;
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