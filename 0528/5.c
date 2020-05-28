
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
// 이전 자료구조는 삽입 알고리즘이 이원화되어 있다는 단점이 있습니다.
// 이를 해결 하기 위해 더미 헤드를 삽입합니다.
// 이원화라는 이유는 listAdd에서 하나의 주제가 두개의 식으로 나온다는 것입니다.
// 따라서 처음에 아무노드가 없을때도 head가 가리키는 아무의미없는 노드인 더미 헤드를 만들어서 그것을 가리킵니다.
// 따라서 노드가있을때랑 똑같은 동작을 하게 해서 하나의 식으로 완성시킵니다.
int listAdd(int data)
{
	Node* node = malloc(sizeof(Node));
	if (node == NULL)
	{
		perror("listAdd");
		return -1;
	}

	node->data = data;
	node->next = NULL;

	
	Node* cur = head;	
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
	return 0;
}

void listDisplay()
{
	system("cls");
	printf("[head]");
	for (Node* node = head->next; node != NULL; node = node->next)
	{
		printf("->[%2d]", node->data);
	}
	getchar();
}

int main()
{
	//더미헤드를 추가합니다.
	head = malloc(sizeof(Node));
	head->next = NULL;
	
	
	
	listDisplay();
	for (int i = 0; i < 5; i++)
	{
		listAdd(i + 1);
		listDisplay();
	}
	return 0;
}