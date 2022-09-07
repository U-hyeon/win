#include <stdio.h>

int cost(int p, int length[]) // p = �ڸ� ������ ��, length[] = �߸� ���� �������� ���̰� ������� ����Ǿ��ִ� (p = length������ �� - 1)
{
	int tmp, r=9999; // �ʱ� r = ����� ū ��
	int i,j;
	int length_before[100] = {}; //����� ũ���� �迭

	// IDEA : tree������ ���, bottom-up solution, �ѹ� �۾��� ������ �� node�� ��ġ�� ���������� 10

	// ���� status
	if (p == 0) return 0;

	// process
	for (i = 0; i < p; i++) // ������ ������ġ ����
	{
		for (j = 0; j < i; j++) 
			length_before[j] = length[j];
		
		length_before[i] = length[i] + length[i + 1]; //�ڸ��� �� ����
		
		for (j = i+1; j < p; j++)
			length_before[j] = length[j + 1]; // �迭 ����

		tmp = length_before[i] + cost(p - 1, length_before); // ���� ���ܺ�� + �� �������� ���� ���ܺ��
		
		if (tmp < r) r = tmp;
	}

	return r;
}

void main()
{
	int a[4] = { 2,2,3,3 };
	printf("%d\n", cost(3, a));
}