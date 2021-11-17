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
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//���� ����
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
#define POTAL_MAX 4 //��Ż ����
#define LEFT 75 // Ű���� �νĹ޾��� ���� �ƽ�Ű �ڵ�
#define RIGHT 77
#define UP 72
#define DOWN 80 // �̵��� �� ����
#define WIDTH 10
#define HEIGHT 10

//�Լ�
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

int character[2]; //1���� �迭 - ù��° �ε����� Y ��ǥ�� 2��° �ε����� X��ǥ�� ��
int Entry_Potal[POTAL_MAX][2]; //2���� �迭 [4][2] �̴�. 
int Exit_Potal[POTAL_MAX][2]; //�����ִ� ��Ż�� 4��, ���� �� �ִ� ��Ż�� 4���� �� - ������ 0���� y��ǥ 1���� x��ǥ�̴�.

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
	int Width = (WIDTH * 2) + 1; //Ư�����ڴ� 2 ����Ʈ�� ���� ������ * 2 +1�� Ȥ�� �� �߸��� ����ؼ�
	int Height = HEIGHT + 1; //���δ� �׳� �ٹٲ�! �׷��� �߸��� ����� + 1�� �־���.
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);  
	system(buf); //�ܼ�â ũ���ε� > �� ����ũ��� 2��+1 �� ����ũ��� +1 �ΰ�

	//���� �迭 -x��� y��- �ʱ�ȭ �ϴ°�
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER) //ĳ���� ��ġ �ʱ�ȭ
			{
				character[X] = x;
				character[Y] = y;
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX) // ���� ��ġ�� ���� 10���� ũ�ų� ���� 14���� ���� ��
			{
				Entry_Potal[map[y][x] - ENTRY_START][X] = x; // ��Ʈ�� ��ŻX�࿡ [���� ��ġ�� �� - 10 = n�� ° ��Ż�̶�� ��][X] x��ǥ�� ����.
				Entry_Potal[map[y][x] - ENTRY_START][Y] = y; //��Ʈ�� ��ŻY�࿡ [���� ��ġ�� �� - 10 = n�� ° ��Ż�̶�� ��][X] y��ǥ�� ����.
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX) //���� ����
			{
				Exit_Potal[map[y][x] - EXIT_START][X] = x;
				Exit_Potal[map[y][x] - EXIT_START][Y] = y;
			}
			//11��Ʈ�� ��Ż�� ���ٸ� 21 �ⱸ��Ż�� ��. ��Ʈ�� ��Ż�� 10 ���� 13 ���� ���� - �迭�� �ε����� �׻� 0���� ������!
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
				printf("��");
			else if (map[y][x] == CHARACTER)
			{
				RED
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX) //0��°���� 4��° ��Ż�� �� ����ϱ����ؼ�
			{
				BLUE
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX) //���� ����
			{
				YELLOW
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == NULL)
				printf("  ");
		}
		printf("\n"); //�ٹٲ�
	}
}

void Move()
{
	char ch;
	ch = getch(); //�����ν� ����
	system("cls"); //�ܼ�â Ŭ����
	map[character[Y]][character[X]] = LastObjectIndex; //ĳ������ x��� y�࿡ NULL����
	//�� ĳ���Ͱ� �̵��ϰ� �� ���� �ڸ��� ��������� �������
	switch (ch) //��� ����ġ���� ������ �̵��Ϸ��� �ϴ� ��ġ�� WALL�� ���� ��쿡�� ����ȴ�.
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] != WALL) //x�� ���� �������� ��ĭ�̵�
			character[X]--;
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL) //x�� ������ �������� ��ĭ�̵�
			character[X]++;
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL) //y�� ���� �������� ��ĭ�̵�
			character[Y]--;
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL)//y�� �Ʒ��� �������� ��ĭ�̵�
			character[Y]++;
		break;
	}
	MoveCheck(); // ������ üũ
	//������ ������Ʈ �ε����� ĳ���Ͱ� ���� �̵��Ѱ��� ��ġ�� �־��� 
	//��ź���� �̵����� ��쿡�� (0 = NULL)�� ��Ż�� �̵����� ��쿡�� POTAL�� ���� 
	//�̰� ������ ĳ���Ͱ� ��Ż�� ����ġ���� ��Ż�� ��������ʰ� �������� �� ����
	LastObjectIndex = map[character[Y]][character[X]];
	map[character[Y]][character[X]] = CHARACTER; //ĳ���� ��(2)�� �ʿ� ����
}

void MoveCheck()
{

	//�̵��� �ڸ��� ���� index �� �־���
	int index = map[character[Y]][character[X]];
	//index�� ���� 10�� ���ų� ũ�� 14���� ������ == ��Ʈ�� ��Ż(10~13)�̶�� ���� 
	if (index >= ENTRY_START && index < ENTRY_START + POTAL_MAX)
	{
		//ĳ������ ��ǥ�� �ش��ϴ� ��Ʈ�� ��Ż�� �´� Ż�� ��Ż�� �̵���Ŵ
		//indexrk 10�� ��� 0��° ��Ʈ�� ��Ż�̶�� �� �̴� 0 ��° Ż�� ��Ż�� X��� Y���� ����
		character[X] = Exit_Potal[index - ENTRY_START][X];
		character[Y] = Exit_Potal[index - ENTRY_START][Y];
	}
}