// 시계방향으로 1, 2, 3, ..., n이라고 할때, 
// 1번부터 시작하여 시계방향으로 한 사람을 살리고 그 다음 사람을 죽인다. 
// 이것을 한 사람이 남을 때까지 계속한다. 
// 시작 인원 수 n을 입력받아 최후에 남은 것이 누구인지 구하는 프로그램을 작성하라
#include <iostream>
#include "list.h"
using namespace std;
// idea : node를 이용하여 원형 큐를 작성한다. 이를 이용하여 중간에 인원이 빠지더라도 바로 다음 사람으로 연결한다.

void main()
{
	int n;
	cout << "Enter n (n >= 1): ";
	cin >> n;
	cout << "The remaining from " << n << " people : " << execute(n) << endl;
}