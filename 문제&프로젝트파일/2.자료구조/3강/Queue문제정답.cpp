#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

//이중 포인터를 사용함

typedef struct Node
{
	int Data;
	struct Node* Link;
}Node;

void Enqueue(Node** Front, Node** Rear)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	printf("데이터 입력 : ");
	scanf("%d", &NewNode->Data);
	NewNode->Link = NULL;
	if (*Front == NULL)
	{
		*Front = NewNode;
		*Rear = NewNode;
	}
	else
	{
		(*Rear)->Link = NewNode;
		(*Rear) = NewNode;
	}
	printf("Front : %d\tRear : %d\n", (*Front)->Data, (*Rear)->Data);
	system("pause");
	return;
}

void Dequeue(Node** Front, Node** Rear)
{
	if (*Front == NULL)
	{
		printf("삭제할 데이터가 없습니다.\n");
		return;
	}
	printf("Front : %d\tRear : %d\n", (*Front)->Data, (*Rear)->Data);
	Node* DeleteNode = (*Front);
	(*Front) = (*Front)->Link;
	if (*Front == NULL)
		*Rear = NULL;
	free(DeleteNode);
	system("pause");
	return;

}

void main()
{
	Node* Front = NULL;
	Node* Rear = NULL;

	while (1)
	{
		system("cls");
		printf("====Queue System====\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Exit\n");
		printf("====================\n");
		printf("입력 :");
		int Select;
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			Enqueue(&Front, &Rear);
			break;
		case 2:
			Dequeue(&Front, &Rear);
			break;
		case 3:
			while (Front != NULL)
				Dequeue(&Front, &Rear);
			return;
		}
	}
}