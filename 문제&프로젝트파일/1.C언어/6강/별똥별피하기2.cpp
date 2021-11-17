#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include <conio.h>

// ���� ON OFF��
#define TRUE 1
#define FALSE 0
//�� �̵� �Լ� 
#define MOVESTAR 1
#define STOPSTAR 2
#define PLAYER 5
#define WALL 9
#define SKY 0
//�迭 ����/���α��� 
#define WIDTH 10
#define HEIGHT 20

//�Լ� ��
void Menu();
int LevelSetting(char level[][10], int playLevel);
void GamePlay(char level[][10], int playLevel);
void Draw(int Map[][WIDTH], char level[][10], int playLevel, int score);
int Update(int Map[][WIDTH], int score);
void MakeStar(int Map[][WIDTH], int playLevel);
int GameOver(int Map[][WIDTH], int gameOverFlag);
void PlayerMove(int Map[][WIDTH], char ch);
int DownCheck(int downCount, int score);

//�����ϱ��� ���� ���̴� 20 ���α��̴� 10 > �� ���� ù��° ĭ�� ������ ĭ�� ���� 
//���������� ���� �����Ǵ� ���� 8ĭ 1~8ĭ 

//����
//���̵� ��� > �����Ǵ� ���� ���� ������ >> �� �迭�� ���� ������ Ȯ���� ������Ŵ
//���ھ ���� ���ھ� �̻��� �ɰ�� ���� �������� �ӵ��� ������ > �÷��̾��� �̵��ӵ��� �״��

//�������� ���̵������� 5 10 15 20 �ۼ�Ʈ�� Ȯ���� ����.

//���ھ ���� ���̵� ������ ���? 

//���� �Լ�
void main()
{
	int Exit = FALSE; //���� ���� 
	int Select; //���ÿ�

	//������ ���̵� ���� ��� �������� 2���� �迭�� �̿��ϸ� ���� ������ ������
	char level[5][10] = { "Easy" , "Normal" , "Hard" , "Hell" , "Return"};

	int playLevel = 0; //�ʱ� �÷��� ������ Easy

	srand(time(NULL)); //�õ尪 ���� 

	while (!Exit)
	{
		Menu();
		scanf("%d", &Select);

		switch (Select)
		{
		case 1:
			GamePlay(level ,playLevel);
			break;
		case 2:
			playLevel = LevelSetting(level, playLevel);
			break;
		case 3:
			Exit = TRUE;
		}
	}
}

//�޴�
void Menu()
{
	system("cls");
	printf("====���˺� ���ϱ�====\n");
	printf("    1.���� ����\n");
	printf("    2.���̵� ����\n");
	printf("    3.����\n");
}

//���� ����
int LevelSetting(char level[][10], int playLevel)
{
	int flag;

	while (true)
	{
		system("cls");
		printf("====%s====\n", level[playLevel]);
		printf("=======���̵� ����=======\n");
		//2���� �迭�� �̿��ؼ� �ѹ��� �¶�� ����
		for (int i = 0; i < 5; i++)
		{
			printf("%d.%s\n", i + 1, level[i]); 
		}
		printf("�Է� : ");
		scanf("%d", &flag);
		if (flag == 5) //������ ��� �޴��� ���ư�
		{
			return playLevel;
		}
		playLevel = flag-1; //�迭�� �ε����� �׻� 0 ���� �����̶����� ��������
	}

}

//�� ��ο�
void Draw(int Map[][WIDTH], char level[][10], int playLevel, int score)
{
	system("cls");
	printf("====%s====\n", level[playLevel]);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == MOVESTAR || Map[y][x] == STOPSTAR)
				printf("��");
			else if(Map[y][x] == WALL)
				printf("��");
			else if (Map[y][x] == PLAYER)
				printf("��");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("Score = %d" , score);
}

