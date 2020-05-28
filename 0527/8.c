#include <stdio.h>
#include <stdlib.h>
//ppt p.8 ����
typedef struct Array {
	int *contents;
	int size;
	int count;
} Array;
// step 7. ���� �ڷᱸ���� �迭�� ũ�Ⱑ �����Ǿ� �ִٴ� ������ �ֽ��ϴ�. �̸� �ذ��ϱ� ���� �����͸� �����մϴ�.
Array* arrayCreate(size_t size) {

	if(size ==0)
	{
		fprintf(stderr, "arryayCreate: size is zero\n");
		return NULL;
	}

	//������ ������ ���������� �ָ� ������ �ڵ��̳� �̰��� ���� �Ҵ��� �ּҸ� �Ѱ��ִ°��̹Ƿ� �ƹ� ������ ����.
	Array* array = malloc(sizeof(Array));
	if (array == NULL) {
		perror("arrayCreate");
		return NULL;
	}
	int* contents = malloc(sizeof(int) * size);
	if(contents ==NULL)
	{
		perror("arrayCreate");
		free(array);	//������ �Ҵ������Ƿ� ������ �ϰ� ������ �ؾ��Ѵ�.
		return NULL;
	}
	array->contents = contents;
	array->count = 0;
	array->size = 5;
	return array;
}

void arrayDestroy(Array* array) {
	
	if (array == NULL)
		return;
	//�ڿ��� ������ ������ ����
	free(array->contents);
	free(array);
}

int arrayAdd(Array* array, int data) {
	if (array == NULL) {
		fprintf(stderr, "arrayAdd: argument is null\n");
		return -1;
	}

	if (array->count == array->size)
		return -1;

	array->contents[array->count] = data;
	++(array->count);
	return 0;
}

void arrayDisplay(const Array* array) {
	system("cls");
	for (int i = 0; i < array->size; i++) {
		if (i < array->count)
			printf("[%2d]", array->contents[i]);
		else
			printf("[%2c]", ' ');
	}
	getchar();
}

int main() {
	Array* arr = arrayCreate(5);
	if (arr == NULL)
		return -1;

	arrayDisplay(arr);
	for (int i = 0; i < 10; i++) {
		arrayAdd(arr, i + 1);
		arrayDisplay(arr);
	}
	arrayDestroy(arr);
}




