#include "Rank.h"

void Rank::RankSort()
{

}

void Rank::RankPrint()
{
	system("cls");
	m_DrawInterface.BoxDraw(WIDTH, HEIGHT);
	m_DrawInterface.BoxDrawPos(WIDTH * 0.3f, 5, HEIGHT * 0.1f);//작은 박스
	BLUE
	m_DrawInterface.DrawMidText("Ranking", WIDTH, HEIGHT * 0.1f + 2);//박스 안에 드로우
	m_DrawInterface.gotoxy(2, HEIGHT * 0.3f-1);
	for (int i = 2; i < WIDTH*2 - 2; i++)
	{
		cout << "=";
	}
	_getch();
}