//���� �÷���
void GamePlay(char level[][10], int playLevel)
{
	int score = 0; //����
	char ch;
	int gameOverFlag = 0;
	int downCount=0;

	int Map[HEIGHT][WIDTH] = { SKY };
	//�ʿ� �� ���� > ���� ���������ʴ� Ư��������
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			//�� �� ù��°�� ��ĭ���� 9�� �־���(��)
			if (x == 0 || x == 9)
			{
				Map[y][x] = WALL;
			}
		}
	}
	//�ʿ� �÷��̾� �ʱ���ġ ����
	Map[HEIGHT - 1][WIDTH / 2] = { 5 };

	while (!gameOverFlag)
	{
		downCount = DownCheck(downCount, score);

		if(downCount == 0)
		{
			score = Update(Map, score);
			MakeStar(Map, playLevel);
			Draw(Map, level, playLevel, score);
		}

		//Ű�Է��� ���´ٸ� True �� ��ȯ�Ǵ� ������ 
		if (kbhit())
		{
			ch = getch();
			PlayerMove(Map, ch);
			Draw(Map, level, playLevel, score);
		}

		gameOverFlag = GameOver(Map, gameOverFlag);
		Sleep(20); //0.02��
		downCount++;
	}
	printf(" ���ӿ��� ");
	system("pause");
}

//�� ������Ʈ �Լ�
//1.��� ���� ��ĭ�� �Ʒ��� ������. 
//3.���� ��ġ�� y�� ���� ��� ���ھ 1 �ø���. 
int Update(int Map[][WIDTH], int score)
{
	//���� ��ĭ�� �Ʒ��� ���� 
	//�� y���� ��������? 
	//1) ������ �Ʒ��� �۾��� ���� ��� ���� �Ʒ��� ���ÿ� ���� �����Ұ�� ���� ��ħ
	//2) �����ٷ� ������ ���� y�� for���� �� ���� �Ʒ��� ������ > �ᱹ ���ھ ��� ���� > �÷��̾ ������� ���ӿ��� üũ X
	for (int y = HEIGHT-1; y >= 0; y--)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			//���� �����̰� ���� ���������϶�
			if (Map[y][x] == MOVESTAR && y == HEIGHT - 1)
			{
			    Map[y][x] = 0;
			    score += 1;
			}
			else if (Map[y][x] == MOVESTAR)
			{
				Map[y][x] = 0;
				Map[y+1][x] = 1;
			}
		}
	}

	return score;
}

//�� ��ܿ� ���� �� ����
void MakeStar(int Map[][WIDTH], int playLevel)
{
	int make;
	make = (playLevel + 1) * 5;

	//�� ���� Ȯ���� 20 40 60 80 ���� �ߴµ� �ʹ� ������
	//5 10 15 20 ���� ����
	for (int x = 1; x < WIDTH-1; x++)
	{
		int Num = (rand() % 100)+1;//1 ���� 100����
		if (make >= Num) 
		{
			Map[0][x] = MOVESTAR;
		}

	}
}

//�� ��ĭ �Ʒ��� �÷��̾ ������ ��� ���ӿ���
//���� ������Ʈ�� �÷��̾ ���ӿ����� �Ǵ��� �ȵǴ����� üũ
int GameOver(int Map[][WIDTH], int gameOverFlag)
{
	for (int x = 0; x < WIDTH; x++)
	{
		if (Map[HEIGHT-2][x] == MOVESTAR && Map[HEIGHT-1][x] == 5)
		{
			return 1;
		}
	}
	return 0;
}

//�÷��̾� ������
void PlayerMove(int Map[][WIDTH], char ch)
{
	//�÷��̾��� ��ġ�� ã�´�. > �÷��̾��� ��ġ�� �׻� ���� �� �Ʒ��ʿ� �����ؾ��Ѵ�.
	for (int x = 1; x < WIDTH; x++)
	{
		if (Map[HEIGHT-1][x] == PLAYER) 
		{
			//�� �÷��̾ �̵��� �� ������ �ϴ� ���⿡ ���� ���� ��� ��������.
			//���°��� d �Ǵ� D �ϰ�� ������ �̵�
			if ((ch == 'd' || ch == 'D')&& Map[HEIGHT - 1][x + 1] != WALL)
			{
				Map[HEIGHT - 1][x] = SKY;
				Map[HEIGHT - 1][x + 1] = PLAYER;
				break;
			}
			//���°��� a �Ǵ� A �ϰ�� ���� �̵�
			else if ((ch == 'a' || ch == 'A') && Map[HEIGHT - 1][x - 1] != WALL)
			{
				Map[HEIGHT - 1][x] = SKY;
				Map[HEIGHT - 1][x - 1] = PLAYER;
				break;
			}
		}
	}
}

int DownCheck(int downCount,int score)
{
	//���ھ� 10���� �������� 0.02�ʾ� ��������
	//0 = 0.2�� 10= 0.18 ....  100�̸� 0.02��(�ִ�ӵ�)
	if (10-(score/10) <= downCount)
	{
		return 0;
	}

	return downCount;
}
