#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>

//1. 이중 포인터를 사용한 Stack

typedef struct Stack
{
    int num;
    struct Stack* link;

}Stack;

void Menu()
{
    printf("====Stack System====\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Exit\n");
    printf("====================\n");
    printf("입력 : ");
}

void Release(Stack* Node)
{
    if (Node == NULL) //Node 가 NULL인지 확인
    {
        return;
    }//NODE가 NULL == 리턴 해서 돌아간 구조체가 가장 처음에 추가된 구조체라는 것
    Release(Node->link);//Node 가 NULL이 될 때까지 재귀함수로 아래로 내려감
    //리턴으로 나오면 가장 아래부터 위까지 차례로 할당 해제됨
    free(Node);//가장 마지막 구조체 할당 해제
}

void Push(Stack* *Node, int num)
{
    //새 동적할당하고 주소저장
    Stack *add = (Stack*)malloc(sizeof(Stack));
    //탑에 있던 주소를 새롭게 동적할당 된 곳의 링크에 넣어주고 새주소를 탑에 넣어줌
    add->num = num;
    add->link = *Node;
    *Node = add;
}

void Pop(Stack** Node)
{
    int data; //데이터를 담을곳
    Stack *tmp; //스택 포인터
    tmp = *Node; //현재 탑의 주소를 저장

    if (tmp == NULL)//탑이 NULL 이면? 비어있다는 뜻임
    {
        printf("삭제할 데이터가 없습니다");
        system("pause");
        return;
    }
    data = tmp->num; //아닐경우 데이터 빼옴
    *Node = tmp->link; //탑의 링크에 있던 주소를 새롭게 탑에 넣음
    free(tmp); //기존 탑의 주소 할당 해제
    printf("Pop : %d", data); //출력
    system("pause");

}

void main()
{
    int select;
    int num;
    Stack* top = NULL;

    while (1)
    {
        system("cls");
        Menu();
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            printf("데이터 입력 : ");
            scanf("%d", &num);
            Push(&top, num);
            break;
        case 2:
            Pop(&top);
            break;
        case 3:
            Release(top);
            printf("할당 해제 완료");
            return;
        }
    }

}