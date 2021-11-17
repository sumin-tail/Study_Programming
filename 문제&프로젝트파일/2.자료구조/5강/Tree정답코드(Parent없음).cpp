#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
//2��Ž��Ʈ��,B Tree,AVL Tree, ���� ��Tree
#define WIDTH_VALUE 20
#define HEIGHT_VALUE 4

typedef struct Node
{
	int Data;
	struct Node* Left;
	struct Node* Right;
}Node;

void gotoxy(int x, int y); //���� ����
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

//WinAIP -> ����ũ�μ���Ʈ�翡�� �����ϴ� �������� ��Ʈ�� �Լ� ����
void gotoxy(int x, int y)//���ϴ� ��ǥ�� Ŀ���� �̵��� �ִ� �Լ�
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

//�� ��� �߰�
Node* Insert(Node* node, int Data)
{
	if (node == NULL) //�ƹ��� ��嵵 ������� 
	{
		return CreateNode(Data); //��� ����� ��������
	}
	else
	{
		//��Ұ��� ���ؼ� ���� �Ǵ� ���������� �̵� - ���� ���ڸ� �����ٸ� �ߺ��� ���ڰ� �̹� �����մϴ� ���
		if (node->Data > Data)
			node->Left = Insert(node->Left, Data);
		else if (node->Data < Data)
			node->Right = Insert(node->Right, Data);
		else { 
			printf("�ߺ��� ���ڰ� �̹� �����մϴ�.\n");
		}
		return node;
	}
}

//���� ��ȸ
void PreOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->Data);
	PreOrder(node->Left);
	PreOrder(node->Right);
}

//���� ��ȸ
void InOrder(Node* node)
{
	if (node == NULL)
		return;
	PreOrder(node->Left);
	printf("%d ", node->Data);
	PreOrder(node->Right);
}

//������ȸ
void PostOrder(Node* node)
{
	if (node == NULL)
		return;
	PreOrder(node->Left);
	PreOrder(node->Right);
	printf("%d ", node->Data);
}

//��ü �Ҵ�����
void AllDelete(Node* node)
{
	if (node == NULL)
		return;
	AllDelete(node->Left);
	AllDelete(node->Right);
	free(node);
}

//����
void Modify(Node* node, int Data)
{
	if (node == NULL)
	{
		printf("%d�� �������� �ʽ��ϴ�.\n", Data);
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

//�˻�
int Search(Node* node, int Data)
{
	if (node == NULL)
	{
		printf("%d�� �������� �ʽ��ϴ�.\n", Data);
		return -1;
	}
	else if (node->Data == Data)
	{
		printf("%d�� �����մϴ�.\n", Data);
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


//���� ���� ��� ã��
Node* FindMinNode(Node* node, Node** MinNode)
{
	if (node->Left == NULL) // �������� ���� ��尡 ���ٸ�
	{
		*MinNode = node; //�������� �ּҸ� MinNode�� ����
		node = node->Right; //���� ����� �ּҿ� �������� ������ �ڽ� �ּҸ� ����
		return node; //������(�� ������ �ڽ�)��ȯ 
	}
	else //�������� ���� ��尡  NULL�� �ƴ϶�� �ѹ� �� 
	{
		node->Left = FindMinNode(node->Left, MinNode);
		return node;
	}
}

Node* Delete(Node* node, int Data)
{
	if (node == NULL) //������ �����͸� ã�� ����
	{
		printf("������ �����Ͱ� �������� �ʽ��ϴ�.\n");
		return NULL;
	}
	else if (node->Data == Data) //���� ������ �����͸� ã�Ҵٸ�
	{
		Node* DeleteNode = node; //������ ��� �ּ� ����

		if (node->Left == NULL && node->Right == NULL) //���� ������ �ڽ� �Ѵ� ���ٸ�
			node = NULL; //��� NULL�� ����
		else if (node->Left != NULL && node->Right == NULL) //�����ڽ��� �ְ� ������ �ڽ��� ���ٸ�
			node = node->Left; //��忡 ��� ���� �ڽ��� �־���
		else if (node->Left == NULL && node->Right != NULL) //������ �ڽ��� �ְ� ���� �ڽ��� ���ٸ�
			node = node->Right; //��忡 ������ �ڽ��� �־���
		else //���� ��� �ش��� �ȵȴٴ� ���� ���� �ڽ��� �ִٴ� ��
		{
			Node* MinNode = NULL; //���� ���� ��带 ���� min ��� ����
			node->Right = FindMinNode(node->Right, &MinNode); //�������� �����ʿ� ���� ��� ����
			MinNode->Left = DeleteNode->Left; //��ü�� ����� ���ʿ� ������ ����� ���� ��� ����
			MinNode->Right = DeleteNode->Right; //��ü�� ����� �����ʿ� ������ ����� ������ ��� ����
			node = MinNode; //���� ��忡 ��ü�� ��� ����
		}
		printf("%d�����͸� �����Ͽ����ϴ�.", Data);
		free(DeleteNode);
		return node; //��� ��ȯ~
	}
	else //������ ã�� ����
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