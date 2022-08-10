#include "queue_with_stack.h"

stack stack1;
stack stack2;

void enqueue(int n) //stack 2를 이용하여 stack1에 큐처럼 저장
{
	int i = stack1.e;
	
	for (;i>0;i--)
	{
		stack2.push(stack1.pop());
	}

	stack1.push(n);

	i = stack2.e;

	for (; i > 0; i--)
	{
		stack1.push(stack2.pop());
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