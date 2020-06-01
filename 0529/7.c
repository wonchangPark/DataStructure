// 0.c �ڵ带 ������ ������
#include <stdlib.h>
#include <stdio.h>

// ���� �ڷᱸ���� ������ Ž���� ��ƴٴ� ������ �ֽ��ϴ�. �̸� �ذ��ϱ� ����
// �ڷᱸ���� �����͸� ������ �ƴ� ���� ��带 ��Ű������ �����մϴ�.

// ��� ��尡 ���� ��带 ����Ű���� listReverse �Լ��� ������ ������ :D


typedef struct Node {
	int data;
	struct Node* next;
} Node;
Node* head;
Node* tail;

int listInitialize() {
	head = malloc(sizeof(Node));
	if (head == NULL) {
		perror("listInitialize");
		return -1;
	}

	tail = malloc(sizeof(Node));
	if (tail == NULL) {
		perror("listInitialize");
		free(head);
		return -1;
	}
	head->next = tail;
	tail->next = tail;
	return 0;
}

int listFinalize() {
	if (head == NULL || tail == NULL) {
		fprintf(stderr, "listFinalize: list is wrong\n");
		return -1;
	}

	while (head->next != tail) {
		Node* target = head->next;
		head->next = target->next;
		free(target);
	}

	free(head);
	free(tail);
	return 0;
}

int listAdd(int data) {
	Node* node = malloc(sizeof(Node));
	if (node == NULL) {
		perror("listAdd");
		return -1;
	}
	node->data = data;
	node->next = tail;

	Node* cur = head;
	while (cur->next != tail)
		cur = cur->next;
	cur->next = node;
	return 0;
}

void listDisplay() {
	system("cls");
	printf("[head]");
	for (Node* node = head->next; node != tail; node = node->next)
		printf("->[%2d]", node->data);
	printf("->[tail]");
	getchar();
}

void listReverse() {
	Node* prev = head;
	Node* cur = head->next;
	Node* next;

	while (cur != tail) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	cur->next = prev;
	// �̰� ������ tail�� ����Ű�°��� ���������� �ٲ������.
	// �̰� �ȵǾ������� tail���� ����ϴµ� �ڱ��ڽ��� ����Ű�� ������ ó������ ���ѷ����� ����.
}
void listDisplayBackwardly()
{
	system("cls");
	printf("[tail]");
	for (Node* node = tail->next; node != head; node = node->next)
		printf("->[%2d]", node->data);
	printf("->[head]");
	getchar();
	
}

int main() {
	listInitialize();

	listDisplay();
	for (int i = 0; i < 5; i++) {
		listAdd(i + 1);
		listDisplay();
	}

	listReverse();
	listDisplayBackwardly();
	
	//listFinalize();
	return 0;
}