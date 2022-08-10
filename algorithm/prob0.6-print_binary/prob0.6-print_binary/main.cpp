#include <stdio.h>
#define BUF_SIZE 10

int binary_1(int n)
{
	int tmp = n;
	int i, r = 0;
	for (i = 0; tmp != 0; )
	{
		i = tmp % 2; //2·Î ³ª´« ³ª¸ÓÁö
		tmp = tmp / 2; //2·Î ³ª´« ÇØ
		if (i == 1) r++;
	}
	return r;
}

void print_binary(int n)
{
	int bi[BUF_SIZE];
	int tmp = n;
	int i,cnt=0;
	for (i = 0; tmp != 0; )
	{
		i = tmp % 2; //2·Î ³ª´« ³ª¸ÓÁö
		tmp = tmp / 2; //2·Î ³ª´« ÇØ
		bi[cnt] = i;
		cnt++;
	}

	printf("%d = ", n);
	while (cnt > 0)
	{
		cnt--;
		printf("%d", bi[cnt]);
	}
	printf("(binary)\n");
}

void main()
{
	int a = 37;
	int b = 15;

	print_binary(a);
	printf("37 => %d\n", binary_1(a));
	print_binary(b);
	printf("15 => %d\n", binary_1(b));
}