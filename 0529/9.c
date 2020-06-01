
// 이중 연결 리스트
#include<stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;
Node* head;
Node* tail;
int count;
int listInitialize()
{

	head = malloc(sizeof(Node));
	if(head == NULL)
	{
		perror("listInitialize");
		return -1;
	}
	tail = malloc(sizeof(Node));
	if (tail == NULL)
	{
		perror("listInitialize");
		free(head);
		return -1;
	}

	head->prev = head;
	head->next = tail;

	tail->prev = head;
	tail->next = tail;

	return 0;
}

int listAdd(int data)
{
	Node* node = malloc(sizeof(Node));
	if(node == NULL)
	{
		perror("listAdd");
		return -1;
	}
	node->data = data;
	Node* cur = head;
	while(cur->next != tail)
	{
		cur = cur->next;
	}
	cur->next = node;
	node->prev = cur;
	node->next = tail;
	count++;
	
	return 0;
}
int listUpdate(int index,int newData, int* oldData)
{
	Node* node = head->next;
	for(int i =0 ; i<index; i++)
	{
		node = node->next;
	}
	*oldData = node->data;
	node->data = newData;
	return 0;
}

int listInsert(int index, int data)
{
	Node* node = malloc(sizeof(Node));
	node->next = head->next;
	node->data = data;
	for(int i=0; i<index; i++)
	{
		node = node->next;
	}
}

int main()
{
	listInitialize();

	// 1. 추가
	// 2. 수정
	// 3. 삽입
	// 4. 읽기
	// 5. 제거
}