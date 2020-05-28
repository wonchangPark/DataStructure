#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	array->size = size;
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

int arraySet(Array* arr, int index, int newData, int* oldData)
{
	if (arr == NULL || oldData == NULL)
	{
		fprintf(stderr, "arraySet: argument is null\n");
		return -1;
	}
	if (index < 0 || index >= arr->count)
	{
		fprintf(stderr, "arraySet: argument is null\n");
		return -1;
	}

	*oldData = arr->contents[index];
	arr->contents[index] = newData;
	return 0;
}

int arrayInsert(Array* arr, int index, int insertData)
{
	if (arr == NULL)
	{
		fprintf(stderr, "arrayInsert: argument is null\n");
		return -1;
	}
	if (arr->size == arr->count)
	{
		fprintf(stderr, "arrayInsert: array is full\n");
		return -1;
	}
	if (index < 0 || index >= arr->count)
	{
		fprintf(stderr, "arrayInsert: out of index\n");
		return -1;
	}

	memmove(&(arr->contents[index + 1]), &(arr->contents[index]), (sizeof(int)) * (arr->count - index));

	arr->contents[index] = insertData;
	++(arr->count);
	return 0;
}

int arrayCount(const Array* array)
{
	if (array == NULL)
	{
		fprintf(stderr, "arrayCount: argument is null\n");
		return -1;
	}

	return array->count;
}
int arrayGet(const Array* array, int index, int* outData)
{
	if (array == NULL || outData == NULL)
	{
		fprintf(stderr, "arrayCount: argument is null\n");
		return -1;
	}
	if (index < 0 || index >= array->count)
	{
		fprintf(stderr, "arrayInsert: out of index\n");
		return -1;
	}
	*outData = array->contents[index];
	return 0;
}
//step 11. 임의의 위치에 있는 데이터를 삭제하는 함수를 구현해 보세요.
// 이때, 자료구조에서의 삭제는 물리적으로 지우는 것이 아니라 자료구조 내에 그 데이터를
// 더 이상 유지하지 않는 다는 개념입니다. 삭제된데이터는 사용자에게 전달하여 사용자가 처리하도록 해야 합니다.
//자료구조에서 삭제는 진짜물리적으로 삭제하는것이 아닌 자료구조내에서 더이상 유지하지 않는다는뜻이다.
//제거 하고 나서생기는 빈부분은 메꿔져야 한다.
int arrayRemove(Array* array, int index, int* removeData)
{
	if (array == NULL || removeData ==NULL)
	{
		fprintf(stderr, "arrayRemove: argument is null\n");
		return -1;
	}
	if (array->count == 0)
	{
		fprintf(stderr, "arrayRemove: array is empty\n");
		return -1;
	}
	if (index < 0 || index >= array->count)
	{
		fprintf(stderr, "arrayRemove: out of index\n");
		return -1;
	}
	*removeData = array->contents[index];
	int newCount = array->count - 1;
	if(index != newCount)	//newCount 마지막번째 원소라면 그냥 카운트만 하나 내리면 된다. p.11참고
	{
		memmove(array->contents + index, array->contents + index + 1, sizeof(int) * (array->count - index));
	}
	array->count=newCount;
	return 0;
}

int main() {
	Array* arr = arrayCreate(10);

	//----------------------------------------
	for (int i = 0; i < 5; i++) {
		arrayAdd(arr, i + 1);
	}
	arrayDisplay(arr);
	int count = arrayCount(arr);
	
	for (int i = 0; i < count; i++)
	{
		int removeData;
		arrayRemove(arr, 0, &removeData);
		arrayDisplay(arr);
	}

	//----------------------------------------

	arrayDestroy(arr);
}


