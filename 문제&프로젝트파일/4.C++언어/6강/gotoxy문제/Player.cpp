#include "Player.h"

Player::Player()
{

}

void Player::PlayerStartDraw(int x, int y)//처음 시작할때 플레이어 드로우
{
	m_iplayerx = x;
	m_iplayery = y;
	MapDraw::TextDraw("♤", m_iplayerx, m_iplayery);
}

//좌표는 0,0부터 시작함
//세로는 1칸씩 이동
//가로는 2칸씩 이동(특수문자라)
void Player::PlayerMove(int x, int y, Map m)//플레이어 움직임 체크
{
	if (m.WidthCheck(m_iplayerx+x)&& m.HeightCheck(m_iplayery + y))
	{
		Erase();
		m_iplayerx += x;
		m_iplayery += y;
		PlayerDraw();
	}
}

void Player::PlayerDraw()//플레이어 드로우
{
	MapDraw::TextDraw("♤", m_iplayerx, m_iplayery);
}

void Player::Erase()//지움
{
	MapDraw::ErasePoint(m_iplayerx, m_iplayery);
}

void Player::PlayerPos()//좌표확인용
{
	MapDraw::gotoxy(0, 10);
	cout << "x : " << m_iplayerx << "   y : " << m_iplayery << "   " << endl;
}

Player::~Player()
{

}