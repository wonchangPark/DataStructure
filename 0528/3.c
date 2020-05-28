//2.c 에서 사용자가 구현하는 코드입니다.
// 헤더파일에다가 선언만 넣어서 사용자와 공유를 할 수 있게 합니다.
// 사용자가 몰라도 되는 내용은 libarray.c에다가 넣어둡니다.
// 모듈화는 헤어파일과 함수구현파일(libarray.c)와 사용자파일 3.c로 만듭니다.
// 이제 앞으로 동적할당 배열을 이용할 일이 생긴다면 이 코드를 내것으로만들어서 사용한다.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Array.h"

// 현재 자료구조는 내부 구조가 은닉되어 있지 않아 코드가 올바르게 동작하지 않을 수 있다는
// 문제가 있습니다. 이를 해결하기 위해 구조체 멤버 은폐해 보세요 :D
typedef struct {
	char name[32];
	int age;
} Person;

const char* toPerson(const void* data) {	//이게 뭘까
	static char buf[32];
	const Person* person = (const Person*)data;
	sprintf(buf, "%s(%d)", person->name, person->age);
	return (const char*)buf;
}

int main() {
	Person people[5] = {
		{"daniel",20}, {"susan",30}, {"pororo", 40}, {"eddy", 50}, {"poby",60}
	};

	Array* arr = arrayCreate();
	arrayDisplay(arr, toPerson);
	for (int i = 0; i < 4; i++) {
		arrayAdd(arr, people + i);
		arrayDisplay(arr, toPerson);
		//arr->contents = NULL;	//이 코드가 오류가 발생되도록 코드를 수정해 보세요 :D
	}

	arrayInsert(arr, 0, people + 4);
	arrayDisplay(arr, toPerson);

	arrayDestroy(arr);
}

// 구글에서 androidxref를 검색하세요 -> 오픈 소스코드를 볼수있는곳


