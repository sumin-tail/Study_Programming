#include<stdio.h>
#include<Windows.h>
#include<conio.h>

#define LEFT -1
#define RIGHT 1

#define START 0
#define LENGHT 10

#define MOVESTAR 1
#define STOPSTAR 2
#define SKY 0

#define WAIT 100

void Draw(int Map[][LENGHT]);
void Update(int Map[][LENGHT], int way);
void Stop(int Map[][LENGHT], int y);
int Direction(int Map[][LENGHT], int way);

void main()
{
	int way = LEFT;
	int Mapy = LENGHT;
	//�� �迭�� 0 ���� �ʱ�ȭ
	int Map[LENGHT][LENGHT] = { 0 };
	char ch;
	for (int y = START; y < LENGHT; y++)
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
		Update(Map, way);
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
		//����üũ
		way = Direction(Map, way);
		//0.1 �� ���
		Sleep(WAIT);
	}
}

void Draw(int Map[][LENGHT])
{
	//ȭ�� ����
	system("cls");
	//�迭 ���鼭 ���� 1�Ǵ� 2�� ��쿡 �� ��� �ƴ϶�� ����� ���
	//1�� ������ ������ 2�� ���� �� >> Update �Լ����� 2�� �ǵ帮�� ����
	for (int y = START; y < LENGHT; y++)
	{
		for (int x = START; x < LENGHT; x++)
		{
			if (Map[y][x] == MOVESTAR || Map[y][x] == STOPSTAR)
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

void Update(int Map[][LENGHT], int way)
{
	for (int y = START; y < LENGHT; y++)
	{
		for (int x = START; x < LENGHT; x++)
		{
			//���� ���ٰ� ���� 1�� ������ ����ġ��
			if (Map[y][x] == MOVESTAR)
			{
				//��ĭ�� ���� 0���� �ٲ���
				Map[y][x] = SKY;
				Map[y][x + way] = MOVESTAR;
				break;
			}

		}
	}

}

void Stop(int Map[][LENGHT], int y)
{
	//�̰� X-���� ĭ�� ��
	for (int x = START; x < LENGHT; x++)
	{
		//�ش�ĭ�� ���� 1�� ���
		if (Map[y][x] == MOVESTAR)
		{
			//2�� �ٲ��� > ���� ����
			Map[y][x] = STOPSTAR;
			return;
		}
	}
}

int Direction(int Map[][LENGHT], int way)
{
	//�����̵��϶��� -1 �� ������ �̵��϶��� +1�� �������
	//���������� �̵��ؾ��ϴ� ��Ȳ
	if (Map[START][START] == MOVESTAR && way == LEFT)
	{
		return RIGHT;
	}
	//�ަU���� �̵��ؾ��ϴ� ��Ȳ
	else if (Map[START][LENGHT-1] == MOVESTAR && way == RIGHT)
	{
		return LEFT;
	}
	return way;
}
