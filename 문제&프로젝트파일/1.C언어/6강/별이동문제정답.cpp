#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define LEFT -1
#define RIGHT 1

#define WIDTH 10
#define HEIGHT 10

#define MOVESTAR 1
#define STOPSTAR 2

void Draw(int Map[][WIDTH])
{
	system("cls");
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == MOVESTAR || Map[y][x] == STOPSTAR)
				printf("☆");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("별 멈추기 = d");
}

int DirectionCheck(int Map[][WIDTH], int Direction)
{
	if (Map[0][0] == MOVESTAR && Direction == LEFT)
		Direction = RIGHT;
	else if (Map[0][WIDTH - 1] == MOVESTAR && Direction == RIGHT)
		Direction = LEFT;
	return Direction;
}

void Update(int Map[][WIDTH], int Derection)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == MOVESTAR)
			{
				Map[y][x] = 0;
				Map[y][x + Derection] = 1;
				break;
			}
		}
	}
}

void Stop(int Map[][WIDTH], int y)
{
	for (int x = 0; x < WIDTH; x++)
	{
		if (Map[y][x] == MOVESTAR)
		{
			Map[y][x] = STOPSTAR;
			return;
		}
	}
}

void main()
{
	int Stop_y = 10;
	int Map[HEIGHT][WIDTH] = { 0 };
	char ch;
	int Derection = LEFT;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (x == WIDTH - 1)
				Map[y][x] = 1;
		}
	}
	printf("별을 보시겠습니까??\n");
	system("pause");
	system("cls");
	while (1)
	{
		Derection = DirectionCheck(Map, Derection);
		Update(Map, Derection);
		if (kbhit())
		{
			ch = getch();
			if (ch == 'd' || ch == 'D')
				Stop(Map, --Stop_y);
		}
		Draw(Map);
		Sleep(100);
	}
}