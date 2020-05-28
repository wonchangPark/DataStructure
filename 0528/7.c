
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
	while (cur->next != tail)	//cur->next가  널이아닌tail을 만나야 마지막인것이다.
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
	// 이전 자료구조는 마지막 노드를 식별하기 위해 널을 사용하고 있습니다. 이는 잠재적으로 널 참조가 발생할 위험이 있습니다.
	// 이를 해결하기 위해 더미 테일을 도입합니다.멀티스레드에서는 매우효과적입니다. 왜냐하면 프로세스가 죽지 않기때문에 디버깅을 하기좋습니다.
	tail = malloc(sizeof(Node));
	if (tail == NULL)
	{
		perror("listInitialize");
		free(head);
		return -1;
	}
	head->next = tail;
	tail->next = tail;//무한루프
	return 0;
}

int main()
{
	//더미헤드를 추가합니다.
	listInitialize();
	



	listDisplay();
	for (int i = 0; i < 5; i++)
	{
		listAdd(i + 1);
		listDisplay();
	}
	return 0;
}