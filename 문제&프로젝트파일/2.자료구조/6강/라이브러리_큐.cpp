#include<stdio.h>
#include<queue> //ť
//���̺귯�� ����ϴ� ��

//ť
void Queue_Ex()
{
	std::queue<int> iQueue;

	for (int i = 1; i <= 10; i++)
	{
		iQueue.push(i);
		printf("Front : %d\t Rear : %d\n", iQueue.front(), iQueue.back());
	}

	printf("Size : %d\n", iQueue.size());

	while (!iQueue.empty())//empty�� �����Ͱ� �������� ������ ���� ��ȯ��
	{
		printf("Front : %d\t Rear : %d\n", iQueue.front(), iQueue.back());
		iQueue.pop();
	}
}
void Queue_Menu()
{
	printf("====Queue System====\n");
	printf("1.Enqueue\n");
	printf("2.Dequeue\n");
	printf("3.Exit\n");
	printf("====================\n");
	printf("�Է� : ");
}

void main()
{
	std::queue<int> iQueue;
	int select;
	int num;
	while (1)
	{
		system("cls");
		Queue_Menu();
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("������ �Է� : ");
			scanf("%d", &num);
			iQueue.push(num);
			printf("Front : %d\t Rear : %d\n", iQueue.front(), iQueue.back());
			system("pause");
			break;
		case 2:
			if (iQueue.empty())
			{
				printf("������ �����Ͱ� �����ϴ�\n");
			}
			else
			{
				printf("Front : %d\t Rear : %d\n", iQueue.front(), iQueue.back());
				iQueue.pop();
			}
			system("pause");
			break;
		case 3: //���̺귯���� �˾Ƽ� �Ҵ� ���� ����
			printf("�Ҵ� ���� �Ϸ�");
			return;
		}
	}
}