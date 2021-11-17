#include "Character.h"



Character::Character(int x, int y)
{
	m_ix = x;
	if(m_ix % 2 == 1)//만약 짝수가 아닐경우
		m_ix++;
	m_iy = y;
	m_strShape = "♤";
}


void Character::Move(int x, int y, int Width, int Height)// 맵 좌표 x,y,와 가로 세로 크기
{
	while(1)
	{
		// 01 23 45 67 89
		char ch = _getch();
		m_DrawManager.ErasePoint(m_ix, m_iy);//먼저 지우고
		switch(ch)//그 다음 드로우 ->  각 뱡향에 따른 벽을 체크함
		{
			case DIRECTION_LEFT:
				if(m_ix*2 - 1 > x+1) //왼쪽 오른 쪽은 특수 문자 때문에
					m_ix--;
				break;
			case DIRECTION_RIGHT:
				if(m_ix*2 + 1 < x +Width*2 - 3)
				m_ix++;
				break;
			case DIRECTION_UP:
				if(m_iy - 1 > y)
				m_iy--;
				break;
			case DIRECTION_DOWN:
				if(m_iy + 1 < y + Height-1)
				m_iy++;
				break;
		}
		Draw();
	}
}


void Character::Draw()
{
	m_DrawManager.DrawPoint(m_strShape, m_ix, m_iy); //모양 x, y 좌표를 넘겨줌
	//안에서 x좌표는 *2 해서 그림
}


Character::~Character()
{
}
