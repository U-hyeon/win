#pragma once
#pragma once
#include <stdio.h>
#include <iostream>
//using namespace std;

struct _node {
	int key;
	struct _node* next;
};

typedef struct _node node_t; //���� struct _node ���������� node_t ������������ ��ü����

//-----------definition of the list(node)

void insert_node(int n); //n = ��尡 ������ Ű��
int delete_node(); //delete the head of the list
int execute(int n); //main function