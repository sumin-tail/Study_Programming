#include<stdio.h>
#include<Windows.h>

typedef struct node
{
	int data;
	struct node* parent;
	struct node* left;
	struct node* right;
}Node;

void gotoxy(int x, int y);//확인안해도됨
void Left_Print(Node* node, int x, int y, int addx);//확인안해도됨
void Right_Print(Node* node, int x, int y, int addx);//확인안해도됨
void print_data(Node* node);//확인안해도됨
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

//추가
Node* insert(Node* node, int data)
{
	//빈곳 까지 노드가 왔을 때
	if (node == NULL)
	{
		//새노드 할당
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		node->parent = NULL;
		return node; //데이터만 있고 나머지는 다 NULL 인 상태로 되돌려줌 
	}
	else if (node->data < data)
	{
		node->right = insert(node->right, data);//현재 노드의 오른쪽에 새로 할당된or기존 노드 주소를 다시 넣어주고
		node->right->parent = node; // 현재노드의 오른쪽 자식 노드의 부모노드를 자신으로 설정함
	}
	else if (node->data > data)
	{
		node->left = insert(node->left, data);
		node->left->parent = node;
	}
	else
		printf("Data already exists\n");//데이터가 이미 존재 할 경우
	return node;
}

//전위 순회
void PreOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	PreOrder(node->left);
	PreOrder(node->right);
}

//중위 순회
void InOrder(Node* node)
{
	if (node == NULL)
		return;
	InOrder(node->left);
	printf("%d ", node->data);
	InOrder(node->right);
}

//후위 순회
void PostOrder(Node* node)
{
	if (node == NULL)
		return;
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d ", node->data);
}

//전체 할당 해제
void All_Delete(Node* node)
{
	if (node == NULL)
		return;
	All_Delete(node->left);
	All_Delete(node->right);
	printf("%d Deallocation Success \n", node->data);
	free(node);
}

Node* FindMinNode(Node* node, Node* Parent) //여기서 들어오는 Parent는 삭제할 노드의 주소
{
	if (node->left == NULL) //만약 현재노드가 가장 작은 노드라면...
	{
		if (node->parent != NULL)//현재노드의 부모가 NULL이 아니라면(parent 대문자 아님!!)
		{
			if (Parent != node->parent)            //현재노드의 부모가 삭제할 노드의 주소와 같지 않다면... = 삭제할 노드에서 한칸만 내려온게 아니라는 뜻
				node->parent->left = node->right;  // >현재노드 부모의 왼쪽 자식에 내가 가진 오른쪽 자식노드의 주소를 넣음
			else                                   //현재노드의 부모가 삭제할 노드의 주소와 같다면..
				node->parent->right = node->right; // >현재노드 부모의 오른쪽 자식에 내가 가진 오른쪽 자식노드의 주소를 넣음  
			//> 왜? 자신을 대체할 노드는 오른쪽 노드(한칸 내려와서)의 가장 왼쪽에 있는 노드이기 때문 

			if (node->right != NULL) //현재노드의 오른쪽 자식이 있다면
				node->right->parent = node->parent;//오른쪽 자식의 부모를 내 부모로 재설정 함
		}
		return node; //현재 노드를 돌려줌
	}
	else //아니라면 왼쪽으로 한칸 더 내려감
		return FindMinNode(node->left, Parent);
}

Node* Delete(Node* node, int data)
{
	if (node == NULL) //(끝까지 왔지만) 삭제할 데이터를 찾지 못함
	{
		printf("Not find data\n");
	}
	else if (node->data > data)//데이터를 찾아서 이동(왼쪽)
		node->left = Delete(node->left, data);
	else if (node->data < data)//데이터를 찾아서 이동(오른쪽)
		node->right = Delete(node->right, data);
	else //데이터를 찾았음
	{
		Node* deletetemp = node; //삭제할 노드의 주소를 저장함

		if (node->left != NULL && node->right != NULL)//왼쪽과 오른쪽 모두 자식이 있음
		{
			Node* MinNode = FindMinNode(node->right, deletetemp); //내가 있던 곳으로 들어갈 나를 대체할 노드를 찾음

			MinNode->parent = node->parent; // 나를 대체할 노드의 부모를 내 부모로 재설정함

			MinNode->left = deletetemp->left; //내 노드의 왼쪽 자식을 나를 내체할 노드의 왼쪽 자식으로 넣음
			if (deletetemp->left != NULL) //내 노드의 왼쪽 자식이 있다면
				deletetemp->left->parent = MinNode;//왼쪽 자신의 부모를 대체할 노드 주소로 변경

			MinNode->right = deletetemp->right;//내 노드의 오른쪽 자식을 나를 내체할 노드의 오른쪽 자식으로 넣음
			if (deletetemp->right != NULL)//위와 동일
				deletetemp->right->parent = MinNode;

			node = MinNode; //현재노드를 대체할 노드로 변경
		}
		else if (node->left != NULL)//왼쪽에만 자식이 있음
		{
			if (node->left != NULL)//1.왼쪽에만 자식이있다면
				node->left->parent = node->parent;//2.왼쪽 자식의 부모를 내 부모로 재설정 해줌
			node = node->left; //현재 노드를 내 노드의 왼쪽 자식으로 갱신함
		}
		else //왼쪽에 자식이 없음
		{
			if (node->right != NULL)//1.오른쪽에만 자식이있다면
				node->right->parent = node->parent;//2.오른쪽 자식의 부모를 내 부모로 재설정 해줌
			node = node->right;//현재 노드를 내 노드의 오른쪽 자식으로 갱신함
		}
		free(deletetemp);//삭제할 노드를 할당 해제함
	}

	return node;
}

void Search(Node* node, int Data)
{
	if (node == NULL)
	{
		printf("Not Find Data..\n"); //데이터를 찾지 못함
		return;
	}
	else if (node->data == Data)//데이터를 찾음
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