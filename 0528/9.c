
// 노드 설계
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int count;
	int data;
	struct Node* next;
}Node;
Node* head;
Node* tail;


int listFinalize()
{
	if (head == NULL || tail == NULL)
	{
		fprintf(stderr, "listFinalize: list is wrong");
		return -1;
	}
	while (head->next != tail)
	{
		Node* temp = (head->next->next);
		free(head->next);
		head->next = temp;
	}
	free(head);
	free(tail);
	return 0;

}

int listAdd(int data)
{
	Node* node = malloc(sizeof(Node));
	if (node == NULL)
	{
		perror("listAdd");
		return -1;
	}
	node->data = data;
	node->next = tail;
	Node* cur = head;
	while (cur->next != tail)	
	{
		cur = cur->next;
	}
	cur->next = node;
	++(tail->count);
	return 0;
}

void listDisplay()
{
	system("cls");
	printf("[head]");

	for (Node* node = head->next; node != tail; node = node->next)
	{
		printf("->[%2d]", node->data);
	}
	printf("->[tail]");
	getchar();
}
int listInitialize()
{
	head = calloc(1, sizeof(Node)); //head = malloc(sizeof(Node));
												//head->next = NULL;
	if (head == NULL)
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
	head->next = tail;
	tail->next = tail;//무한루프
	tail->count = 0;
	return 0;
}

// 아래의 함수를 구현해 보세요 :D
int listSet(int index, int newData, int* oldData)
{
	if(index >= tail->count )
	{
		perror("listSet: index is wrong");
	}
	if(head == NULL)
	{
		perror("listSet: head is null");
		return -1;
	}
	Node* node = head->next;
	for(int i =0 ;i<index; i++)
	{
		node = node->next;
	}
	
}

int main()
{
	listInitialize();

	listDisplay();
	for (int i = 0; i < 5; i++)
	{
		listAdd(i + 1);
		listDisplay();
	}
	listFinalize();

	listInitialize();
	listDisplay();
	return 0;
}