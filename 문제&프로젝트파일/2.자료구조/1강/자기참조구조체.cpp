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
    printf("��ǥ ���� = %d\n", icount);
    printf("1.��ǥ �߰�\n");
    printf("2.��ǥ ����\n");
    printf("3.����\n");
    printf("�Է� : ");
}

void Release(Point* Node)
{
    if (Node == NULL) //Node �� NULL���� Ȯ��
    {
        return;
    }//NODE�� NULL�� ��� ���� ���� �ؼ� ���ư� ����ü�� ���� �������� �߰��� ����ü��� ��

    Release(Node->Next);//Node �� NULL�� �� ������ Release(Node->Next) ����Լ�

    free(Node);//���� ������ ����ü �Ҵ� ����
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
            if (icount == 1)// ù��° ��ǥ�϶�
            {
                pt = (Point*)malloc(sizeof(Point)); //pt�� �Ҵ�
                printf("x = "); 
                scanf("%d", &pt->x); //��ǥ �Է¹���
                printf("y = ");
                scanf("%d", &pt->y);
                pt->number = icount; //��ȣ ����
                pt->Next = NULL; //����ĭ ����
            }
            else
            {
                tmp = pt; //pt�� �ִ� �ּҸ� tmp�� ����
                while (tmp->Next != NULL)//tmp�� Next�� NULL�� �ƴҰ��
                {
                    tmp = tmp->Next; //tmp->Next(���� ����ü �ּ�)�� tmp�� �־���
                }
                add = (Point*)malloc(sizeof(Point)); //add�� ������ �Ҵ�
                printf("x = ");
                scanf("%d", &add->x);
                printf("y = ");
                scanf("%d", &add->y);
                add->Next = NULL; //�߰��� ����ü�� next�� �������
                add->number = icount; //���°�� �߰��Ǿ����� �־���
                tmp->Next = add; //tmp�� next�� add�� �������ִ� ��(�ּ�)�� ����
            }
            break;

        case 2:
            tmp = pt;
            while (tmp != NULL) 
            {
                printf("%d���� ��ǥ\nx = %d\ny = %d\n", tmp->number, tmp->x, tmp->y);
                printf("=======================\n\n");
                tmp = tmp->Next;//���� ����ü�� �Ѿ
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