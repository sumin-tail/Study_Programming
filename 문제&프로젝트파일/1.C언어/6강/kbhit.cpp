#include<stdio.h>
#include<Windows.h>
#include<conio.h>

void Draw(int Map[][10]);
void Update(int Map[][10]);
void Stop(int Map[][10], int y);

void main()
{
	int Mapy = 10;
	//�� �迭�� 0 ���� �ʱ�ȭ
	int Map[10][10] = { 0 };
	char ch;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			//�� �� �� ��ĭ���� 1�� �־���
			if (x == 9)
			{
				Map[y][x] = 1;
			}
		}
	}
	printf("���� ���ðڽ��ϱ�??\n");
	system("pause"); //� Ű�� ������ �������� �н�
	system("cls"); //ȭ������
	while (1)
	{
		Update(Map);
		//Ű�Է��� ���´ٸ� True �� ��ȯ�Ǵ� ������ 
		if (kbhit())
		{
			ch = getch();
			//���°��� d �Ǵ� D �ϰ�� Map�� y�� ����-1 �ϰ� ��ž�Լ��� �̵�
			if (ch == 'd' || ch == 'D')
			{
				Mapy--;
				Stop(Map, Mapy);
			}
		}
		Draw(Map);
		//0.1 �� ���
		Sleep(100);
	}
}

void Draw(int Map[][10])
{
	//ȭ�� ����
	system("cls");
	//�迭 ���鼭 ���� 1�Ǵ� 2�� ��쿡 �� ��� �ƴ϶�� ����� ���
	//1�� ������ ������ 2�� ���� �� >> Update �Լ����� 2�� �ǵ帮�� ����
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (Map[y][x] == 1|| Map[y][x] == 2)
			{
				printf("��");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("�� ���߱� = d");
}

void Update(int Map[][10])
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			//���� ���ٰ� ���� 1�� ������ ����ġ��
			if (Map[y][x] == 1)
			{
				//��ĭ�� ���� 0���� �ٲ���
				Map[y][x] = 0;
				//�׸��� X��° ĭ�� �� -1 �� 0 ���� ������� 
				//�ش� ���� �� ��ĭ�� �ٽú���(���� ���� ������)  
				if (x - 1 < 0)
				{
					Map[y][9] = 1;
				}
				else//�ƴҰ�� ���� ��ġ�� ��ĭ������ 
				{
					Map[y][x - 1] = 1;
				}
				break;
			}

		}
	}
}

void Stop(int Map[][10], int y)
{
	//�̰� X-���� ĭ�� ��
	for (int x = 0; x < 10; x++)
	{
		//�ش�ĭ�� ���� 1�� ���
		if (Map[y][x] == 1)
		{
			//2�� �ٲ��� > ���� ����
			Map[y][x] = 2;
			return;
		}
	}
}