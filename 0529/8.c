// 0.c �ڵ带 ������ ������
#include <stdlib.h>
#include <stdio.h>

// ���� �ڷᱸ���� �ڿ� ������ ���������� ���� �ʴ´ٴ� ������ �ְ� �� �ٸ� ������
// �������� ���������� ����������, ���ó� ���������� �������� �ʴ´ٴ� ������ �ֽ��ϴ�.
// 
// �̸� �ذ��ϱ� ���� �÷��׿� ���� ����� ����� ���� ������ �̴� �ڷᱸ���� �����
// �ſ� �������ϰ� ����ٴ� ������ �ֽ��ϴ�.
//
// �̸� �ذ��ϱ� ���� ���� ������ �����մϴ�.


typedef struct Node {
	int data;
	struct Node* next;
} Node;
Node* head;
//Node* tail;

int listInitialize() {
	head = malloc(sizeof(Node));
	if (head == NULL) {
		perror("listInitialize");
		return -1;
	}

	head->next = head;
	return 0;
}

int listFinalize() {
	if (head == NULL ) {
		fprintf(stderr, "listFinalize: list is wrong\n");
		return -1;
	}

	while (head->next != head) {
		Node* target = head->next;
		head->next = target->next;
		free(target);
	}

	free(head);
	return 0;
}

// �������Ḯ��Ʈ�� �̿�
// �̷��� �ϸ� ������ �������� �ϳ��� ������ �ȴ�.
int listAdd(int data) {
	Node* node = malloc(sizeof(Node));
	if (node == NULL) {
		perror("listAdd");
		return -1;
	}
	node->data = data;
	node->next = head;

	Node* cur = head;
	while (cur->next != head)
		//tail�� �ƴ� head�� �ƴҶ� ���� �� ������ ���� �������� �ٽ� head�� ����Ű�Ƿ�
		//head�� ���� ���� �������ΰ��̴�.
		 //�̰��� �������Ḯ��Ʈ�̴�.	
		cur = cur->next;
	cur->next = node;
	return 0;
}

void listDisplay() {
	system("cls");
	printf("[head]");
	for (Node* node = head->next; node != head; node = node->next)
		printf("->[%2d]", node->data);
	printf("->[head]");
	getchar();
}

void listReverse() {
	Node* prev = head;
	Node* cur = head->next;
	Node* next;

	while (cur != head) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	cur->next = prev;	
}


int main() {
	listInitialize();

	listDisplay();
	for (int i = 0; i < 5; i++) {
		listAdd(i + 1);
		listDisplay();
	}

	listReverse();
	listDisplay();
	listReverse();
	listDisplay();
	
	listFinalize();
	return 0;
}