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
	//맵 배열을 0 으로 초기화
	int Map[LENGHT][LENGHT] = { 0 };
	char ch;
	for (int y = START; y < LENGHT; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			//각 줄 맨 끝칸에는 1을 넣어줌
			if (x == 9)
			{
				Map[y][x] = 1;
			}
		}
	}
	printf("별을 보시겠습니까??\n");
	system("pause"); //어떤 키든 누르면 다음으로 패스
	system("cls"); //화면정리
	while (1)
	{
		Update(Map, way);
		//키입력이 들어온다면 True 가 반환되니 안으로 
		if (kbhit())
		{
			ch = getch();
			//들어온값이 d 또는 D 일경우 Map의 y축 값을-1 하고 스탑함수로 이동
			if (ch == 'd' || ch == 'D')
			{
				Mapy--;
				Stop(Map, Mapy);
			}
		}
		Draw(Map);
		//방향체크
		way = Direction(Map, way);
		//0.1 초 대기
		Sleep(WAIT);
	}
}

void Draw(int Map[][LENGHT])
{
	//화면 정리
	system("cls");
	//배열 돌면서 값이 1또는 2인 경우에 별 출력 아니라면 빈공간 출력
	//1은 멈추지 않은별 2는 멈춘 별 >> Update 함수에서 2는 건드리지 않음
	for (int y = START; y < LENGHT; y++)
	{
		for (int x = START; x < LENGHT; x++)
		{
			if (Map[y][x] == MOVESTAR || Map[y][x] == STOPSTAR)
			{
				printf("☆");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("별 멈추기 = d");
}

void Update(int Map[][LENGHT], int way)
{
	for (int y = START; y < LENGHT; y++)
	{
		for (int x = START; x < LENGHT; x++)
		{
			//만약 돌다가 값이 1인 구간을 마추치면
			if (Map[y][x] == MOVESTAR)
			{
				//그칸의 값을 0으로 바꿔줌
				Map[y][x] = SKY;
				Map[y][x + way] = MOVESTAR;
				break;
			}

		}
	}

}

void Stop(int Map[][LENGHT], int y)
{
	//이건 X-가로 칸만 돔
	for (int x = START; x < LENGHT; x++)
	{
		//해당칸의 값이 1일 경우
		if (Map[y][x] == MOVESTAR)
		{
			//2로 바꿔줌 > 별을 멈춤
			Map[y][x] = STOPSTAR;
			return;
		}
	}
}

int Direction(int Map[][LENGHT], int way)
{
	//왼쪽이동일때는 -1 을 오른쪽 이동일때는 +1을 해줘야함
	//오른쪽으로 이동해야하는 상황
	if (Map[START][START] == MOVESTAR && way == LEFT)
	{
		return RIGHT;
	}
	//왼쪾으로 이동해야하는 상황
	else if (Map[START][LENGHT-1] == MOVESTAR && way == RIGHT)
	{
		return LEFT;
	}
	return way;
}
