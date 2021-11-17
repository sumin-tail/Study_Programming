#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct Node
{
	int Data;
	struct Node* Next;
}Node;

Node* Push(Node* node) //함수에서 데이터 입력 받아서 바로 집어넣었음
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	printf("데이터 입력 : ");
	scanf("%d", &NewNode->Data);
	NewNode->Next = node; //이전노드의 주소를 저장함
	return NewNode;
}

Node* Pop(Node* node)
{
	if (node == NULL)
	{
		printf("삭제할 데이터가 없습니다.\n");
		return node;
	}
	printf("Pop : %d\n", node->Data);//top 노드의 데이터를 먼저 출력하고
	Node* DeleteNode = node; // 탑노드의 주소를 포인터에 넣고
	node = node->Next; //탑노드는 이전 노드의 주소로 체인자 
	free(DeleteNode);//그리고 탑노드 주소였던것을 할당 해제
	return node; //새로 바뀐 탑노드를 리턴 시켜줌

}

void main()
{
	Node* Top = NULL;
	while (1)
	{
		system("cls");
		printf("====Stack System====\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Exit\n");
		printf("====================\n");
		printf("입력 :");
		int Select;
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			Top = Push(Top);
			break;
		case 2:
			Top = Pop(Top);
			system("pause");
			break;
		case 3:
			while (Top != NULL) //탑이 NULL이 아닐때까지 계속 pop 해줌
				Top = Pop(Top);
			return;
		}
	}
}