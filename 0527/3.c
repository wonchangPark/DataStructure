#include <stdio.h>
#include <stdlib.h>	// system()

int arr[5];
int size = 5;
int count;	

//step2. ���� �ڷᱸ���� �߰��� �� �����ϳ� 2�� �̻��� �ڷᱸ���� ���� �� ���ٴ� ������ �ֽ��ϴ�.
// �̴� �Լ��� ���� �ɺ��� ���������� ����ϰ� �ֱ� �����Դϴ�.
// ���� �� ������ �ذ��ϱ� ���� ���� �ɺ��� ���� �ɺ��� �����Ͽ� ó���մϴ�.
int arrayAdd(int* arr, int size, int* count, int data) {
	//���ڷ� ������ �̰͵鵵 ���������� �Ǳ⶧���� �� ���������� ���� �ٲ���� ���������� ������ ����ģ��.
	//��, ����������  ����Ű�� �����͸� �̿��Ͽ� �ذ��Ѵ�.
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




