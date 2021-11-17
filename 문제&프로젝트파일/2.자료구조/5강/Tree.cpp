#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>

//����Ž�� Ʈ�� �����-����Լ� �̿��ϱ�
typedef struct Tree
{
    int data;
    struct Tree* leftlink; //���� �ּ�
    struct Tree* rightlink; //������ �ּ�
}Tree;

//�޴�
void Menu()
{
    printf("< < < = = = = �޴� = = = = > > >\n");
    printf("1.data �߰�\n");
    printf("2.data ����\n"); //��������
    printf("3.preorder\n");
    printf("4.inorder\n");
    printf("5.postorder\n");
    printf("6.data �˻�\n");
    printf("7.����\n");
    printf("====================\n");
    printf("���� : ");
}

//�¿� ��ũ �ʱ�ȭ�� Ʈ����� �����ϰ� �����
Tree* Make_Tree()
{
    Tree* add = (Tree*)malloc(sizeof(Tree));
    add->leftlink = NULL;
    add->rightlink = NULL;
    return add;
}

//������ �߰�
Tree* Add_Data(Tree* Node, int data)
{
    //��������� ����� ����� �ּҺ���
    if (Node == NULL)
    {
        Tree* add = Make_Tree();
        add->data = data;
        return add;
    }

    //�̹� �����ϴ� �����Ͷ��
    if (Node->data == data)
    {
        printf("�Է��Ͻ� %d �����մϴ�\n", data);
    }//�ƴ϶�� ��� �����ؼ� �������� ���ų� ���������� ��
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

//Ž��
void Search(Tree* Node, int data)
{
    //�� ã���� ���
    if (Node == NULL)
    {
        printf("%d �������� �ʽ��ϴ�\n", data);
        return;
    }

    //ã���� ���
    if (Node->data == data) 
    {
        printf("%d �����մϴ�\n", data);
    }//�ƴ϶�� ��� �����ؼ� �������� ���ų� ���������� ��
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

//���� ��ȸ
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

//���� ��ȸ
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

//������ȸ
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

//�Ҵ� ����
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

//���� ���� ������ ã�¿�
Tree* MinNode(Tree* Node)
{
    if (Node->leftlink == NULL) //�����ʿ��� ���� ���� ������ ã��
    {
        return Node;
    }

    Tree* tmp = MinNode(Node->leftlink);

    if (tmp->leftlink == NULL && tmp->rightlink != NULL)//���� �� �����Ͱ� ������ �ڽ��� �ִٸ� 
    {
        Node->leftlink = tmp->rightlink; //���� ����� ���ʿ� ������ �ڽ��� ��ũ�� �־��ְ�
        tmp->rightlink = NULL; //NULL�� �������
    }

    return tmp;
}

//������ ����-��Ʈ ��尡 ������ ���� ���� > �׻� ��Ʈ ��带 ��ȯ
Tree* Delete(Tree* Node, int data)
{
    //������ �����͸� �� ã���� ���
    if (Node == NULL)
    {
        printf("������ �����Ͱ� �����ϴ�.\n");
        return Node;
    }

    //1.������ ��� ã��
    if (Node->data == data)
    {
        Tree* tmp = NULL;

        if (Node->leftlink != NULL && Node->rightlink != NULL) //���� �ڽ��� ����
        {
            tmp = MinNode(Node->rightlink);//�ڽ��� ��ü�� �ڽ��� ã��
            tmp->leftlink = Node->leftlink; //���� �ڱⰡ �������ִ� �ڽ� �־���
            if (Node->rightlink != tmp)//���� �����ؾ��� ����� ������ ù��° ��尡 ��ü���� ���õǾ��� ��� tmp->rightlink �����ϸ� �ȵ�
            {
                tmp->rightlink = Node->rightlink;
            }
        }
        else if (Node->leftlink != NULL) //���� �ڽĸ� ����
        {
            tmp = Node->leftlink;
        }
        else if (Node->rightlink != NULL) //������ �ڽĸ�����
        {
            tmp = Node->rightlink;
        } 
        //�ڽ��� ����
        free(Node);
        return tmp;
    }//������ �����͸� ã�������� �̵� > ��� �����ؼ� ���� �Ǵ� ����������
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
    Tree* root = NULL; //��Ʈ ���

    while (1)
    {
        system("cls");
        Menu();
        scanf("%d", &select);

        switch (select)
        {
        case 1://������ �߰�
            printf("data �Է� : ");
            scanf("%d", &data);
            root = Add_Data(root, data);
            system("pause");
            break;
        case 2: //������ ����
            printf("������ ������ �Է� : ");
            scanf("%d", &data);
            root = Delete(root, data);
            system("pause");
            break;
        case 3: //preorder - ������ȸ
            Preorder(root);
            system("pause");
            break;
        case 4: //inorder - ������ȸ
            Inorder(root);
            system("pause");
            break;
        case 5: //postorder - ������ȸ
            Postorder(root);
            system("pause");
            break;
        case 6: //������ �˻�
            printf("input data : ");
            scanf("%d", &data);
            Search(root,data);
            system("pause");
            break;
        case 7: //����-�Ҵ����� (postorder ����� ��)
            Release(root);
            printf("�Ҵ� ���� �Ϸ�");
            return;
        }
    }

}