#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>

//����Լ��� �̿��Ͽ� ���� ����Ʈ�� ������ ��
//���� �� ����� ����, ����, �˻�, ����
//�������� �����ϸ� �Ҵ� �ߴ� �� ���� �ʱ�
//����, ���� �Լ����� �˻� �Լ� �̿��ϱ�

//�л� ������ ���� ����Ʈ ����
typedef struct Student
{
    char name[10]; //�̸�
    int age; //����
    char address[30]; //�ּ�
    //������ ����
    int korean;
    int math;
    int english;
    struct Student* link; 
}Student;

//�޴�
void Menu()
{
    printf("< < < = = = = �޴� = = = = > > >\n");
    printf("1.�л� ���\n");
    printf("2.�л� �˻�\n");
    printf("3.�л� ���\n");
    printf("4.�л� ����\n");
    printf("5.�л� ����\n");
    printf("6.����\n");
    printf("====================\n");
    printf("���� : ");
}

//��ü �Ҵ� ����
void Release(Student* Node)
{
    if (Node == NULL) //Node �� NULL���� Ȯ��
    {
        return;
    }//NODE�� NULL == ���� �ؼ� ���ư� ����ü�� ���� ó���� �߰��� ����ü��� ��
    Release(Node->link);//Node �� NULL�� �� ������ ����Լ��� �Ʒ��� ������
    //�������� ������ ���� �Ʒ����� ������ ���ʷ� �Ҵ� ������
    free(Node);//���� ������ ����ü �Ҵ� ����
}

//�˻� �Լ� > ������ �ּҹ�ȯ ������ NULL�� ��ȯ
Student* Search(Student* Node, char name[])
{
    if (Node == NULL)// ������ �Դµ��� ã�����ߴٸ�
    {
        return NULL;
    }

    if (strcmp (Node->name , name) == 0 )//�̸��� ���� ������ ã���� �ּҸ� ������
    {
        printf("�л� ���� �˻� �Ϸ�\n");
        return Node;
    }

    return Search(Node->link, name);//�ش��忡 ������ �������� �ǳʰ�
}

//�л� ���� ���
void Student_Information(Student* Node)
{
    if (Node == NULL)
    {
        printf("�˻��ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�.\n");
        return;
    }

    int max = Node->korean + Node->english + Node->math; //�հ�����
    float average = (float)max / 3;
    char rank;
    if (average >= 90)
    {
        rank = 'A';
    }
    else if (average >= 80)
    {
        rank = 'B';
    }
    else if (average >= 70)
    {
        rank = 'C';
    }
    else if (average >= 60)
    {
        rank = 'D';
    }
    else
    {
        rank = 'F';
    }

    printf("< < = = = = = Information = = = = = > >\n");
    printf("�л� �̸� : %s\n", Node->name);
    printf("�л� ���� : %d ��\n", Node->age);
    printf("�л� �ּ� : %s\n", Node->address);
    printf("���� ���� : %d ��\n", Node->korean);
    printf("���� ���� : %d ��\n", Node->english);
    printf("���� ���� : %d ��\n", Node->math);
    printf("�հ� ���� : %d ��\n", max);
    printf("��� ���� : %.2f ��\n", average);
    printf("�л� ��� : %c ���\n", rank);

}

//�л� ��ü ���
void All_Student_Print(Student* Node)
{
    if (Node == NULL)
    {
        return;
    }
    printf("\t  %s", Node->name);
    printf("\t%d", Node->age);
    printf("\t\t%s\n", Node->address);
    All_Student_Print(Node->link);
}

//�л��߰� - ����� �׻� �����Ѵ� > ���� ù��°�� �� ����ּҸ� �׻� ��ȯ
Student* Student_Add(Student* Node)
{
    if (Node == NULL) //�����尡 ���ϰ��
    {
        //�� �����Ҵ��ϰ� �ּ�����
        Student* add = (Student*)malloc(sizeof(Student));
        add->link = NULL;

        //�л������Է�
        system("cls");
        printf("�л� �̸� �Է� : ");
        scanf("%s", add->name);
        printf("%s �л� ���� �Է� : ", add->name);
        scanf("%d", &add->age);
        printf("%s �л� �ּ� �Է� : ", add->name);
        scanf("%s", add->address);
        printf("%s �л� ���� ���� : ", add->name);
        scanf("%d", &add->korean);
        printf("%s �л� ���� ���� : ", add->name);
        scanf("%d", &add->english);
        printf("%s �л� ���� ���� : ", add->name);
        scanf("%d", &add->math);
        printf("�л� ���� �Է� �Ϸ�\n");
        //������ ���� ���� ���� �л��� �ּҸ� ��� ���ƿ´�. 
        return add; //���� �̰� ��������� ù��°�� ��� �׷��� ��尡 ����Ű�Եǰ�     
    }
    //�ƴ϶�� ���� ����� ��ũ�� ���Ž����ش�.

    Node->link = Student_Add(Node->link);//����Լ�
    return Node;
}

