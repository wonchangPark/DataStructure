#include <stdio.h>
#include <stdlib.h>
typedef struct Array {
	int* contents;
	int size;
	int count;
} Array;
Array* arrayCreate(size_t size) {

	if (size == 0)
	{
		fprintf(stderr, "arrayCreate: size is zero\n");
		return NULL;
	}

	Array* array = malloc(sizeof(Array));
	if (array == NULL) {
		perror("arrayCreate");
		return NULL;
	}
	int* contents = malloc(sizeof(int) * size);
	if (contents == NULL)
	{
		perror("arrayCreate");
		free(array);	
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

//step 8. ������ �����ϴ� ��ġ�� �����͸� �����ϴ� �Լ��� ������ ������
// ��, �����Ͻ� ���� �ݵ�� ���� �����ʹ� ���Ƿ� �����Ͻø� �ȵ˴ϴ�.
int arraySet(Array* arr, int index, int newData, int *oldData)
{
	if(arr == NULL || oldData ==NULL)
	{
		fprintf(stderr, "arraySet: argument is null\n");
		return -1;
	}
	if(index <0 || index >= arr->count)
	{
		fprintf(stderr, "arraySet: argument is null\n");
		return -1;
	}

	*oldData = arr->contents[index];
	 arr->contents[index]= newData;
	 return 0;
}

int main() {
	Array* arr = arrayCreate(5);

	for (int i = 0; i < 10; i++) {
		arrayAdd(arr, i + 1);
	}
	arrayDisplay(arr);	//1 2 3 4 5

	for(int i =0; i<5; i++)
	{
		int oldData;
		
		arraySet(arr,i, 0, &oldData);	//arr�� i��°�� 0�� �ְڴ�
		arrayDisplay(arr);
		printf("old value: %d\n", oldData);
		getchar();
	}
	
	arrayDestroy(arr);
}




