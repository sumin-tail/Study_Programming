#include <stdio.h>


typedef struct Node
{
    int Num;
    struct Node* Next;
}Node;


void main()
{
    Node a;
    Node b;
    a.Num = 1;
    b.Num = 2;

    a.Next = &b;

    printf("%d\n", a.Num);
    //�Ʒ����� ����
    printf("%d\n", (*a.Next).Num);
    printf("%d\n", a.Next->Num);

    printf("%p\n", a.Next);
    printf("%p\n",&b);
    //->�� (*p).~~�� ����.
    //->�� � ���� �ִ°��� ����Ű��
}

//�޸��ּҴ� 32��Ʈ
//1����Ʈ�� 8 ��Ʈ 
//�޸��ּҴ� 4����Ʈ
//16���� 8�ڸ���
//1����Ʈ�� 16���� ���ڸ��� ǥ�Ⱑ��

//���� �����Ҵ�
//������ ����
//�����Ͱ� ����
//�ڵ尡 �ڵ