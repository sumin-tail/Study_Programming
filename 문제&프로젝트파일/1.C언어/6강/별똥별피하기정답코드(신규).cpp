#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#define NULL 0
#define WALL 1
#define CHARACTER 2
#define STAR 3
#define X 1
#define Y 0
#define WIDTH 10
#define HEIGHT 20
#define LEFT 'a'
#define RIGHT 'd'
#define UPGRADE 10
#define EASY 1
#define NORMAL 2
#define HARD 3
#define HELL 4

void ShowDifficulty(int Difficulty);
void Init(int Map[][WIDTH], int character[]);
void MapDraw(int Map[][WIDTH], int Score, int Difficulty);
int CheckScore(int Score, int Map[][WIDTH]);
void Input(int Map[][WIDTH], int character[]);
void CreateStar(int Map[][WIDTH], int  StarCount, int StarCreatePercent);
int Update(int Map[][WIDTH]);
void Menu();
void GamePlay(int Map[][WIDTH], int character[], int StarCount, int StarCreatePercent, int Difficulty, int StarSpeed, int CreateStarSpeed);
int SetDifficulty(int Difficulty);
void ShowDifficulty(int Difficulty);


void Init(int Map[][WIDTH], int character[])
{
	srand(time(NULL));
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (x == 0 || x == WIDTH - 1)
				Map[y][x] = WALL;
			else
				Map[y][x] = NULL;
		}
	}

	character[X] = WIDTH / 2;
	character[Y] = HEIGHT - 1;
	Map[character[Y]][character[X]] = CHARACTER;
}

void MapDraw(int Map[][WIDTH], int Score, int Difficulty)
{
	system("cls");
	ShowDifficulty(Difficulty);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == CHARACTER)
				printf("옷");
			else if (Map[y][x] == STAR)
				printf("☆");
			else if (Map[y][x] == WALL)
				printf("│");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("Score = %d", Score);
}

void Input(int Map[][WIDTH], int character[])
{
	char ch = getch();
	Map[character[Y]][character[X]] = NULL;
	switch (ch)
	{
	case LEFT:
		if (Map[character[Y]][character[X] - 1] != WALL)
			character[X]--;
		break;
	case RIGHT:
		if (Map[character[Y]][character[X] + 1] != WALL)
			character[X]++;
		break;
	}
	Map[character[Y]][character[X]] = CHARACTER;
}

int CheckScore(int Score, int Map[][WIDTH])
{
	for (int x = 0; x < WIDTH; x++)
	{
		if (Map[HEIGHT - 1][x] == STAR)
		{
			Map[HEIGHT - 1][x] = NULL;
			Score++;
		}
	}
	return Score;
}

void CreateStar(int Map[][WIDTH], int  StarCount, int StarCreatePercent)
{
	for (int i = 0; i < StarCount; i++)
	{
		if (rand() % StarCreatePercent == 0)
		{
			int x = (rand() % 8) + 1;
			Map[0][x] = STAR;
		}
	}
}

int Update(int Map[][WIDTH])
{
	for (int y = HEIGHT - 1; y >= 0; y--)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == STAR)
			{
				Map[y][x] = NULL;
				if (Map[y + 1][x] == CHARACTER)
					return 1;
				else if (y + 1 < HEIGHT)
					Map[y + 1][x] = STAR;
			}
		}
	}

	return 0;
}

void Menu()
{
	printf("=====별똥별 피하기===\n");
	printf("     1.게임 시작\n");
	printf("     2.난이도 조절\n");
	printf("     3.종료\n");
}

void GamePlay(int StarCount, int StarCreatePercent, int Difficulty, int StarSpeed, int CreateStarSpeed)
{
	int Map[HEIGHT][WIDTH];
	int character[2];
	int Score = 0;
	int LastScore = 0;
	int GameOver = 0;
	int SpeedCount = 0;
	int CreateCount = 0;
	int MapDrawState = FALSE;
	Init(Map, character);
	MapDraw(Map, Score, Difficulty);
	while (!GameOver)
	{
		if (MapDrawState)
			MapDraw(Map, Score, Difficulty);

		MapDrawState = FALSE;
		Score = CheckScore(Score, Map);
		if (LastScore <= Score)
		{
			StarCreatePercent--;
			LastScore += 10;
			if (CreateStarSpeed - 1 >= 0)
				CreateStarSpeed--;
			if (StarSpeed - 1 >= 0)
				StarSpeed--;
		}
		if (kbhit())
		{
			Input(Map, character);
			MapDrawState = TRUE;
		}
		if (CreateCount >= CreateStarSpeed)
		{
			CreateCount = 0;
			CreateStar(Map, StarCount, StarCreatePercent);
			MapDrawState = TRUE;
		}
		if (SpeedCount >= StarSpeed)
		{
			SpeedCount = 0;
			GameOver = Update(Map);
			MapDrawState = TRUE;
		}
		Sleep(10);
		SpeedCount++;
		CreateCount++;
	}
	printf("게임 종료\n");
	system("pause");
}

int SetDifficulty(int Difficulty)
{
	int Select;
	system("cls");
	ShowDifficulty(Difficulty);
	printf("=======난이도 조절=======\n");
	printf("1.Easy\n");
	printf("2.Normal\n");
	printf("3.Hard\n");
	printf("4.Hell\n");
	printf("5.Return\n");
	printf("입력 : ");
	scanf("%d", &Select);
	return Select;
}

void ShowDifficulty(int Difficulty)
{
	switch (Difficulty)
	{
	case EASY:
		printf("====Easy====\n");
		break;
	case NORMAL:
		printf("====Normal====\n");
		break;
	case HARD:
		printf("====Hard====\n");
		break;
	case HELL:
		printf("====Hell====\n");
		break;
	}
}

void main()
{
	int Select;
	int StarCount = 5;
	int StarCreatePercent = 50;
	int Difficulty = EASY;
	int LoopState = 1;
	int StarSpeed = 15;
	int CreateStarSpeed = 5;

	while (1)
	{
		system("cls");
		Menu();
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			GamePlay(StarCount, StarCreatePercent, Difficulty, StarSpeed, CreateStarSpeed);
			break;
		case 2:
			LoopState = 1;
			while (LoopState)
			{
				switch (SetDifficulty(Difficulty))
				{
				case EASY:
					StarCount = 5;
					StarCreatePercent = 50;
					StarSpeed = 13;
					CreateStarSpeed = 4;
					Difficulty = EASY;
					break;
				case NORMAL:
					StarCount = 7;
					StarCreatePercent = 45;
					Difficulty = NORMAL;
					StarSpeed = 11;
					CreateStarSpeed = 3;
					break;
				case HARD:
					StarCount = 10;
					StarCreatePercent = 40;
					Difficulty = HARD;
					StarSpeed = 9;
					CreateStarSpeed = 2;
					break;
				case HELL:
					StarCount = 13;
					StarCreatePercent = 35;
					Difficulty = HELL;
					StarSpeed = 7;
					CreateStarSpeed = 1;
					break;
				case 5:
					LoopState = 0;
					break;
				}
			}
			break;
		case 3:
			return;
		}

	}
}
