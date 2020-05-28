
// ��� ����
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int count;
	int data;
	struct Node* next;
}Node;
Node* head;	//head �����ʹ� �׻� ó�� ��常�� �����Ѿ� �Ѵ�. �̰��� �����ϸ� �� ������ ���鿡�� �� ���� ���� ���� ���� current node�� ����Ű�� �����͸� �����. 

// �����͸� �������� �߰��ϴ� listAdd �Լ��� ������ ������ :D
int listAdd(int data)
{
	Node* node = malloc(sizeof(Node));
	if(node == NULL)
	{
		perror("listAdd");
		return -1;
	}
	
	node->data = data;
	node->next = NULL;

	//���Ḯ��Ʈ�� ����ִ°��
	if(head == NULL)
	{
		head = node;	//head���ٰ� ������ ������� node�� �ּҸ� �ֹǷ� head�� node�� �ȴ�. node�� ����Ű���� ����Ų��.
		return 0;
	}

	//���Ḯ��Ʈ�� ������� ���� ���
	Node* cur = head;	//�ӽ� cur ��带 ������ head�� ���� �־��ش�.
	while(cur->next != NULL)//cur�� next�� null���� Ȯ�� �ϰ� null �� �ƴ� ��쿡�� 
	{
		cur = cur->next;// cur�� next�� ����Ű�� �ּҸ� cur�� �ִ´� �� ������尡 cur�� �ȴ�.
	}
	//while���� �ٵ��� ���� cur->next�� NULL�̶�� ���̹Ƿ� ���� ������� ������ ���� �Դٴ°��� �ǹ��Ѵ�.
	cur->next = node;//���� cur�� ����Ű�� ����� next���ٰ� ���� ���� node�� �ּҸ� �־��ش�.
	return 0;
}

void listDisplay()
{
	system("cls");
	printf("[head]");
	for(Node* node = head; node != NULL; node = node->next)
	{
		printf("->[%2d]", node->data);
		getchar();
	}
}

int main()
{
	listDisplay();
	for(int i =0 ; i<5;i++)
	{
		listAdd(i + 1);
		listDisplay();
	}
	return 0;
}