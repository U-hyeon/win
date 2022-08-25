#pragma once
#pragma once
#include <stdio.h>
#include <iostream>
//using namespace std;

struct _node {
	int key;
	struct _node* next;
};

typedef struct _node node_t; //이후 struct _node 변수선언을 node_t 변수선언으로 대체가능

//-----------definition of the list(node)

void insert_node(int n); //n = 노드가 가지는 키값
int delete_node(); //delete the head of the list
int execute(int n); //main function