#include <stdio.h>

int square[4][4] = {
	{3, -3, -2, -1},
	{2, 6, -5, 1},
	{-3, -5, 2, 4},
	{2, 4, 0, -2}
};

int partial_sum[4][4][4][4];
//partial_sum [m_start][n_start][m_end][n_end]

int max_sum_naive()
{
	int m, n, m_start, n_start;
	int tmp, r = -999;

	//step 1 : 1칸짜리
	for (m_start = 0; m_start < 4; m_start++)
		for (n_start = 0; n_start < 4; n_start++)
			partial_sum[1][1][m_start][n_start] = square[m_start][n_start];

	//step 2 : n = 1
	for (m = 1; m <= 4; m++) //가로사이즈
		for (m_start = 0; m_start < 4 - m + 1; m_start++)
			for (n_start = 0; n_start < 4; n_start++)
			{
				partial_sum[m][1][m_start][n_start] = partial_sum[m - 1][1][m_start][n_start] + square[m_start + m][n_start];
			}

	//step 3 : n > 1
	for (m = 1; m <= 4; m++) //가로사이즈
		for (n = 2; n <= 4; n++) //세로사이즈
			for (m_start = 0; m_start < 4 - m + 1; m_start++)
				for (n_start = 0; n_start < 4 - n + 1; n_start++)
				{
					partial_sum[m][n][m_start][n_start] = partial_sum[m][n-1][m_start][n_start] + square[m_start][n_start + n];
				}

	//step 4 : find max
	for (m = 1; m <= 4; m++) //가로사이즈
		for (n = 2; n <= 4; n++) //세로사이즈
			for (m_start = 0; m_start < 4 - m + 1; m_start++)
				for (n_start = 0; n_start < 4 - n + 1; n_start++)
				{
					tmp = partial_sum[m][n][m_start][n_start];
					if (tmp > r) r = tmp;
				}

	return r;
}

void main()
{
	printf("%d\n", max_sum_naive());
}