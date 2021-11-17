#include "Block.h"

//빈 박스 드로우
void Block::WallDraw()
{
	gotoxy(STARTPOS, STARTPOS);
	for (int y = 0; y < HEIGHT; y++)
	{
		if (y == 0 || y == HEIGHT - 1)
		{
			for (int x = 0; x < WIDTH; x++)
			{
				cout << "▦";
			}
			cout << endl;
		}
		else
		{
			cout << "▦";
			for (int x = 0; x < WIDTH - 2; x++)
			{
				cout << "  ";
			}
			cout << "▦" << endl;
		}
	}

}

//해당좌표에 드로우
void Block::DrawPoint(string str, int x, int y)
{
	gotoxy(x*2, y);
	cout << str;
}

//해당좌표 지움
void Block::ErasePoint(int x, int y)
{
	gotoxy(x*2, y);
	cout << "  ";
	return;
}

//텍스트 중앙드로우
void Block::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}


//뱀 머리-몸통-음식 그리는 함수
void Block::DrawWall(Pos pos)
{
	gotoxy(pos.x * 2, pos.y);
	cout << "▣";
}

void Block::DrawFood(Pos pos)
{
	gotoxy(pos.x*2, pos.y);
	cout << food;
}

void Block::DrawSnakeHead(Pos pos)
{
	gotoxy(pos.x*2, pos.y);
	cout << snakeHead;
}

void Block::DrawSnakeBody(Pos pos)
{
	gotoxy(pos.x*2, pos.y);
	cout << snakeBody;
}