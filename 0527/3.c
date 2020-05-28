#include <stdio.h>
#include <stdlib.h>	// system()

int arr[5];
int size = 5;
int count;	

//step2. 이전 자료구조는 추가가 잘 동작하나 2개 이상의 자료구조를 만들 수 없다는 문제가 있습니다.
// 이는 함수가 전역 심볼을 직접적으로 사용하고 있기 때문입니다.
// 이제 이 문제를 해결하기 위해 전역 심볼을 지역 심볼로 변경하여 처리합니다.
int arrayAdd(int* arr, int size, int* count, int data) {
	//인자로 들어오면 이것들도 지역변수가 되기때문에 이 지역변수의 값을 바꿔봤자 전역변수에 영향은 못미친다.
	//즉, 전역변수를  가르키는 포인터를 이용하여 해결한다.
	if (*count == size)
		return -1;
	arr[(*count)++] = data;
	return 0;
}

void arrayDisplay() {
	system("cls");	

	for (int i = 0; i < size; i++) {
		if (i < count)
			printf("[%2d]", arr[i]);
		else
			printf("[%2c]", ' ');
	}
	getchar();
}

int main() {
	arrayDisplay();
	for (int i = 0; i < 10; i++) {
		arrayAdd(arr, size, &count ,i + 1);
		arrayDisplay();
	}
}




