#pragma once
#include "Mecro.h"

enum MOVE
{
	MOVE_UP = 'w',
	MOVE_DOWN = 's',
	MOVE_ENTER = 13
};

//전반적인 배경 그림 관리 Class
class Interface
{
public:
	void BoxDraw(int Width, int Height);
	void BoxDrawPos(int Width, int Height ,int startY);
	void BoxErase(int Width, int Height);
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	int MenuSelectCursor(int MenuLen, int AddCol, int x, int y);
	Interface();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~Interface();
};

