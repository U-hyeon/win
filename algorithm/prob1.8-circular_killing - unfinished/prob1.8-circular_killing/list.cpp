#include "list.h"

node_t* head = NULL, * tail = NULL;

void insert_node(int n) //n = ��尡 ������ Ű��
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

int execute(int n)
{
	int i;
	// n���� ����ť�� �ۼ�
	for (i = 1; i <= n; i++)
	{
		insert_node(i);
	}
	tail->next = head;

	// execute
	node_t* current_node; // �츱 ���
	node_t* next_node; // ���� ���
	current_node = head; // initialize
	next_node = current_node->next; // initialize

	for (i = 0; i < n; i++) // n�� �� n-1���� ���̴� ���̹Ƿ� ������ Ƚ���� n-1��
	{
		printf("(%d, %d)\n", current_node->key, next_node->key);
		if (current_node == next_node)
		{
			return current_node->key; //���� ť���� ������ == ������� �� ���� ���� ��尡 �ϳ����̶�� ���� �ǹ��Ѵ�.
		}

		head = next_node;
		delete_node(); //�Լ� ���� ��, ���� current_node�� ���ο� head�� �ȴ�.
		current_node = head; //����
		next_node = current_node->next; //����
	}

	printf("Error!\n");
	return -1;
}