#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
//2진탐색트리,B Tree,AVL Tree, 레드 블랙Tree
#define WIDTH_VALUE 20
#define HEIGHT_VALUE 4

typedef struct Node
{
	int Data;
	struct Node* Left;
	struct Node* Right;
}Node;

void gotoxy(int x, int y); //전방 선언
void RightPrint(Node* node, int x, int y);
void LeftPrint(Node* node, int x, int y);
void Print_Tree(Node* node);
Node* CreateNode(int Data);
Node* Insert(Node* node, int Data);
void PreOrder(Node* node);
void PostOrder(Node* node);
void InOrder(Node* node);
int Search(Node* node, int Data);
void Modify(Node* node, int Data);
void AllDelete(Node* node);
Node* Delete(Node* node, int Data);

//WinAIP -> 마이크로소프트사에서 제공하는 윈도우즈 컨트롤 함수 모음
void gotoxy(int x, int y)//원하는 좌표로 커서를 이동해 주는 함수
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void RightPrint(Node* node, int x, int y)
{
	if (node == NULL)
		return;
	x += WIDTH_VALUE;
	y += HEIGHT_VALUE;
	gotoxy(x, y);
	printf("%d", node->Data);
	RightPrint(node->Right, x, y);
	LeftPrint(node->Left, x, y);
}

void LeftPrint(Node* node, int x, int y)
{
	if (node == NULL)
		return;
	x -= WIDTH_VALUE;
	y += HEIGHT_VALUE;
	gotoxy(x, y);
	printf("%d", node->Data);
	RightPrint(node->Right, x, y);
	LeftPrint(node->Left, x, y);
}

void Print_Tree(Node* node)
{
	system("cls");
	int x = 70, y = 2;
	if (node == NULL)
		return;
	gotoxy(x, y);
	printf("%d", node->Data);
	RightPrint(node->Right, x, y);
	LeftPrint(node->Left, x, y);
	gotoxy(0, 0);
}

Node* CreateNode(int Data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = Data;
	newNode->Right = NULL;
	newNode->Left = NULL;
	return newNode;
}

//새 노드 추가
Node* Insert(Node* node, int Data)
{
	if (node == NULL) //아무런 노드도 없을경우 
	{
		return CreateNode(Data); //노드 만들고 리턴해줌
	}
	else
	{
		//대소관계 비교해서 왼쪽 또는 오른쪽으로 이동 - 같은 숫자를 만난다면 중복된 숫자가 이미 존재합니다 출력
		if (node->Data > Data)
			node->Left = Insert(node->Left, Data);
		else if (node->Data < Data)
			node->Right = Insert(node->Right, Data);
		else { 
			printf("중복된 숫자가 이미 존재합니다.\n");
		}
		return node;
	}
}

//전위 순회
void PreOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->Data);
	PreOrder(node->Left);
	PreOrder(node->Right);
}

//중위 순회
void InOrder(Node* node)
{
	if (node == NULL)
		return;
	PreOrder(node->Left);
	printf("%d ", node->Data);
	PreOrder(node->Right);
}

//후위순회
void PostOrder(Node* node)
{
	if (node == NULL)
		return;
	PreOrder(node->Left);
	PreOrder(node->Right);
	printf("%d ", node->Data);
}

//전체 할당해제
void AllDelete(Node* node)
{
	if (node == NULL)
		return;
	AllDelete(node->Left);
	AllDelete(node->Right);
	free(node);
}

//수정
void Modify(Node* node, int Data)
{
	if (node == NULL)
	{
		printf("%d는 존재하지 않습니다.\n", Data);
		return;
	}
	else if (node->Data == Data)
	{
		printf("%d -> ", node->Data);
		scanf("%d", &node->Data);
		return;
	}
	else
	{
		if (node->Data > Data)
			Modify(node->Left, Data);
		else if (node->Data < Data)
			Modify(node->Right, Data);
	}
}

//검색
int Search(Node* node, int Data)
{
	if (node == NULL)
	{
		printf("%d는 존재하지 않습니다.\n", Data);
		return -1;
	}
	else if (node->Data == Data)
	{
		printf("%d는 존재합니다.\n", Data);
		return node->Data;
	}
	else
	{
		if (node->Data > Data)
			return Search(node->Left, Data);
		else if (node->Data < Data)
			return Search(node->Right, Data);
	}
}


