#pragma once
#include <stdio.h>
#define STACK_SIZE 10

struct stack {
	int stack[STACK_SIZE];
	int e=0; //number of elements in the stack
	
	void push(int n);
	int pop();
};
