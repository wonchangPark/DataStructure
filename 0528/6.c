
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
// ���� �ڷᱸ���� ���� �˰����� �̿�ȭ�Ǿ� �ִٴ� ������ �ֽ��ϴ�.
// �̸� �ذ� �ϱ� ���� ���� ��带 �����մϴ�.
// �̿�ȭ��� ������ listAdd���� �ϳ��� ������ �ΰ��� ������ ���´ٴ� ���Դϴ�.
// ���� ó���� �ƹ���尡 �������� head�� ����Ű�� �ƹ��ǹ̾��� ����� ���� ��带 ���� �װ��� ����ŵ�ϴ�.
// ���� ��尡�������� �Ȱ��� ������ �ϰ� �ؼ� �ϳ��� ������ �ϼ���ŵ�ϴ�.
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

int listInitialize()
{
	head = calloc(1, sizeof(Node)); //head = malloc(sizeof(Node));
												//head->next = NULL;
												
	if(head == NULL)
	{
		perror("listInitialize");
		return -1;
	}
	return 0;
}

int main()
{
	//������带 �߰��մϴ�.
	listInitialize();
	//���� �ڷᱸ���� ������ �ڷᱸ���� �ʱ�ȭ�� ����ڰ� �ؾ� �Ѵٴ� ������ �ֽ��ϴ�.
	//�̸� �ذ��ϱ� ���� �ڷᱸ���� �ʱ�ȭ�ϴ� �Լ��� �����ϵ��� �մϴ�.
	


	listDisplay();
	for (int i = 0; i < 5; i++)
	{
		listAdd(i + 1);
		listDisplay();
	}
	return 0;
}