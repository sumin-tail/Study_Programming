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


#define WIDTH 50 //���� �� ũ��
#define HEIGHT 30 //���� �� ũ��

#define SPACEBAR 32 //�����̽� ��

//��ǥ�� ���� ����ü
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

//��ǥ�̵��� �ζ��� �Լ���
inline void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

