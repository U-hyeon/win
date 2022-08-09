#include "stack.h"

void stack::push(int n)
{
	if (e == n)
	{
		printf("stack is full!\n");
		return;
	}

	stack[e] = n;
	e++;
}

int stack::pop()
{
	int r;

	if (e < 1)
	{
		printf("stack is empty!\n");
		return -1;
	}

	e--;
	r = stack[e];
	return r;
}