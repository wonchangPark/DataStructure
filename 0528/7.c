
// ��� ����
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
	// ���� �ڷᱸ���� ������ ��带 �ĺ��ϱ� ���� ���� ����ϰ� �ֽ��ϴ�. �̴� ���������� �� ������ �߻��� ������ �ֽ��ϴ�.
	// �̸� �ذ��ϱ� ���� ���� ������ �����մϴ�.��Ƽ�����忡���� �ſ�ȿ�����Դϴ�. �ֳ��ϸ� ���μ����� ���� �ʱ⶧���� ������� �ϱ������ϴ�.
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
	//������带 �߰��մϴ�.
	listInitialize();
	



	listDisplay();
	for (int i = 0; i < 5; i++)
	{
		listAdd(i + 1);
		listDisplay();
	}
	return 0;
}