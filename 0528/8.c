
// ��� ����
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;
Node* head;
Node* tail;
// ���� �ڷᱸ���� ���������� ���Ǵ� ���� ���� ���� ������ �������� �����Ƿ�
// �޸� ���� �߻��Ѵٴ� ������ �ֽ��ϴ�. �̸� �ذ��ϱ� ���� ������ �Լ��� �����մϴ�.

int listFinalize()
{
	if(head == NULL || tail == NULL)
	{
		fprintf(stderr, "listFinalize: list is wrong");
		return -1;
	}
	while(head->next != tail)
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
	while (cur->next != tail)	//cur->next��  ���̾ƴ�tail�� ������ �������ΰ��̴�.
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
	tail = malloc(sizeof(Node));
	if (tail == NULL)
	{
		perror("listInitialize");
		free(head);
		return -1;
	}
	head->next = tail;
	tail->next = tail;//���ѷ���
	return 0;
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