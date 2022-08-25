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

int execute(int n)
{
	int i;
	// n명의 원형큐를 작성
	for (i = 1; i <= n; i++)
	{
		insert_node(i);
	}
	tail->next = head;

	// execute
	node_t* current_node; // 살릴 노드
	node_t* next_node; // 죽일 노드
	current_node = head; // initialize
	next_node = current_node->next; // initialize

	for (i = 0; i < n; i++) // n명 중 n-1명을 죽이는 것이므로 루프의 횟수는 n-1번
	{
		printf("(%d, %d)\n", current_node->key, next_node->key);
		if (current_node == next_node)
		{
			return current_node->key; //원형 큐에서 현재노드 == 다음노드 인 경우는 남은 노드가 하나뿐이라는 것을 의미한다.
		}

		head = next_node;
		delete_node(); //함수 실행 후, 다음 current_node가 새로운 head가 된다.
		current_node = head; //전진
		next_node = current_node->next; //전진
	}

	printf("Error!\n");
	return -1;
}