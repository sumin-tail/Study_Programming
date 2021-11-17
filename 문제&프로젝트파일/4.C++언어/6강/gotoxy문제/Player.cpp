#include "Player.h"

Player::Player()
{

}

void Player::PlayerStartDraw(int x, int y)//ó�� �����Ҷ� �÷��̾� ��ο�
{
	m_iplayerx = x;
	m_iplayery = y;
	MapDraw::TextDraw("��", m_iplayerx, m_iplayery);
}

//��ǥ�� 0,0���� ������
//���δ� 1ĭ�� �̵�
//���δ� 2ĭ�� �̵�(Ư�����ڶ�)
void Player::PlayerMove(int x, int y, Map m)//�÷��̾� ������ üũ
{
	if (m.WidthCheck(m_iplayerx+x)&& m.HeightCheck(m_iplayery + y))
	{
		Erase();
		m_iplayerx += x;
		m_iplayery += y;
		PlayerDraw();
	}
}

void Player::PlayerDraw()//�÷��̾� ��ο�
{
	MapDraw::TextDraw("��", m_iplayerx, m_iplayery);
}

void Player::Erase()//����
{
	MapDraw::ErasePoint(m_iplayerx, m_iplayery);
}

void Player::PlayerPos()//��ǥȮ�ο�
{
	MapDraw::gotoxy(0, 10);
	cout << "x : " << m_iplayerx << "   y : " << m_iplayery << "   " << endl;
}

Player::~Player()
{

}