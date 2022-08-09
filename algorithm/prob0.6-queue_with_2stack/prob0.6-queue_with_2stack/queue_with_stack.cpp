#include "queue_with_stack.h"

stack stack1;
stack stack2;

void enqueue(int n) //stack 2�� �̿��Ͽ� stack1�� ťó�� ����
{
	int i;
	
	for (;;)
	{
		i = stack1.pop();
		if (i == -1) break;
		stack2.push(i);
	}

	stack1.push(n);

	for (;;)
	{
		i = stack2.pop();
		if (i == -1) break;
		stack1.push(i);
	}
}

int dequeue()  //
{
	int r = stack1.pop();
	return r;
}

void display_queue()
{
	int i;
	for (i=0 ; i<stack1.e ; i++)
	{
		printf("[%d] ", stack1.stack[i]);
	}
	printf("\n");
}