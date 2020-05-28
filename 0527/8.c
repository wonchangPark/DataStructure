#include <stdio.h>
#include <stdlib.h>
//ppt p.8 참고
typedef struct Array {
	int *contents;
	int size;
	int count;
} Array;
// step 7. 이전 자료구조는 배열의 크기가 고정되어 있다는 단점이 있습니다. 이를 해결하기 위해 포인터를 도입합니다.
Array* arrayCreate(size_t size) {

	if(size ==0)
	{
		fprintf(stderr, "arryayCreate: size is zero\n");
		return NULL;
	}

	//원래는 리턴을 지역변수로 주면 안좋은 코드이나 이것은 힙에 할당한 주소를 넘겨주는것이므로 아무 문제가 없다.
	Array* array = malloc(sizeof(Array));
	if (array == NULL) {
		perror("arrayCreate");
		return NULL;
	}
	int* contents = malloc(sizeof(int) * size);
	if(contents ==NULL)
	{
		perror("arrayCreate");
		free(array);	//위에서 할당했으므로 해제를 하고 리턴을 해야한다.
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
	//자원의 해제는 생성의 역순
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




