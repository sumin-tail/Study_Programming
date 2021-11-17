#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<string>
#include<conio.h> //getch
#include <list>
#include <vector>  
#include <cstdlib>

using namespace std;

#define STARTPOS 0
#define DEFAULT_SCORE 0
#define DIRECTION_STOP 0


#define WIDTH 50 //가로 맵 크기
#define HEIGHT 30 //세로 맵 크기

#define SPACEBAR 32 //스페이스 바

//좌표를 담을 구조체
typedef struct Pos
{
	int x;
	int y;

	Pos(int posX, int posY)
	{
		x = posX;
		y = posY;
	}

	Pos()
	{}

}Pos;

//좌표이동은 인라인 함수로
inline void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

