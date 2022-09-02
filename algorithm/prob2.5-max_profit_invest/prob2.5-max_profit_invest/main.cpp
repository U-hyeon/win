#include <iostream>
using namespace std;

#define MAX_INVEST 4 // 한 회사에 최대로 투자가능한 금액
#define N_COMPANY 3

#define MAXN 100
#define MAXM 100

int profit[MAX_INVEST + 1][N_COMPANY] = {
	{0,0,0},
	{2,3,1},
	{4,5,3},
	{6,6,7},
	{9,8,9}
};

int invest[N_COMPANY];

int profit_algorithm_recursive(int c, int sum) // c = number of company, sum = sum of invests
{
	int r = 0;
	int tmp, i, j;
	
	if (c == 1)
	{
		if (sum > MAX_INVEST) return -999; // 여유자금이 생기는 경우는 채택하지 않는다.
		else return profit[sum][0];
	}

	for (i = 1; i <= MAX_INVEST && i <= sum; i++)
	{
		tmp = profit[i][c-1] + profit_algorithm_recursive(c - 1, sum - i);
		if (tmp > r) r = tmp;
	}

	return r;
}

//solution
int r[MAXN][MAXM];
int max_return[MAXN][MAXM];
void calculate_return(int n, int m)
{
	int i, j, k, max, t;

	for (i = 0; i <= m; i++)
		max_return[0][i] = r[0][i];
	for(i=1;i<=n;i++)
		for (j = 1; j <= m; j++)
		{
			max = -1;
			for (k = 0; k <= j; k++)
			{
				t = max_return[i - 1][k] + r[i][j - k];
				if (t > max) max = t;
			}
			max_return[i][j] = max;
		}
}

void main()
{
	cout << profit_algorithm_recursive(3, 4) << endl;

	//solution
	
	int m, n, i, j;
	cin >> m >> n;
	for (i = 0; i < n; i++) r[i][0] = 0;
	for (i = 1; i <= m; i++)
		for (j = 0; j < n; j++)
		{
			r[j][i] = rand() % 10 + 1;
			//cin >> r[j][i];
		}
	calculate_return(n - 1, m);
	cout << "Max return: " << max_return[n - 1][m] << endl;


}