//�л� ����
void Student_Retouch(Student* Node)
{
    int select = 0;
    int data;
    char change[30];

    if (Node == NULL)//�ش��л��� ���ٴ� ���̴� ����
    {
        printf("ã�� �л��� �����ϴ�.\n");
        return;
    }

    while (select !=5)
    {
        system("cls");
        Student_Information(Node);// �л� ������ ���
        printf("\n");
        printf("������ �׸��� ���� �Ͻÿ�\n");
        printf("1.�̸� 2.���� 3.�ּ� 4.���� 5.��������\n");
        printf("���� : ");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            printf("���� �̸� : %s\n", Node->name);
            printf("������ �̸� : ");
            scanf("%s", &change);
            printf("%s -> %s �� �̸� ���� �Ϸ�\n", Node->name , change);
            strcpy(Node->name, change); //���ڿ��� ������ �ȵǴ� strcpy ���
            system("pause");
            break;
        case 2:
            printf("���� ���� : %d ��\n", Node->age);
            printf("������ ���� :    ��");
            printf("\b\b\b\b\b\b");
            scanf("%d", &data);
            printf("%d �� -> %d �� �� ���� ���� �Ϸ�\n", Node->age, data);
            Node->age = data;
            system("pause");
            break;
        case 3:
            printf("���� �ּ� : %d \n", Node->address);
            printf("������ �ּ� : ");
            scanf("%s", &change);
            printf("%s -> %s �� �ּ� ���� �Ϸ�\n", Node->address, change);
            strcpy(Node->address, change); //���ڿ�
            system("pause");
            break;
        case 4:
            printf("���� ����\n");
            printf("���� : %d ���� : %d ���� : %d\n", Node->korean, Node->english, Node->math);
            printf("������ ���� ���� : ");
            scanf("%d", &data);
            Node->korean = data;
            printf("������ ���� ���� : ");
            scanf("%d", &data);
            Node->english = data;
            printf("������ ���� ���� : ");
            scanf("%d", &data);
            Node->math = data;
            printf("���� ���� �Ϸ�\n");
            system("pause");
            break;
        case 5:
            printf("������ �����մϴ�.\n");
            system("pause");
            break;
        }
    }
   
}

//�л� ���� - �л� �߰�ó�� ���� ���ֱ�
Student* Student_Delete(Student* Node, char name[])
{
    //��Ī ����~
    if (Node == NULL)// ���� ��尡 ���ϰ��
    {
        return Node;
    }

    //������ ��忡 �����ϸ� ��������� �ּҸ� ���� <
    if (strcmp(Node->name, name) == 0)//������ ��带 ã����
    {
        Student* tmp; //������
        tmp = Node->link;// ������ ��� ��������� �ּҸ� ���
        free(Node);//�������� �ּ� �Ҵ�����
        printf("���� �Ϸ�\n");
        system("pause");
        return tmp;//������ ��� ���� ��ũ�� ���� ������� �ּ� tmp�� ������
    }

    Node->link = Student_Delete(Node->link, name); //�ش��忡 ������ �������� �ǳʰ�
    return Node; //���� �����ʱ�
    //~��Ī ����
}

void main()
{
    int select;
    int num;
    char searchname[10];
    int count = 0;
    Student* Head = NULL; //�Ӹ�

    while (1)
    {
        system("cls");
        Menu();
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            Head = Student_Add(Head);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("�˻��� �̸� �Է� : ");
            scanf("%s", searchname);
            Student_Information(Search(Head, searchname));
            system("pause");
            break;
        case 3:
            system("cls");
            printf("< < = = = = = Information = = = = = > >\n");
            printf("\n");
            printf("\t�л��̸�\t�л�����\t�л��ּ�\n");
            All_Student_Print(Head);
            printf("<�л� �������� ������ �˻��� �̿��ϼ���!!>\n");
            system("pause");
            break;
        case 4:
            system("cls");
            printf("������ �л� �̸���? ");
            scanf("%s", searchname);
            Student_Retouch(Search(Head, searchname));
            break;
        case 5:
            system("cls");
            if (Head == NULL)
            {
                printf("�ƹ��� �����Ͱ� �����ϴ�.\n");
                system("pause");
                break;
            }
            printf("������ �л� �̸�: ");
            scanf("%s", searchname);
            Head = Student_Delete(Head, searchname); //��尻��
            break;
        case 6:
            Release(Head);
            printf("�Ҵ� ���� �Ϸ�");
            return;
        }
    }

}