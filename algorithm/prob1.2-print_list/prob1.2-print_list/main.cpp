#define _CRT_SECURE_NO_WARNINGS //scanf error 방지
#include "list.h"


node_t* head = NULL, * tail = NULL;

void insert_node(int n) //n = 노드가 가지는 키값
{
	node_t* new_node = (node_t*)malloc(sizeof(node_t)); //create new node

	new_node->key = n; //designate key
	new_node->next = NULL; //there isn't any following nodes
	if (head == NULL) //if there is nothing on the list
	{
		head = new_node;
		tail = new_node;
	}
	else //if there are any nodes on the list
	{
		tail->next = new_node;
		tail = new_node; //insert new_node into last of the list
	}
}

int delete_node() //delete the head of the list
{
	node_t* node;
	int r;

	if (head == NULL)
	{
		return -1;
	} //error check. 

	node = head;
	head = head->next; //designate new head
	if (head == NULL)
		tail = NULL; //it there is nothing left on the list

	r = node->key; //load key value to return 
	free(node); //memory
	return r; //return the key value of the node
}

void enqueue(int n)
{
	insert_node(n);
	//printf("insertion complete!\n");

	node_t* node;
	node = head;
	/*
		do {
			printf("[%d] ", node->key);
			node = node->next;
		} while (node != NULL);
		printf("\n");*/
}

void dequeue()
{
	int tmp = delete_node();
	if (tmp == -1)
		printf("empty list!\n");
	else
		printf("return [%d]\n", tmp);
}

void print_list(node_t* from)
{
	if (from == NULL)
	{
		printf("\n");
		return;
	}
	printf("[%d] ", from->key);

	print_list(from->next);
}

void print_list_reverse(node_t* from)
{
	if (from == NULL)
	{
		return;
	}
	print_list_reverse(from->next);
	
	printf("[%d] ", from->key);
}

void main()
{
	dequeue();

	int input;
	printf("input insertion : ");
	scanf("%d", &input);
	insert_node(input);

	input;
	printf("input insertion : ");
	scanf("%d", &input);
	insert_node(input);

	input;
	printf("input insertion : ");
	scanf("%d", &input);
	insert_node(input);

	input;
	printf("input insertion : ");
	scanf("%d", &input);
	insert_node(input);

	dequeue();

	input;
	printf("input insertion : ");
	scanf("%d", &input);
	insert_node(input);

	input;
	printf("input insertion : ");
	scanf("%d", &input);
	insert_node(input);

	input;
	printf("input insertion : ");
	scanf("%d", &input);
	insert_node(input);

	dequeue();
	dequeue();
	dequeue();

	//print_list(head);
	print_list_reverse(head);
}

