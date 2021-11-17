#include<stdio.h>
#include<Windows.h>

typedef struct node
{
	int data;
	struct node* parent;
	struct node* left;
	struct node* right;
}Node;

void gotoxy(int x, int y);//Ȯ�ξ��ص���
void Left_Print(Node* node, int x, int y, int addx);//Ȯ�ξ��ص���
void Right_Print(Node* node, int x, int y, int addx);//Ȯ�ξ��ص���
void print_data(Node* node);//Ȯ�ξ��ص���
Node* insert(Node* node, int data);
void PreOrder(Node* node);
void InOrder(Node* node);
void PostOrder(Node* node);
void All_Delete(Node* node);
Node* Delete(Node* node, int data);


void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Left_Print(Node* node, int x, int y, int addx)
{
	if (node == NULL)	return;
	gotoxy(x -= addx, y += 2);
	printf("%d(", node->data);
	if (node->parent != NULL)
		printf("%d)", node->parent->data);
	else
		printf("NULL)");
	if (node->left)
		Left_Print(node->left, x, y, addx - 4);
	if (node->right)
		Right_Print(node->right, x, y, addx - 4);
}
void Right_Print(Node* node, int x, int y, int addx)
{
	if (node == NULL)	return;
	gotoxy(x += addx, y += 2);
	printf("%d(", node->data);
	if (node->parent != NULL)
		printf("%d)", node->parent->data);
	else
		printf("NULL)");
	if (node->left)
		Left_Print(node->left, x, y, addx - 4);
	if (node->right)
		Right_Print(node->right, x, y, addx - 4);
}
void print_data(Node* node)
{
	int x = 70, y = 2;
	if (node == NULL)
		return;

	gotoxy(x, y);
	printf("%d(", node->data);
	if (node->parent != NULL)
		printf("%d)", node->parent->data);
	else
		printf("NULL)");
	if (node->right) {
		Right_Print(node->right, x, y, 32);
	}
	if (node->left) {
		Left_Print(node->left, x, y, 32);
	}
	gotoxy(0, 10);
}

//�߰�
Node* insert(Node* node, int data)
{
	//��� ���� ��尡 ���� ��
	if (node == NULL)
	{
		//����� �Ҵ�
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		node->parent = NULL;
		return node; //�����͸� �ְ� �������� �� NULL �� ���·� �ǵ����� 
	}
	else if (node->data < data)
	{
		node->right = insert(node->right, data);//���� ����� �����ʿ� ���� �Ҵ��or���� ��� �ּҸ� �ٽ� �־��ְ�
		node->right->parent = node; // �������� ������ �ڽ� ����� �θ��带 �ڽ����� ������
	}
	else if (node->data > data)
	{
		node->left = insert(node->left, data);
		node->left->parent = node;
	}
	else
		printf("Data already exists\n");//�����Ͱ� �̹� ���� �� ���
	return node;
}

//���� ��ȸ
void PreOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	PreOrder(node->left);
	PreOrder(node->right);
}

//���� ��ȸ
void InOrder(Node* node)
{
	if (node == NULL)
		return;
	InOrder(node->left);
	printf("%d ", node->data);
	InOrder(node->right);
}

//���� ��ȸ
void PostOrder(Node* node)
{
	if (node == NULL)
		return;
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d ", node->data);
}

//��ü �Ҵ� ����
void All_Delete(Node* node)
{
	if (node == NULL)
		return;
	All_Delete(node->left);
	All_Delete(node->right);
	printf("%d Deallocation Success \n", node->data);
	free(node);
}

Node* FindMinNode(Node* node, Node* Parent) //���⼭ ������ Parent�� ������ ����� �ּ�
{
	if (node->left == NULL) //���� �����尡 ���� ���� �����...
	{
		if (node->parent != NULL)//�������� �θ� NULL�� �ƴ϶��(parent �빮�� �ƴ�!!)
		{
			if (Parent != node->parent)            //�������� �θ� ������ ����� �ּҿ� ���� �ʴٸ�... = ������ ��忡�� ��ĭ�� �����°� �ƴ϶�� ��
				node->parent->left = node->right;  // >������ �θ��� ���� �ڽĿ� ���� ���� ������ �ڽĳ���� �ּҸ� ����
			else                                   //�������� �θ� ������ ����� �ּҿ� ���ٸ�..
				node->parent->right = node->right; // >������ �θ��� ������ �ڽĿ� ���� ���� ������ �ڽĳ���� �ּҸ� ����  
			//> ��? �ڽ��� ��ü�� ���� ������ ���(��ĭ �����ͼ�)�� ���� ���ʿ� �ִ� ����̱� ���� 

			if (node->right != NULL) //�������� ������ �ڽ��� �ִٸ�
				node->right->parent = node->parent;//������ �ڽ��� �θ� �� �θ�� �缳�� ��
		}
		return node; //���� ��带 ������
	}
	else //�ƴ϶�� �������� ��ĭ �� ������
		return FindMinNode(node->left, Parent);
}

