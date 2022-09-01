#include <iostream>
using namespace std;

#define MAX_INVEST 4 // 한 회사에 최대로 투자가능한 금액
#define N_COMPANY 3

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

void main()
{
	cout << profit_algorithm_recursive(3, 4) << endl;
}
