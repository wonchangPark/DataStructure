// 2.c�� ��� �ڵ带 ������ ������ 
#include <stdio.h>
#include <stdlib.h>	// system()

// step3: ���� �ڷᱸ���� �����͵��� �и��Ǿ� �־� ����ϱ� ��ƴٴ� ������ �ֽ��ϴ�.
// �ϳ��� ������ �ִµ� arr, size, count�� �׻� ���� �־�� �ǹ̰� �ִ� �ֵ��Դϴ�.

// �̸� �ذ��ϱ� ���� �����͸� ���� ���ο� Ÿ������ ����(�߻�ȭ)�մϴ�.
typedef struct Array
{
	int contents[5];//int arr[5];
	int size;
	int count;
} Array;
//int arrayAdd(int* arr, int size, int* count, int data) {
int arrayAdd(Array* array, int data) {

	if(array == NULL)
	{
		fprintf(stderr, "arrayAdd: argument is null\n");
	}

	if (array->count == array-> size)
		return -1;
	array-> contents[(array->count)++] = data;
	return 0;
}

//void arrayDisplay(const int* arr, int size, int count) {
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
	// ���� 2�� �̻��� �ڷᱸ���� ������ �� �ֽ��ϴ�.
	Array arr1;
	//arr1�ȿ� �ִ� �μ����� �ʱ�ȭ�� ������Ѵ�.
	arr1.size = 5;
	arr1.count = 0;
	arrayDisplay(&arr1);
	for (int i = 0; i < 10; i++) {
		arrayAdd(&arr1, i + 1);
		arrayDisplay(&arr1);
	}

	Array arr2;
	//arr1�ȿ� �ִ� �μ����� �ʱ�ȭ�� ������Ѵ�.
	arr2.size = 5;
	arr2.count = 0;
	arrayDisplay(&arr2);
	for (int i = 0; i < 10; i++) {
		arrayAdd(&arr2, i + 1);
		arrayDisplay(&arr2);
	}
}




