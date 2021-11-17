#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>

//1. ���� �����͸� ����� Stack
// �������� �ּҸ� �������� �ʰ�...

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
    printf("�Է� : ");
}

void Release(Stack* Node)
{
    if (Node == NULL) //Node �� NULL���� Ȯ��
    {
        return;
    }//NODE�� NULL == ���� �ؼ� ���ư� ����ü�� ���� ó���� �߰��� ����ü��� ��
    Release(Node->link);//Node �� NULL�� �� ������ ����Լ��� �Ʒ��� ������
    //�������� ������ ���� �Ʒ����� ������ ���ʷ� �Ҵ� ������
    free(Node);//���� ������ ����ü �Ҵ� ����
}

//�����͸� �����ؼ� > ���ο��� top�� �ֱ�
Stack* Push(Stack* Node, int num)
{
    //�� �����Ҵ��ϰ� �ּ�����
    Stack* add = (Stack*)malloc(sizeof(Stack));
    //ž�� �ִ� �ּҸ� ���Ӱ� �����Ҵ� �� ���� ��ũ�� �־��ְ� ���ּҸ� ž�� �־���
    add->num = num;
    add->link = Node;
    return add;
}

Stack* Pop(Stack* Node)
{
    int data; //�����͸� ������
    Stack* tmp; //���� ������
    tmp = Node; //���� ž�� �ּҸ� ����

    if (tmp == NULL)//ž�� NULL �̸�? ����ִٴ� ����
    {
        printf("������ �����Ͱ� �����ϴ�");
        system("pause");
        return NULL;
    }
    data = tmp->num; //�ƴҰ�� ������ ����
    tmp = tmp->link; //ž�� ��ũ�� �ִ� �ּ� ������
    free(Node); //���� ž�� �ּ� �Ҵ� ����
    printf("Pop : %d", data); //���
    system("pause");
    return tmp; //ž�� ��ũ�� �ִ� �ּҸ� ����
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
            printf("������ �Է� : ");
            scanf("%d", &num);
            top = Push(top, num);
            break;
        case 2:
            top = Pop(top);
            break;
        case 3:
            Release(top);
            printf("�Ҵ� ���� �Ϸ�");
            return;
        }
    }

}