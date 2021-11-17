#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>

typedef struct Queue
{
    int num;
    struct Queue* link;

}Queue;

void Menu()
{
    printf("====Queue System====\n");
    printf("1.enqueue\n");
    printf("2.dequeue\n");
    printf("3.Exit\n");
    printf("====================\n");
    printf("입력 : ");
}

void Release(Queue* Node)
{
    if (Node == NULL) //Node 가 NULL인지 확인
    {
        return;
    }//NODE가 NULL == 리턴 해서 돌아간 구조체가 가장 처음에 추가된 구조체라는 것
    Release(Node->link);//Node 가 NULL이 될 때까지 재귀함수로 아래로 내려감
    //리턴으로 나오면 가장 아래부터 위까지 차례로 할당 해제됨
    free(Node);//가장 마지막 구조체 할당 해제
}

Queue* enqueue(Queue* Last, int num)
{
    //새 동적할당하고 주소저장
    Queue* add = (Queue*)malloc(sizeof(Queue));
    add->num = num;
    add->link = NULL;

    if (Last != NULL)
    {
        Last->link = add;
    }
    return add;
}

Queue* dequeue(Queue* Node, Queue* Last)
{
    int data; //데이터를 담을곳
    Queue* tmp; //큐 포인터
    tmp = Node; //현재 프론트의 주소를 저장

    if (tmp == NULL)//프론트가 NULL 이면? 비어있다는 뜻임
    {
        printf("삭제할 데이터가 없습니다\n");
        return NULL;
    }

    data = tmp->num; //아닐경우 데이터 빼옴
    tmp = tmp->link; //프론트의 링크에 있던 주소 저장함
    if (tmp == NULL)//마지막 구조체일 경우
    {
        printf("Front : %d  Rear : %d\n", data, data);
    }
    else
    {
        printf("Front : %d  Rear : %d\n", data, Last->num);
    }
    free(Node); //기존 탑의 주소 할당 해제
    return tmp; //링크에 있던 주소를 리턴
}

void main()
{
    int select;
    int num;
    Queue* Front = NULL; //가장 먼저 들어온 큐를 가리키는 포인터
    Queue* Rear = NULL; //가장 나중에 들어온 큐를 가리키는 포인터

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
            if (Front == NULL) //만약 프론트가 아무것도 안 가리키고 있을 경우에는 아무것도 안 들어와있는 상태라는 뜻이니 둘다 동시에 초기화
            {
                Front = enqueue(Rear, num);
                Rear = Front;
            }
            else
            {
                Rear = enqueue(Rear, num);//아니라면 니어만 초기화
            }
            printf("Front : %d  Rear : %d\n", Front->num, Rear->num);
            system("pause");
            break;
        case 2:
            Front = dequeue(Front, Rear);
            if (Front == NULL) //만약 프론트가 NULL이라면 데이터가 다빠져나갔다는 뜻이니 Rear도 초기화
            {
                Rear = NULL;
            }
            system("pause");
            break;
        case 3:
            Release(Front);
            printf("할당 해제 완료");
            return;
        }
    }

}