//가장 작은 노드 찾기
Node* FindMinNode(Node* node, Node** MinNode)
{
	if (node->Left == NULL) // 현재노드의 왼쪽 노드가 없다면
	{
		*MinNode = node; //현재노드의 주소를 MinNode에 저장
		node = node->Right; //현재 노드의 주소에 현재노드의 오른쪽 자식 주소를 저장
		return node; //현재노드(의 오른쪽 자식)반환 
	}
	else //현재노드의 왼쪽 노드가  NULL이 아니라면 한번 더 
	{
		node->Left = FindMinNode(node->Left, MinNode);
		return node;
	}
}

Node* Delete(Node* node, int Data)
{
	if (node == NULL) //삭제할 데이터를 찾지 못함
	{
		printf("삭제할 데이터가 존재하지 않습니다.\n");
		return NULL;
	}
	else if (node->Data == Data) //만약 삭제할 데이터를 찾았다면
	{
		Node* DeleteNode = node; //삭제할 노드 주소 저장

		if (node->Left == NULL && node->Right == NULL) //왼쪽 오른쪽 자식 둘다 없다면
			node = NULL; //노드 NULL로 만듬
		else if (node->Left != NULL && node->Right == NULL) //왼쪽자식은 있고 오른쪽 자식이 없다면
			node = node->Left; //노드에 노드 왼쪽 자식을 넣어줌
		else if (node->Left == NULL && node->Right != NULL) //오른쪽 자식이 있고 왼쪽 자식이 없다면
			node = node->Right; //노드에 오른쪽 자식을 넣어줌
		else //위에 모두 해당이 안된다는 것은 양쪽 자식이 있다는 것
		{
			Node* MinNode = NULL; //가장 작은 노드를 담을 min 노드 선언
			node->Right = FindMinNode(node->Right, &MinNode); //현재노드의 오른쪽에 기존 노드 넣음
			MinNode->Left = DeleteNode->Left; //대체할 노드의 왼쪽에 삭제할 노드의 왼쪽 노드 대입
			MinNode->Right = DeleteNode->Right; //대체할 노드의 오른쪽에 삭제할 노드의 오른쪽 노드 대입
			node = MinNode; //현재 노드에 재체할 노드 삽입
		}
		printf("%d데이터를 삭제하였습니다.", Data);
		free(DeleteNode);
		return node; //노드 반환~
	}
	else //데이터 찾는 과정
	{
		if (node->Data > Data)
			node->Left = Delete(node->Left, Data);
		else
			node->Right = Delete(node->Right, Data);
		return node;
	}
}

void main()
{
	Node* Root = NULL;
	int Data;
	while (1)
	{
		printf("========Tree========\n");
		printf("1.Insert\n");
		printf("2.Print\n");
		printf("3.PreOrder\n");
		printf("4.InOrder\n");
		printf("5.PostOrder\n");
		printf("6.Modify\n");
		printf("7.Delete\n");
		printf("8.Exit\n");
		int Select;
		printf("Input >> ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			printf("Input Data >>");
			scanf("%d", &Data);
			Root = Insert(Root, Data);
			Print_Tree(Root);
			break;
		case 2:
			Print_Tree(Root);
			break;
		case 3:
			Print_Tree(Root);
			gotoxy(0, 0);
			printf("PreOrder : ");
			PreOrder(Root);
			break;
		case 4:
			Print_Tree(Root);
			gotoxy(0, 0);
			printf("InOrder : ");
			InOrder(Root);
			break;
		case 5:
			Print_Tree(Root);
			gotoxy(0, 0);
			printf("PostOrder : ");
			PostOrder(Root);
			break;
		case 6:
			printf("Input Data >>");
			scanf("%d", &Data);
			Modify(Root, Data);
			break;
		case 7:
			printf("Input Data >>");
			scanf("%d", &Data);
			Root = Delete(Root, Data);
			Print_Tree(Root);
			break;
		case 8:
			AllDelete(Root);
			return;
		}
		system("pause");
	}
}