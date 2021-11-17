#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include <conio.h>

// 게임 ON OFF용
#define TRUE 1
#define FALSE 0
//별 이동 함수 
#define MOVESTAR 1
#define STOPSTAR 2
#define PLAYER 5
#define WALL 9
#define SKY 0
//배열 가로/세로길이 
#define WIDTH 10
#define HEIGHT 20

//함수 존
void Menu();
int LevelSetting(char level[][10], int playLevel);
void GamePlay(char level[][10], int playLevel);
void Draw(int Map[][WIDTH], char level[][10], int playLevel, int score);
int Update(int Map[][WIDTH], int score);
void MakeStar(int Map[][WIDTH], int playLevel);
int GameOver(int Map[][WIDTH], int gameOverFlag);
void PlayerMove(int Map[][WIDTH], char ch);
int DownCheck(int downCount, int score);

//별피하기의 세로 길이는 20 가로길이는 10 > 단 가로 첫번째 칸과 마지막 칸은 벽임 
//실질적으로 벌이 생성되는 같은 8칸 1~8칸 

//조건
//난이도 상승 > 생성되는 별의 수가 많아짐 >> 각 배열에 별이 생성될 확률을 증가시킴
//스코어가 일정 스코어 이상이 될경우 별이 내려오는 속도가 빨라짐 > 플레이어의 이동속도는 그대로

//별생성은 난이도에따라 5 10 15 20 퍼센트의 확률로 생성.

//스코어에 따른 난이도 조절은 어떻게? 

//메인 함수
void main()
{
	int Exit = FALSE; //게임 종료 
	int Select; //선택용

	//일일이 난이도 변경 출력 귀찮은데 2차원 배열을 이용하면 쉽고 편하지 않을까
	char level[5][10] = { "Easy" , "Normal" , "Hard" , "Hell" , "Return"};

	int playLevel = 0; //초기 플레이 레벨은 Easy

	srand(time(NULL)); //시드값 적용 

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

//메뉴
void Menu()
{
	system("cls");
	printf("====별똥별 피하기====\n");
	printf("    1.게임 시작\n");
	printf("    2.난이도 조절\n");
	printf("    3.종료\n");
}

//레벨 세팅
int LevelSetting(char level[][10], int playLevel)
{
	int flag;

	while (true)
	{
		system("cls");
		printf("====%s====\n", level[playLevel]);
		printf("=======난이도 조절=======\n");
		//2차원 배열을 이용해서 한번에 좌라락 뽑음
		for (int i = 0; i < 5; i++)
		{
			printf("%d.%s\n", i + 1, level[i]); 
		}
		printf("입력 : ");
		scanf("%d", &flag);
		if (flag == 5) //리턴일 경우 메뉴로 돌아감
		{
			return playLevel;
		}
		playLevel = flag-1; //배열의 인덱스는 항상 0 부터 시작이란것을 잊지말자
	}

}

//맵 드로우
void Draw(int Map[][WIDTH], char level[][10], int playLevel, int score)
{
	system("cls");
	printf("====%s====\n", level[playLevel]);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x] == MOVESTAR || Map[y][x] == STOPSTAR)
				printf("☆");
			else if(Map[y][x] == WALL)
				printf("│");
			else if (Map[y][x] == PLAYER)
				printf("웃");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("Score = %d" , score);
}

//게임 플레이
void GamePlay(char level[][10], int playLevel)
{
	int score = 0; //점수
	char ch;
	int gameOverFlag = 0;
	int downCount=0;

	int Map[HEIGHT][WIDTH] = { SKY };
	//맵에 벽 생성 > 벽은 움직이지않는 특수문자임
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			//각 줄 첫번째와 끝칸에는 9를 넣어줌(벽)
			if (x == 0 || x == 9)
			{
				Map[y][x] = WALL;
			}
		}
	}
	//맵에 플레이어 초기위치 생성
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

		//키입력이 들어온다면 True 가 반환되니 안으로 
		if (kbhit())
		{
			ch = getch();
			PlayerMove(Map, ch);
			Draw(Map, level, playLevel, score);
		}

		gameOverFlag = GameOver(Map, gameOverFlag);
		Sleep(20); //0.02초
		downCount++;
	}
	printf(" 게임오버 ");
	system("pause");
}

//맵 업데이트 함수
//1.모든 별을 한칸씩 아래로 내린다. 
//3.별의 위치가 y의 끝일 경우 스코어를 1 올린다. 
int Update(int Map[][WIDTH], int score)
{
	//별을 한칸씩 아래로 내림 
	//왜 y축은 역순으로? 
	//1) 위에서 아래로 작업을 했을 경우 위와 아래에 동시에 별이 존재할경우 별이 겹침
	//2) 다음줄로 내려간 별이 y축 for문이 또 돌때 아래로 내려감 > 결국 스코어가 계속 오름 > 플레이어도 사라져서 게임오버 체크 X
	for (int y = HEIGHT-1; y >= 0; y--)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			//별이 움직이고 별이 마지막줄일때
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

//맨 상단에 새로 별 생성
void MakeStar(int Map[][WIDTH], int playLevel)
{
	int make;
	make = (playLevel + 1) * 5;

	//별 생성 확률을 20 40 60 80 으로 했는데 너무 높은듯
	//5 10 15 20 으로 변경
	for (int x = 1; x < WIDTH-1; x++)
	{
		int Num = (rand() % 100)+1;//1 에서 100까지
		if (make >= Num) 
		{
			Map[0][x] = MOVESTAR;
		}

	}
}

//별 한칸 아래에 플레이어가 존재할 경우 게임오버
//다음 업데이트때 플레이어가 게임오버가 되는지 안되는지를 체크
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

//플레이어 움직임
void PlayerMove(int Map[][WIDTH], char ch)
{
	//플레이어의 위치를 찾는다. > 플레이어의 위치는 항상 세로 맨 아래쪽에 존재해야한다.
	for (int x = 1; x < WIDTH; x++)
	{
		if (Map[HEIGHT-1][x] == PLAYER) 
		{
			//단 플레이어가 이동할 때 가고자 하는 방향에 벽이 있을 경우 갈수없음.
			//들어온값이 d 또는 D 일경우 오른쪽 이동
			if ((ch == 'd' || ch == 'D')&& Map[HEIGHT - 1][x + 1] != WALL)
			{
				Map[HEIGHT - 1][x] = SKY;
				Map[HEIGHT - 1][x + 1] = PLAYER;
				break;
			}
			//들어온값이 a 또는 A 일경우 왼쪽 이동
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
	//스코어 10점을 기준으로 0.02초씩 빨라지기
	//0 = 0.2초 10= 0.18 ....  100이면 0.02초(최대속도)
	if (10-(score/10) <= downCount)
	{
		return 0;
	}

	return downCount;
}
