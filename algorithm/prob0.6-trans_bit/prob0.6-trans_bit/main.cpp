#include <stdio.h>

int binary_1(int n)
{
	int tmp = n;
	int i, r=0;
	for (i=0; tmp != 0; )
	{
		i = tmp % 2; //2·Î ³ª´« ³ª¸ÓÁö
		tmp = tmp / 2; //2·Î ³ª´« ÇØ
		if (i == 1) r++;
	}
	return r;
}

void main()
{
	int a = 37;
	int b = 15;

	printf("37 => %d\n", binary_1(a));
	printf("15 => %d\n", binary_1(b));
}