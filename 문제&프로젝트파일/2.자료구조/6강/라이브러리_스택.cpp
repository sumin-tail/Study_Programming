#include<stdio.h>
#include<stack> //����
//���̺귯�� ����ϴ� ��

//����
void Stack_Ex()
{
	std::stack<int> iStack;
	//������ �ֱ�
	for (int i = 1; i <= 10; i++)
	{
		iStack.push(i);
		printf("Top : %d\n", iStack.top());
	}
	//������
	printf("Size : %d\n", iStack.size());
	//������ ����
	while (!iStack.empty())//empty�� �����Ͱ� �������� ������ ���� ��ȯ��
	{
		printf("Top : %d\n", iStack.top());
		iStack.pop();
	}
}

void Stack_Menu()
{
	printf("====Stack System====\n");
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Exit\n");
	printf("====================\n");
	printf("�Է� : ");
}

void main() 
{
	std::stack<int> iStack;
	int select;
	int num;
	while (1)
	{
		system("cls");
		Stack_Menu();
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("������ �Է� : ");
			scanf("%d", &num);
			iStack.push(num);
			break;
		case 2:
			if (iStack.empty())
			{
				printf("������ �����Ͱ� �����ϴ�\n");
			}
			else
			{
				printf("Pop : %d\n", iStack.top());
				iStack.pop();
			}
			system("pause");
			break;
		case 3: //���̺귯���� �˾Ƽ� �Ҵ� ���� ����
			printf("�Ҵ� ���� �Ϸ�");
			return;
		}
	}
}