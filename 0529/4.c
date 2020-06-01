
// 노드 설계
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

	int data;
	struct Node* next;
}Node;
// 함수내의 전역 심볼을 지역심볼로 바꿔야한다.
//Node* head;
//Node* tail;
//int count;
typedef struct List
{
	Node* head, * tail;
	int count;
}List;
int listFinalize(List* list)
{
	if(list == NULL)
	{
		fprintf(stderr, "listFinalize: argument is null\n");
		return -1;
	}
	Node* head = list->head;
	Node* tail = list->tail;
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

int listAdd(List* list,int data)
{
	if (list == NULL)
	{
		fprintf(stderr, "listAdd: argument is null\n");
		return -1;
	}
	Node* head = list->head;
	Node* tail = list->tail;
	
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
	++(list->count);
	return 0;
}
int listInsert(List* list,int index, int newData)
{
	if (list->count == 0)
	{
		fprintf(stderr, "listInsert: list is empty\n");
		return -1;
	}
	if (index < 0 || index >= list->count)
	{
		fprintf(stderr, "listInsert: out of index\n");
		return -1;
	}
	Node* prev = list->head;
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
	++(list->count);
	return 0;

}
int listDisplay(List* list)
{
	if (list == NULL)
	{
		fprintf(stderr, "listDisplay: argument is null\n");
		return -1;
	}
	system("cls");
	printf("[head]");
	
	for (Node* node = list->head->next; node != list->tail; node = node->next)
	{
		printf("->[%2d]", node->data);
	}
	printf("->[tail]");
	getchar();
	return 0;
}
int listInitialize(List* list)
{
	if (list == NULL)
	{
		fprintf(stderr, "listFinalize: argument is null\n");
		return -1;
	}
	Node* head = calloc(1, sizeof(Node)); //head = malloc(sizeof(Node));
												//head->next = NULL;
	if (head == NULL)
	{
		perror("listInitialize");
		return -1;
	}
	Node* tail = malloc(sizeof(Node));
	if (tail == NULL)
	{
		perror("listInitialize");
		free(head);
		return -1;
	}
	head->next = tail;
	tail->next = tail;//무한루프
	list->head = head;
	list->tail = tail;
	list->count = 0;
	return 0;
}

int listSet(List* list, int index, int newData, int* oldData)
{
	if (list == NULL)
	{
		fprintf(stderr, "listSet: argument is null\n");
		return -1;
	}
	if (list->count == 0)
	{
		fprintf(stderr, "listSet: list is empty\n");
		return -1;
	}
	if (oldData == NULL)
	{
		fprintf(stderr, "listSet: oldData is empty\n");
		return -1;
	}
	if (index < 0 || index >= list->count)
	{
		fprintf(stderr, "listSet: out of index\n");
		return -1;
	}
	Node* node = list->head->next;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}
	*oldData = node->data;
	node->data = newData;
	return 0;

}

int listCount(List* list)
{
	return list->count;
}
int listGet(List* list, int index, int* dp)	//여기가 문제
{
	if (list->count == 0)
	{
		fprintf(stderr, "listGet: list is empty\n");
		return -1;
	}
	if (dp == NULL)
	{
		fprintf(stderr, "listGet: argument is null\n");
		return -1;
	}
	if (index < 0 || index >= list->count)
	{
		fprintf(stderr, "listGet: out of index\n");
		return -1;
	}
	Node* node = list->head->next;
	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}
	*dp = node->data;
	return 0;
}
int listRemove(List* list,int index, int* dp)//dp는 제거하는 값을 사용자에게 리턴해주기 위하여
{
	if (list->count == 0)
	{
		fprintf(stderr, "listRemove: list is empty\n");
		return -1;
	}
	if (dp == NULL)
	{
		fprintf(stderr, "listRemove: argument is null\n");
		return -1;
	}
	if (index < 0 || index >= list->count)
	{
		fprintf(stderr, "listRemove: out of index\n");
		return -1;
	}
	Node* node = list->head->next;
	Node* prev = list->head;
	for (int i = 0; i < index; i++)
	{
		prev = node;
		node = node->next;
	}
	prev->next = node->next;
	*dp = node->data;
	free(node);
	--(list->count);
	return 0;
}
int main()
{
	List list;
	listInitialize(&list);
	for(int i=0 ;i<5; i++)
	{
		listAdd( &list,i + 1);
	}
	listDisplay(&list);
	for(int i=0; i<listCount(&list); i++)
	{
		int data;
		listSet(&list, i,0, &data);
		listDisplay(&list);
	}
	listInsert(&list,3, 22);
	listDisplay(&list);
	for(int i =0 ;i<listCount(&list); i++)
	{
		int data;
		listGet(&list, i, &data);
		printf("%d\n", data);
	}
	int data;
	listRemove(&list, 3, &data);
	listDisplay(&list);
	listFinalize(&list);
	return 0;
}