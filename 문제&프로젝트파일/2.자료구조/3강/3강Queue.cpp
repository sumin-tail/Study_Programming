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
    printf("�Է� : ");
}

void Release(Queue* Node)
{
    if (Node == NULL) //Node �� NULL���� Ȯ��
    {
        return;
    }//NODE�� NULL == ���� �ؼ� ���ư� ����ü�� ���� ó���� �߰��� ����ü��� ��
    Release(Node->link);//Node �� NULL�� �� ������ ����Լ��� �Ʒ��� ������
    //�������� ������ ���� �Ʒ����� ������ ���ʷ� �Ҵ� ������
    free(Node);//���� ������ ����ü �Ҵ� ����
}

Queue* enqueue(Queue* Last, int num)
{
    //�� �����Ҵ��ϰ� �ּ�����
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
    int data; //�����͸� ������
    Queue* tmp; //ť ������
    tmp = Node; //���� ����Ʈ�� �ּҸ� ����

    if (tmp == NULL)//����Ʈ�� NULL �̸�? ����ִٴ� ����
    {
        printf("������ �����Ͱ� �����ϴ�\n");
        return NULL;
    }

    data = tmp->num; //�ƴҰ�� ������ ����
    tmp = tmp->link; //����Ʈ�� ��ũ�� �ִ� �ּ� ������
    if (tmp == NULL)//������ ����ü�� ���
    {
        printf("Front : %d  Rear : %d\n", data, data);
    }
    else
    {
        printf("Front : %d  Rear : %d\n", data, Last->num);
    }
    free(Node); //���� ž�� �ּ� �Ҵ� ����
    return tmp; //��ũ�� �ִ� �ּҸ� ����
}

void main()
{
    int select;
    int num;
    Queue* Front = NULL; //���� ���� ���� ť�� ����Ű�� ������
    Queue* Rear = NULL; //���� ���߿� ���� ť�� ����Ű�� ������

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
            if (Front == NULL) //���� ����Ʈ�� �ƹ��͵� �� ����Ű�� ���� ��쿡�� �ƹ��͵� �� �����ִ� ���¶�� ���̴� �Ѵ� ���ÿ� �ʱ�ȭ
            {
                Front = enqueue(Rear, num);
                Rear = Front;
            }
            else
            {
                Rear = enqueue(Rear, num);//�ƴ϶�� �Ͼ �ʱ�ȭ
            }
            printf("Front : %d  Rear : %d\n", Front->num, Rear->num);
            system("pause");
            break;
        case 2:
            Front = dequeue(Front, Rear);
            if (Front == NULL) //���� ����Ʈ�� NULL�̶�� �����Ͱ� �ٺ��������ٴ� ���̴� Rear�� �ʱ�ȭ
            {
                Rear = NULL;
            }
            system("pause");
            break;
        case 3:
            Release(Front);
            printf("�Ҵ� ���� �Ϸ�");
            return;
        }
    }

}