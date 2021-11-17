#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>

//이진탐색 트리 만들기-재귀함수 이용하기
typedef struct Tree
{
    int data;
    struct Tree* leftlink; //왼쪽 주소
    struct Tree* rightlink; //오른쪽 주소
}Tree;

//메뉴
void Menu()
{
    printf("< < < = = = = 메뉴 = = = = > > >\n");
    printf("1.data 추가\n");
    printf("2.data 삭제\n"); //구현제외
    printf("3.preorder\n");
    printf("4.inorder\n");
    printf("5.postorder\n");
    printf("6.data 검색\n");
    printf("7.종료\n");
    printf("====================\n");
    printf("선택 : ");
}

//좌우 링크 초기화된 트리노드 간편하게 만들기
Tree* Make_Tree()
{
    Tree* add = (Tree*)malloc(sizeof(Tree));
    add->leftlink = NULL;
    add->rightlink = NULL;
    return add;
}

//데이터 추가
Tree* Add_Data(Tree* Node, int data)
{
    //비어있으면 새노드 만들고 주소보냄
    if (Node == NULL)
    {
        Tree* add = Make_Tree();
        add->data = data;
        return add;
    }

    //이미 존재하는 데이터라면
    if (Node->data == data)
    {
        printf("입력하신 %d 존재합니다\n", data);
    }//아니라면 대소 구분해서 왼쪽으로 가거나 오른쪽으로 감
    else if (Node->data > data)
    {
        Node->leftlink = Add_Data(Node->leftlink, data);
    }
    else if (Node->data < data)
    {
       Node->rightlink = Add_Data(Node->rightlink, data);
    }

    return Node;
}

//탐색
void Search(Tree* Node, int data)
{
    //못 찾았을 경우
    if (Node == NULL)
    {
        printf("%d 존재하지 않습니다\n", data);
        return;
    }

    //찾았을 경우
    if (Node->data == data) 
    {
        printf("%d 존재합니다\n", data);
    }//아니라면 대소 구분해서 왼쪽으로 가거나 오른쪽으로 감
    else if (Node->data > data)
    {
        Search(Node->leftlink, data);
    }
    else if (Node->data < data)
    {
        Search(Node->rightlink, data);
    }

    return;
}

//전위 순회
void Preorder(Tree* Node)
{
    if (Node == NULL)
    {
        return;
    }
    printf("%d  ", Node->data);
    Preorder(Node->leftlink);
    Preorder(Node->rightlink);
}

//중위 순회
void Inorder(Tree* Node)
{
    if (Node == NULL)
    {
        return;
    }
    Inorder(Node->leftlink);
    printf("%d  ", Node->data);
    Inorder(Node->rightlink);

}

//후위순회
void Postorder(Tree* Node)
{
    if (Node == NULL)
    {
        return;
    }
    Postorder(Node->leftlink);
    Postorder(Node->rightlink);
    printf("%d  ", Node->data);
}

//할당 해제
void Release(Tree* Node)
{
    if (Node == NULL)
    {
        return;
    }
    Postorder(Node->leftlink);
    Postorder(Node->rightlink);
    free(Node);
}

//가장 작은 데이터 찾는용
Tree* MinNode(Tree* Node)
{
    if (Node->leftlink == NULL) //오른쪽에서 가장 작은 데이터 찾음
    {
        return Node;
    }

    Tree* tmp = MinNode(Node->leftlink);

    if (tmp->leftlink == NULL && tmp->rightlink != NULL)//만약 그 데이터가 오른쪽 자식이 있다면 
    {
        Node->leftlink = tmp->rightlink; //현재 노드의 왼쪽에 오른쪽 자식의 링크를 넣어주고
        tmp->rightlink = NULL; //NULL로 만들어줌
    }

    return tmp;
}

//데이터 삭제-루트 노드가 삭제될 수도 있음 > 항상 루트 노드를 반환
Tree* Delete(Tree* Node, int data)
{
    //삭제할 데이터를 못 찾았을 경우
    if (Node == NULL)
    {
        printf("삭제할 데이터가 없습니다.\n");
        return Node;
    }

    //1.삭제할 노드 찾기
    if (Node->data == data)
    {
        Tree* tmp = NULL;

        if (Node->leftlink != NULL && Node->rightlink != NULL) //양쪽 자식이 있음
        {
            tmp = MinNode(Node->rightlink);//자신을 대체할 자식을 찾음
            tmp->leftlink = Node->leftlink; //원래 자기가 가지고있던 자식 넣어줌
            if (Node->rightlink != tmp)//만약 삭제해야할 노드의 오른쪽 첫번째 노드가 대체노드로 선택되었을 경우 tmp->rightlink 갱신하면 안됨
            {
                tmp->rightlink = Node->rightlink;
            }
        }
        else if (Node->leftlink != NULL) //왼쪽 자식만 있음
        {
            tmp = Node->leftlink;
        }
        else if (Node->rightlink != NULL) //오른쪽 자식만있음
        {
            tmp = Node->rightlink;
        } 
        //자식이 없음
        free(Node);
        return tmp;
    }//삭제할 데이터를 찾을때까지 이동 > 대소 구분해서 왼쪽 또는 오른쪽으로
    else if (Node->data > data)
    {
        Node->leftlink = Delete(Node->leftlink, data);
    }
    else if (Node->data < data)
    {
        Node->rightlink = Delete(Node->rightlink, data);
    }
    return Node;
}


void main()
{
    int select;
    int data;
    Tree* root = NULL; //루트 노드

    while (1)
    {
        system("cls");
        Menu();
        scanf("%d", &select);

        switch (select)
        {
        case 1://데이터 추가
            printf("data 입력 : ");
            scanf("%d", &data);
            root = Add_Data(root, data);
            system("pause");
            break;
        case 2: //데이터 삭제
            printf("삭제할 데이터 입력 : ");
            scanf("%d", &data);
            root = Delete(root, data);
            system("pause");
            break;
        case 3: //preorder - 전위순회
            Preorder(root);
            system("pause");
            break;
        case 4: //inorder - 중위순회
            Inorder(root);
            system("pause");
            break;
        case 5: //postorder - 후위순회
            Postorder(root);
            system("pause");
            break;
        case 6: //데이터 검색
            printf("input data : ");
            scanf("%d", &data);
            Search(root,data);
            system("pause");
            break;
        case 7: //종료-할당해제 (postorder 사용할 것)
            Release(root);
            printf("할당 해제 완료");
            return;
        }
    }

}