Node* Delete(Node* node, int data)
{
	if (node == NULL) //(������ ������) ������ �����͸� ã�� ����
	{
		printf("Not find data\n");
	}
	else if (node->data > data)//�����͸� ã�Ƽ� �̵�(����)
		node->left = Delete(node->left, data);
	else if (node->data < data)//�����͸� ã�Ƽ� �̵�(������)
		node->right = Delete(node->right, data);
	else //�����͸� ã����
	{
		Node* deletetemp = node; //������ ����� �ּҸ� ������

		if (node->left != NULL && node->right != NULL)//���ʰ� ������ ��� �ڽ��� ����
		{
			Node* MinNode = FindMinNode(node->right, deletetemp); //���� �ִ� ������ �� ���� ��ü�� ��带 ã��

			MinNode->parent = node->parent; // ���� ��ü�� ����� �θ� �� �θ�� �缳����

			MinNode->left = deletetemp->left; //�� ����� ���� �ڽ��� ���� ��ü�� ����� ���� �ڽ����� ����
			if (deletetemp->left != NULL) //�� ����� ���� �ڽ��� �ִٸ�
				deletetemp->left->parent = MinNode;//���� �ڽ��� �θ� ��ü�� ��� �ּҷ� ����

			MinNode->right = deletetemp->right;//�� ����� ������ �ڽ��� ���� ��ü�� ����� ������ �ڽ����� ����
			if (deletetemp->right != NULL)//���� ����
				deletetemp->right->parent = MinNode;

			node = MinNode; //�����带 ��ü�� ���� ����
		}
		else if (node->left != NULL)//���ʿ��� �ڽ��� ����
		{
			if (node->left != NULL)//1.���ʿ��� �ڽ����ִٸ�
				node->left->parent = node->parent;//2.���� �ڽ��� �θ� �� �θ�� �缳�� ����
			node = node->left; //���� ��带 �� ����� ���� �ڽ����� ������
		}
		else //���ʿ� �ڽ��� ����
		{
			if (node->right != NULL)//1.�����ʿ��� �ڽ����ִٸ�
				node->right->parent = node->parent;//2.������ �ڽ��� �θ� �� �θ�� �缳�� ����
			node = node->right;//���� ��带 �� ����� ������ �ڽ����� ������
		}
		free(deletetemp);//������ ��带 �Ҵ� ������
	}

	return node;
}

void Search(Node* node, int Data)
{
	if (node == NULL)
	{
		printf("Not Find Data..\n"); //�����͸� ã�� ����
		return;
	}
	else if (node->data == Data)//�����͸� ã��
	{
		printf("Find Success Data!!\n");
		return;
	}
	else if (node->data > Data)
		Search(node->left, Data);
	else if (node->data < Data)
		Search(node->right, Data);
}

void main()
{
	Node* Root = NULL;
	int Select;
	while (1)
	{
		system("cls");
		printf("======AVLTree======\n");
		printf("1.Insert\n");
		printf("2.Search\n");
		printf("3.PrintTree\n");
		printf("4.PreOrder\n");
		printf("5.InOrder\n");
		printf("6.PostOrder\n");
		printf("7.Delete\n");
		printf("8.Exit\n");
		printf("Input >> ");
		scanf("%d", &Select);
		system("cls");
		switch (Select)
		{
		case 1:
			printf("Add Data >> ");
			scanf("%d", &Select);
			Root = insert(Root, Select);
			print_data(Root);
			break;
		case 2:
			printf("Select Data >> ");
			scanf("%d", &Select);
			Search(Root, Select);
			break;
		case 3:
			print_data(Root);
			break;
		case 4:
			PreOrder(Root);
			break;
		case 5:
			InOrder(Root);
			break;
		case 6:
			PostOrder(Root);
			break;
		case 7:
			printf("Delete Data >> ");
			scanf("%d", &Select);
			Root = Delete(Root, Select);
			break;
		case 8:
			All_Delete(Root);
			return;
		default:
			printf("Please enter again!\n");
			break;
		}
		system("pause");
	}
}