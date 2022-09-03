#include <stdio.h>
//최대 연속부분수열의 합
int max_consqcutive_sum(int s[], int n) 
{
	int i, j, k, sum, max_sum = s[0];

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			sum = 0;
			for (k = i; k <= j;k++)
			{
				sum += s[k];
			}
			if (sum > max_sum) max_sum = sum;
		}
	}
	return max_sum;
}

int max_consecutive_sum2(int s[], int n)
{
	int i, j, sum, max_sum = s[0];

	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = i; j < n; j++)
		{
			sum += s[j];
			if (sum > max_sum) max_sum = sum;
		}
	}
	return max_sum;
}

void main()
{

}