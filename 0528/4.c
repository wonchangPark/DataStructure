
// 노드 설계
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int count;
	int data;
	struct Node* next;
}Node;
Node* head;	//head 포인터는 항상 처음 노드만을 가리켜야 한다. 이것을 수정하면 그 이전의 노드들에게 갈 수가 없기 때문 따라서 current node를 가리키는 포인터를 만든다. 

// 데이터를 마지막에 추가하는 listAdd 함수를 구현해 보세요 :D
int listAdd(int data)
{
	Node* node = malloc(sizeof(Node));
	if(node == NULL)
	{
		perror("listAdd");
		return -1;
	}
	
	node->data = data;
	node->next = NULL;

	//연결리스트가 비어있는경우
	if(head == NULL)
	{
		head = node;	//head에다가 위에서 만들었던 node의 주소를 주므로 head가 node가 된다. node가 가리키던걸 가리킨다.
		return 0;
	}

	//연결리스트가 비어있지 않은 경우
	Node* cur = head;	//임시 cur 노드를 만든후 head의 값을 넣어준다.
	while(cur->next != NULL)//cur의 next가 null인지 확인 하고 null 이 아닌 경우에는 
	{
		cur = cur->next;// cur의 next가 가리키는 주소를 cur에 넣는다 즉 다음노드가 cur이 된다.
	}
	//while문을 다돌고 나면 cur->next는 NULL이라는 것이므로 현재 만들어진 마지막 노드로 왔다는것을 의미한다.
	cur->next = node;//따라서 cur이 가리키는 노드의 next에다가 지금 만든 node의 주소를 넣어준다.
	return 0;
}

void listDisplay()
{
	system("cls");
	printf("[head]");
	for(Node* node = head; node != NULL; node = node->next)
	{
		printf("->[%2d]", node->data);
		getchar();
	}
}

int main()
{
	listDisplay();
	for(int i =0 ; i<5;i++)
	{
		listAdd(i + 1);
		listDisplay();
	}
	return 0;
}