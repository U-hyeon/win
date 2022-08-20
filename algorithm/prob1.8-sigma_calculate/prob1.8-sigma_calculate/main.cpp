#include <iostream>
#include <math.h>
using namespace std;

int sigma_naive(int n, int k)
{
	int r=0;
	
	for (int i = 1; i <= n; i++)
	{
		r += pow(i,k);
	}

	return r;
}

int sigma(int n, int k)
{
	if (n == 1) return 1;
	int r = 0;
	r = sigma(n-1, k) + pow(n, k);
}

void main()
{
	int n, k;
	cin >> n >> k;
	cout << "n = " << n << ", k = " << k << " : " << sigma(n, k) << endl;
}