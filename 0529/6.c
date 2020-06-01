#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

// ���� �ڷᱸ���� ���� ����Ʈ �ȿ� ����� �������� ������ �� �� �����ϴ�. ������
// ���������� ���� �Ҵ�� �ڿ��� ���� ���, �޸� ������ �߻��� �� �ֽ��ϴ�.
// �̸� �ذ��ϱ� ���� ����� �����͸� ����ڿ��� �����Ͽ� ����ڰ� �ڿ��� �����ϵ���
// �ڵ带 �����մϴ�.

// �ڿ� ������ ���� �ݹ� �Լ� Ÿ���� �����մϴ�.
typedef void(FreeFunction)(void* ptr);

typedef struct Node {
	void* data;
	struct Node* next;
} Node;

typedef struct List {
	Node* head, * tail;
	int count;
	FreeFunction* freeFn;
} List;

int listInitialize(List* list, FreeFunction fn) {
	if (list == NULL) {
		fprintf(stderr, "listInitialize: argument is null\n");
		return -1;
	}

	Node* head = malloc(sizeof(Node));
	if (head == NULL) {
		perror("listInitialize");
		return -1;
	}

	Node* tail = malloc(sizeof(Node));
	if (tail == NULL) {
		perror("listInitialize");
		free(head);
		return -1;
	}

	head->next = tail;
	tail->next = tail;

	list->head = head;
	list->tail = tail;
	list->count = 0;
	list->freeFn = fn;

	return 0;
}

int listFinalize(List* list) {
	if (list == NULL) {
		fprintf(stderr, "listFinalize: argument is null\n");
		return -1;
	}

	Node* head = list->head;
	Node* tail = list->tail;

	if (head == NULL || tail == NULL) {
		fprintf(stderr, "listFinalize: list is wrong\n");
		return -1;
	}

	while (head->next != tail) {
		Node* target = head->next;
		head->next = target->next;

		if (list->freeFn)
			list->freeFn(target);

		free(target);
	}

	free(head);
	free(tail);
	return 0;
}

int listAdd(List* list, void* data) {
	if (list == NULL) {
		fprintf(stderr, "listAdd: argument is null\n");
		return -1;
	}

	Node* head = list->head;
	Node* tail = list->tail;

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
	list->count++;
	return 0;
}

void listDisplay(const List* list, const char* (toString)(const void*)) {
	if (list == NULL || toString == NULL) {
		fprintf(stderr, "listDisplay: argument is null\n");
		return;
	}
	Node* head = list->head;
	Node* tail = list->tail;

	system("cls");
	printf("[head]");
	for (Node* node = head->next; node != tail; node = node->next)
		printf("->[%s]", toString(node->data));
	printf("->[tail]");
	getchar();
}

void* listSet(List* list, int index, void* newData) {
	if (list == NULL) {
		fprintf(stderr, "listSet: argument is null\n");
		return NULL;
	}

	if (list->count == 0) {
		fprintf(stderr, "listSet: list is empty\n");
		return NULL;
	}

	if (index < 0 || index >= list->count) {
		fprintf(stderr, "listSet: out of index\n");
		return NULL;
	}
	Node* head = list->head;

	Node* node = head->next;
	for (int i = 0; i < index; i++)
		node = node->next;

	void* oldData = node->data;
	node->data = newData;
	return oldData;
}

int listCount(const List* list) {
	if (list == NULL) {
		fprintf(stderr, "listCount: argument is null\n");
		return -1;
	}
	return list->count;
}

int listInsert(List* list, int index, void* newData) {
	if (list == NULL) {
		fprintf(stderr, "listInsert: argument is null\n");
		return -1;
	}

	if (list->count == 0) {
		fprintf(stderr, "listInsert: list is empty\n");
		return -1;
	}

	if (index < 0 || index >= list->count) {
		fprintf(stderr, "listInsert: out of index\n");
		return -1;
	}

	Node* node = malloc(sizeof(Node));
	if (node == NULL) {
		perror("listInsert");
		return -1;
	}
	node->data = newData;

	Node* head = list->head;
	Node* prev = head;
	for (int i = 0; i < index; i++)
		prev = prev->next;

	node->next = prev->next;
	prev->next = node;
	++list->count;
	return 0;
}

void* listGet(List* list, int index) {
	if (list == NULL) {
		fprintf(stderr, "listGet: argument is null\n");
		return NULL;
	}

	if (list->count == 0) {
		fprintf(stderr, "listGet: list is empty\n");
		return NULL;
	}

	if (index < 0 || index >= list->count) {
		fprintf(stderr, "listGet: out of index\n");
		return NULL;
	}

	Node* head = list->head;
	Node* node = head->next;
	for (int i = 0; i < index; i++)
		node = node->next;
	return node->data;
}

void* listRemove(List* list, int index) {
	if (list == NULL) {
		fprintf(stderr, "listRemove: argument is null\n");
		return NULL;
	}

	if (list->count == 0) {
		fprintf(stderr, "listRemove: list is empty\n");
		return NULL;
	}

	if (index < 0 || index >= list->count) {
		fprintf(stderr, "listRemove: out of index\n");
		return NULL;
	}

	Node* head = list->head;
	Node* prev = head;
	for (int i = 0; i < index; i++)
		prev = prev->next;

	Node* target = prev->next;
	prev->next = target->next;
	void* outData = target->data;
	free(target);
	--list->count;
	return outData;
}

// ���� �ڵ�� ���̺귯�� �����ڰ� �����ϴ� �ڵ��Դϴ�.
//------------------------------------------------------------------
// �Ʒ��� �ڵ�� ����ڰ� �����ϴ� �ڵ��Դϴ�.
typedef struct {
	char name[32];	// char *name;
	int age;
} Person;

const char* toString(const void* ptr) {
	const Person* person = ptr;

	static char buf[32];
	sprintf(buf, "%s(%d)", person->name, person->age);
	return (const char*)buf;
}

//void FreePerson(void* ptr) {
//	Person* p = ptr;
//	free(p->name);
//}

int main() {
	Person people[4] = {
		{"susan", 20}, {"eddy", 30}, {"rupy", 40}, {"petty", 50}
	};

	List list;
	listInitialize(&list, NULL);

	for (int i = 0; i < 3; i++)
		listAdd(&list, people + i);
	listDisplay(&list, toString);

	listInsert(&list, 0, people + 3), listDisplay(&list, toString);

	Person* person = listRemove(&list, 0);
	listDisplay(&list, toString);

	listFinalize(&list);
	return 0;
}