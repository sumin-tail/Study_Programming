#include<stdio.h>
#include<conio.h>
#include<Windows.h>
//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////
#define WALL 1
#define NULL 0
#define Y 0
#define X 1
#define CHARACTER 2
#define ENTRY_POTAL 10
#define EXIT_POTAL 20
#define LEFT 75 // 키보드 인식받았을 때의 아스키 코드
#define RIGHT 77
#define UP 72
#define DOWN 80 // 이동할 때 쓴다
#define WIDTH 10
#define HEIGHT 10

//함수
void Init();
void MapDraw();
void Move();
void MoveCheck();

int map[HEIGHT][WIDTH] = {
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	0,	2,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	0,	10,	0,	0,	0,	0,	20,	0,	1 },
	{ 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
	{ 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 } };

int character[2]; //이 세개는
int Entry_Potal[2]; //1차원 배열 - 첫번째 인덱스에 Y 좌표가 2번째 인덱스에 X좌표가 들어감
int Exit_Potal[2];

int LastObjectIndex = NULL;

void main() 
{
	Init();
	while (1)
	{
		MapDraw();
		Move();
	}
}

void Init()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)
			{
				character[X] = x;
				character[Y] = y;
			}
			else if(map[y][x] == ENTRY_POTAL)
			{
				Entry_Potal[X] = x;
				Entry_Potal[Y] = y;
			}
			else if (map[y][x] == EXIT_POTAL)
			{
				Exit_Potal[X] = x;
				Exit_Potal[Y] = y;
			}
		}
	}
}

void MapDraw() 
{
	for (int y = 0; y < WIDTH; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
			{
				printf("▩");
			}
			else if(map[y][x] == CHARACTER)
			{
				RED //이 아래쪽은 레드 색상으로 출력
					printf("♧");
				ORIGINAL //다시 오리지널 색으로
			}
			else if (map[y][x] == ENTRY_POTAL)
			{
				BLUE //이 아래쪽은 블루 색상으로 출력
					printf("◎");
				ORIGINAL
			}
			else if (map[y][x] == EXIT_POTAL)
			{
				YELLOW
					printf("●");
				ORIGINAL
			}
			else if (map[y][x] == NULL) 
			{
				printf("  ");
			}
		}
		printf("\n"); //가로 하나가 끝날때마다 줄 바꿈
	}
}

void Move() 
{
	char ch; 
	ch = getch(); //자판인식 받음
	system("cls"); //콘솔창 클리어
	map[character[Y]][character[X]] = LastObjectIndex; //캐릭터의 x축과 y축에 NULL넣음
	//즉 캐릭터가 이동하고 난 후의 자리를 빈공간으로 만들어줌
	switch (ch) //모든 스위치문의 전제는 이동하려고 하는 위치에 WALL이 없을 경우에만 실행된다.
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] != WALL) //x축 왼쪽 방향으로 한칸이동
			character[X]--;
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL) //x축 오른쪽 방향으로 한칸이동
			character[X]++;
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL) //y축 위쪽 방향으로 한칸이동
			character[Y]--;
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL)//y축 아래쪽 방향으로 한칸이동
			character[Y]++;
		break;
	}
	MoveCheck(); // 움직임 체크
	//마지막 오브젝트 인덱스에 캐릭터가 새로 이동한곳의 위치를 넣어줌 
	//빈탄으로 이동했을 경우에는 (0 = NULL)을 포탈로 이동했을 경우에는 POTAL의 값을 
	//이것 때문에 캐릭터가 포탈을 지나치더라도 포탈이 사라지지않고 남아있을 수 있음
	LastObjectIndex = map[character[Y]][character[X]]; 
	map[character[Y]][character[X]] = CHARACTER; //캐릭터 값(2)를 맵에 넣음
}

void MoveCheck() 
{
	//이동하고 난후의 자리가 엔트리 포탈일 경우
	if (map[character[Y]][character[X]] == ENTRY_POTAL)
	{
		//캐릭터의 좌표를 탈출 포탈로 이동시킴
		character[X] = Exit_Potal[X];
		character[Y] = Exit_Potal[Y];
	}
}