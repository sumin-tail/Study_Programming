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
#define ENTRY_START 10
#define EXIT_START 20
#define POTAL_MAX 4 //포탈 갯수
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
  { 1,	0,	10,	0,	12,	0,	0,	11,	0,	1 },
  { 1,	23,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	0,	0,	2,	0,	0,	0,	1 },
  { 1,	22,	0,	0,	0,	0,	0,	13,	0,	1 },
  { 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	21,	0,	0,	0,	0,	20,	0,	1 },
  { 1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 } };

int character[2]; //1차원 배열 - 첫번째 인덱스에 Y 좌표가 2번째 인덱스에 X좌표가 들어감
int Entry_Potal[POTAL_MAX][2]; //2차원 배열 [4][2] 이다. 
int Exit_Potal[POTAL_MAX][2]; //들어갈수있는 포탈이 4개, 나갈 수 있는 포탈도 4개란 뜻 - 여전히 0번은 y좌표 1번은 x좌표이다.

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
	int Width = (WIDTH * 2) + 1; //특수문자는 2 바이트라서 가로 사이즈 * 2 +1은 혹시 모를 잘림을 대비해서
	int Height = HEIGHT + 1; //세로는 그냥 줄바꿈! 그래서 잘림을 대비한 + 1만 넣었음.
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);  
	system(buf); //콘솔창 크기인듯 > 왜 가로크기는 2배+1 고 세로크기는 +1 인가

	//여긴 배열 -x축과 y축- 초기화 하는곳
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER) //캐릭터 위치 초기화
			{
				character[X] = x;
				character[Y] = y;
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX) // 현재 위치의 값이 10보다 크거나 같고 14보다 작을 때
			{
				Entry_Potal[map[y][x] - ENTRY_START][X] = x; // 엔트리 포탈X축에 [현재 위치의 값 - 10 = n번 째 포탈이라는 뜻][X] x좌표를 넣음.
				Entry_Potal[map[y][x] - ENTRY_START][Y] = y; //엔트리 포탈Y축에 [현재 위치의 값 - 10 = n번 째 포탈이라는 뜻][X] y좌표를 넣음.
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX) //위와 같음
			{
				Exit_Potal[map[y][x] - EXIT_START][X] = x;
				Exit_Potal[map[y][x] - EXIT_START][Y] = y;
			}
			//11엔트리 포탈에 들어간다면 21 출구포탈로 감. 엔트리 포탈은 10 부터 13 까지 있음 - 배열의 인덱스는 항상 0부터 시작함!
		}
	}
}

void MapDraw()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
				printf("▩");
			else if (map[y][x] == CHARACTER)
			{
				RED
					printf("♧");
				ORIGINAL
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX) //0번째부터 4번째 포탈을 다 출력하기위해서
			{
				BLUE
					printf("◎");
				ORIGINAL
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX) //위와 동일
			{
				YELLOW
					printf("●");
				ORIGINAL
			}
			else if (map[y][x] == NULL)
				printf("  ");
		}
		printf("\n"); //줄바꿈
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

	//이동한 자리의 값을 index 에 넣어줌
	int index = map[character[Y]][character[X]];
	//index의 값이 10과 같거나 크고 14보다 작을떄 == 엔트리 포탈(10~13)이라는 뜻임 
	if (index >= ENTRY_START && index < ENTRY_START + POTAL_MAX)
	{
		//캐릭터의 좌표를 해당하는 엔트리 포탈과 맞는 탈출 포탈로 이동시킴
		//indexrk 10일 경우 0번째 엔트리 포탈이라는 뜻 이니 0 번째 탈출 포탈의 X축과 Y축을 대입
		character[X] = Exit_Potal[index - ENTRY_START][X];
		character[Y] = Exit_Potal[index - ENTRY_START][Y];
	}
}