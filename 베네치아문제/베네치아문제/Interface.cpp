#include "Interface.h"

Interface::Interface()
{

}

void Interface::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}
void Interface::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void Interface::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void Interface::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

//박스안을 지우는 함수
void Interface::BoxErase(int Width, int Height)
{
	for (int y = 1; y < Height - 1; y++)
	{
		gotoxy(2, y);
		for (int x = 1; x < Width - 1; x++)
			cout << "  ";
	}
}

//박스 드로우
void Interface::BoxDraw(int Width, int Height)
{
	BLUE
		for (int y = 0; y < Height; y++)
		{
			gotoxy(0, 0 + y);
			if (y == 0)
			{
				cout << "┌";
				for (int x = 1; x < Width - 1; x++)
					cout << "─";
				cout << "┐";
			}
			else if (y == Height - 1)
			{
				cout << "└";
				for (int x = 1; x < Width - 1; x++)
					cout << "─";
				cout << "┘";
			}
			else
			{
				cout << "│";
				for (int x = 1; x < Width - 1; x++)
					cout << "  ";
				cout << "│";
			}
		}
	ORIGINAL
		return;
}

void Interface::BoxDrawPos(int Width, int Height, int startY)
{
	BLUE
		for (int y = 0; y < Height; y++) //y는 0 이고 세로보다 작다
		{
			gotoxy(WIDTH - Width, startY + y); //그릴 좌표로 이동
			if (y == 0) //맨 첫번째줄일경우 ┌─────┐ < 의 형태여야함
			{
				cout << "┌";
				for (int x = 1; x < Width - 1; x++)
					cout << "─";
				cout << "┐";
			}
			else if (y == Height - 1) //맨 마지막 줄일경우
			{
				cout << "└";
				for (int x = 1; x < Width - 1; x++)
					cout << "─";
				cout << "┘";
			}
			else //둘다 아닐경우
			{
				cout << "│";
				for (int x = 1; x < Width - 1; x++)
					cout << "  ";
				cout << "│";
			}
		}
	ORIGINAL
		return;
}

int Interface::MenuSelectCursor(int MenuLen, int AddCol, int x, int y)
{
	int Select = 1;
	RED
		DrawPoint("▷", x, y);
	ORIGINAL
		while (1)
		{
			switch (_getch())
			{
			case MOVE_UP:
				if (Select - 1 >= 1)
				{
					ErasePoint(x, y);
					y -= AddCol;
					Select--;
				}
				break;
			case MOVE_DOWN:
				if (Select + 1 <= MenuLen)
				{
					ErasePoint(x, y);
					y += AddCol;
					Select++;
				}
				break;
			case MOVE_ENTER:
				return Select;
			}
			RED
				DrawPoint("▷", x, y);
			ORIGINAL
		}
}

Interface::~Interface()
{

}
