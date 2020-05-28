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
	if(arr == NULL)
	{
		fprintf(stderr, "arrayInsert: argument is null\n");
		return -1;
	}
	if(arr->size == arr->count)
	{
		fprintf(stderr, "arrayInsert: array is full\n");
		return -1;
	}
	if (index < 0 || index >= arr->count)
	{
		fprintf(stderr, "arrayInsert: out of index\n");
		return -1;
	}

	/*for(int i =arr->count; i!=index; i--)
	{
		arr->contents[i] = arr->contents[i-1];
	}*/
	//위의 루프는 성능저하가 일어나는부분이므로 memmove를 사용해야한다.
	memmove(&(arr->contents[index+1]), &(arr->contents[index]),(sizeof(int))*(arr->count-index) );
	//memmove(arr->contents+index+1, arr->contents+index, (sizeof(int))*(arr->count-index) );
	// p. 10 쪽을 참고
	arr->contents[index] = insertData;
	++(arr->count);	//내가 간과한 부분. count를 올려줘야 다음것도 가능해진다.
	return 0;
}


int main() {
	Array* arr = arrayCreate(10);

	for (int i = 0; i < 5; i++) {
		arrayAdd(arr, i + 1);
	}
	arrayDisplay(arr);	//1 2 3 4 5

	arrayInsert(arr,  2,  0 );
	arrayDisplay(arr);	//1,2,0,3,4,5

	arrayInsert(arr, 0, 0);
	arrayDisplay(arr);	//0,1,2,0,3,4,5

	
	arrayDestroy(arr);
}




