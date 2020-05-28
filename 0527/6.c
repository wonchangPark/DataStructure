#include <stdio.h>
#include <stdlib.h>

// step 5. 이전 자료구조는 자료구조의 컨텍스트를 저장하기 위해 스택 메모리를 사용하고 있다는
// 단점이 있습니다. 이를 해결하기 위해 정보 구조체를 힙에 생성하도록 합니다.
typedef struct Array {
	int contents[5];
	int size;
	int count;
} Array;

//int arrayInitiate(Array* array) {
int arrayCreate(Array **array) {
	//
	if (array == NULL) {
		fprintf(stderr, "arrayAdd: argument is null\n");
		return -1;
	}

	Array* temp = malloc(sizeof(Array));
	if (temp == NULL) {
		perror("malloc");
		return -1;
	}

	temp->count = 0;
	temp->size = 5;
	*array = temp;	//Array*를 가리키는 포인터 array이므로 역참조를 하면 진짜 Array*의 값이 되고 그 값에 temp의 값을 넣는다.
	return 0;
}

void arrayDestroy(Array* array) {
	if (array == NULL)
		return;
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
	Array* arr;// Array arr;
	arrayCreate(&arr); //arrayInitiate(&arr);
	//주소로 받는 이유는 Array* arr로 할당을 할것이기 때문인데 그냥 arr만 넘기게 되면 arrayCreate함수에서는 힙에 할당을 할순있겠지만
	//그 함수내에서 한것이므로 돌아왔을때 메인의 arr는 여전히 쓰레기값을 가지고 있을것이다. 따라서 arr의 주소를 보내게 되면
	//create함수에서는 temp로 할당을 한후 메인의 arr를 가리키는 array의 포인터값에 temp를 넣는다. 
	//----------------------------
	arrayDisplay(arr);
	for (int i = 0; i < 10; i++) {
		arrayAdd(arr, i + 1);
		arrayDisplay(arr);
	}
	//----------------------------
	arrayDestroy(arr);
}




