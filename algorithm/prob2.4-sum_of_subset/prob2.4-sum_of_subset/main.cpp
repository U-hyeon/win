#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define SIZE 10

//int proper_subset[SIZE][SIZE];

int subset_sum_recursive(int subset[], int m, int n, int sum) // subset ���տ��� n���� ���Ҹ� ���� sum�� ����� ������ TRUE, �ƴϸ� FALSE
{
	if (m < n) return FALSE; // �����ؾ� �ϴ� ������ ������ ��ü������ ���� ���� => �� ���;��� FALSE
	if (sum < 0) return FALSE; // sum���� ��� �Ҹ��ߴ� => FALSE

	if (m == 0) // ��� ���Ҹ� �� Ȯ���Ͽ���
	{
		if (sum == 0) return TRUE; // sum���� ��ġ�Ѵ� => TRUE
		else return FALSE; // sum���� ��ġ���� �ʴ´� => FALSE
	}
	
	

	if (subset_sum_recursive(subset, m - 1, n, sum) == TRUE) // subset[m-1]�� �������� ���� ��쿡�� TRUE �߻� => TRUE
		return TRUE;
	else if (subset_sum_recursive(subset, m - 1, n - 1, sum - subset[m - 1]) == TRUE) // subset[m-1]�� �����ϴ� ��쿡�� TRUE �߻� => TRUE
		return TRUE;
	else 
		return FALSE;
}

void init(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = (rand() % 100) + 1;
}

void main()
{
	int arr[SIZE];
	int n, sum;

	init(arr, SIZE);

	cout << "Enter n, sum : ";
	cin >> n >> sum;
	
	for (int i = 0; i < SIZE; i++) cout << "[" << arr[i] << "] ";
	cout << endl;

	int tmp = subset_sum_recursive(arr, SIZE, n, sum);

	//����
	if (tmp == TRUE) cout << "possible!" << endl;
	else cout << "impossible!" << endl;
}