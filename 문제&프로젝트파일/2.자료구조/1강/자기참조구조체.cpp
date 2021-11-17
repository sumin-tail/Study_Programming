#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>

typedef struct Point
{
    int number;
    int x, y;
    struct Point* Next;
}Point;


void Menu(int icount)
{
    printf("좌표 갯수 = %d\n", icount);
    printf("1.좌표 추가\n");
    printf("2.좌표 보기\n");
    printf("3.종료\n");
    printf("입력 : ");
}

void Release(Point* Node)
{
    if (Node == NULL) //Node 가 NULL인지 확인
    {
        return;
    }//NODE가 NULL이 라는 것은 리턴 해서 돌아간 구조체가 가장 마지막에 추가된 구조체라는 것

    Release(Node->Next);//Node 가 NULL이 될 때까지 Release(Node->Next) 재귀함수

    free(Node);//가장 마지막 구조체 할당 해제
}


void main()
{
    int icount = 0;
    int num;
    Point* pt = NULL, *tmp, *add;
    while (1)
    {
        system("cls");
        Menu(icount);
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            icount++;
            if (icount == 1)// 첫번째 좌표일때
            {
                pt = (Point*)malloc(sizeof(Point)); //pt에 할당
                printf("x = "); 
                scanf("%d", &pt->x); //좌표 입력받음
                printf("y = ");
                scanf("%d", &pt->y);
                pt->number = icount; //번호 넣음
                pt->Next = NULL; //다음칸 없다
            }
            else
            {
                tmp = pt; //pt에 있는 주소를 tmp에 넣음
                while (tmp->Next != NULL)//tmp의 Next가 NULL이 아닐경우
                {
                    tmp = tmp->Next; //tmp->Next(다음 구조체 주소)를 tmp에 넣어줌
                }
                add = (Point*)malloc(sizeof(Point)); //add에 사이즈 할당
                printf("x = ");
                scanf("%d", &add->x);
                printf("y = ");
                scanf("%d", &add->y);
                add->Next = NULL; //추가된 구조체의 next는 비어있음
                add->number = icount; //몇번째로 추가되었는지 넣어줌
                tmp->Next = add; //tmp의 next에 add가 가지고있는 값(주소)를 넣음
            }
            break;

        case 2:
            tmp = pt;
            while (tmp != NULL) 
            {
                printf("%d번쨰 좌표\nx = %d\ny = %d\n", tmp->number, tmp->x, tmp->y);
                printf("=======================\n\n");
                tmp = tmp->Next;//다음 구조체로 넘어감
            }
            system("pause");
            break;

        case 3:
            Release(pt);
            return;
        }
    }

    Release(pt);
}