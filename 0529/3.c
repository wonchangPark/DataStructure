
// 노드 설계
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

	int data;
	struct Node* next;
}Node;
Node* head;
Node* tail;
int count;

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
	++count;
	return 0;
}
int listInsert(int index, int newData)
{
	if (count == 0)
	{
		fprintf(stderr, "listInsert: list is empty\n");
		return -1;
	}
	if (index < 0 || index >= count)
	{
		fprintf(stderr, "listInsert: out of index\n");
		return -1;
	}
	Node* prev = head;
	Node* node = malloc(sizeof(Node));
	if (node == NULL)
	{
		perror("listInsert");
		return -1;
	}
	node->data = newData;
	for (int i = 0; i < index; i++)
	{
		prev = prev->next;
	}
	node->next = prev->next;
	prev->next = node;
	++count;
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
	count = 0;
	return 0;
}

int listSet(int index, int newData, int* oldData)
{
	if (count == 0)
	{
		fprintf(stderr, "listSet: list is empty\n");
		return -1;
	}
	if (oldData == NULL)
	{
		fprintf(stderr, "listSet: oldData is empty\n");
		return -1;
	}
	if (index < 0 || index >= count)
	{
		fprintf(stderr, "listSet: out of index\n");
		return -1;
	}
	Node* node = head->next;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}
	*oldData = node->data;
	node->data = newData;
	return 0;

}

int listCount()
{
	return count;
}
int listGet(int index, int* dp)
{
	if (count == 0)
	{
		fprintf(stderr, "listGet: list is empty\n");
		return -1;
	}
	if (dp == NULL)
	{
		fprintf(stderr, "listGet: argument is null\n");
		return -1;
	}
	if (index < 0 || index >= count)
	{
		fprintf(stderr, "listGet: out of index\n");
		return -1;
	}
	Node* node = head->next;
	for (int i = 0; i < index; i++)
	{
		node->next;
	}
	*dp = node->data;
	return 0;
}
int listRemove(int index, int* dp)//dp는 제거하는 값을 사용자에게 리턴해주기 위하여
{
	if (count == 0)
	{
		fprintf(stderr, "listRemove: list is empty\n");
		return -1;
	}
	if (dp == NULL)
	{
		fprintf(stderr, "listRemove: argument is null\n");
		return -1;
	}
	if (index < 0 || index >= count)
	{
		fprintf(stderr, "listRemove: out of index\n");
		return -1;
	}
	Node* node = head->next;
	Node* prev = head;
	for(int i =0 ;i <index ; i++)
	{
		prev = node;
		node = node->next;
	}
	prev->next = node->next;
	*dp = node->data;
	free(node);
	--count;
	return 0;
}
int main()
{
	listInitialize();

	listDisplay();
	for (int i = 0; i < 5; i++)
	{
		listAdd(i + 1);
	}
	listDisplay();
	int data;
	listRemove(4, &data), listDisplay();
	
	listFinalize();
	return 0;
}