#include "Player.h"

//������
Player::Player(string name, int x, int y, string Shape, int undoCount)
{
	m_strName = name; //�̸�
	m_strStoneShape = Shape; //�� ���
	m_iundoCount = undoCount; //������ Ƚ�� 

	//��ǥ ����
	m_ix = x;
	if (m_ix % 2 == 1)//���� ¦���� �ƴҰ��
		m_ix++;
	m_iy = y;

}

//�Ҹ���
Player::~Player() 
{

}

//�������� �� ������ ����
void Player::PosUpdate(int x, int y) 
{
	m_ix = x;
	m_iy = y;
}

//����� ���� �Լ�
void Player::ChangeStoneShape(string Shape)
{
	m_strStoneShape = Shape;
}

//������
void Player::Undo(int width, int height)
{
	m_ix = StoneLOG.back().x; //���� ������ ��ġ ����
	m_iy = StoneLOG.back().y; //���� ������ ��ġ ����
	m_DrawManager.PlayingBoxEmpty(width, height, m_ix, m_iy);
	StoneLOG.pop_back();//�� ����
}


void  Player::Undocount()
{
	m_iundoCount--;
}

//�¸�üũ �Լ�
bool Player::WinCheck()
{
	int count = 0;
	if (6 == WinCheckStoneCount(count, m_ix, m_iy, -2, 0)+ WinCheckStoneCount(count, m_ix, m_iy, 2, 0)) //����
	{
		return true;
	}
	else if (6 == WinCheckStoneCount(count, m_ix, m_iy, 0, 1) + WinCheckStoneCount(count, m_ix, m_iy, 0, -1))//����
	{
		return true;
	}
	else if (6 == WinCheckStoneCount(count, m_ix, m_iy, 2, -1) + WinCheckStoneCount(count, m_ix, m_iy, -2, 1))//������������ ���� �Ʒ���
	{
		return true;
	}
	else if (6 == WinCheckStoneCount(count, m_ix, m_iy, -2, -1) + WinCheckStoneCount(count, m_ix, m_iy, 2, 1))//���� ������ ������ �Ʒ���
	{
		return true;
	}
	return false;
}

int Player::WinCheckStoneCount(int count, int posX, int posY, int ChangeX, int ChangeY)
{
	if (posX < 0 || posY < 0)
	{
		return count;
	}

	for (list<StoneXY>::iterator iter = StoneLOG.begin(); iter != StoneLOG.end(); iter++)
	{
		if (iter->x == posX && iter->y == posY)
		{
			count++;
			count = WinCheckStoneCount(count, posX+ChangeX, posY+ChangeY, ChangeX, ChangeY);
		}
	}

	return count;
}


//�� üũ �Լ� > �ش���ǥ�� ���� �� �� �ִ��� ������ Ȯ��
bool Player::StoneCheck(int posX, int posY)
{
	//���� ������ true ��ȯ
	for (list<StoneXY>::iterator iter = StoneLOG.begin(); iter != StoneLOG.end(); iter++)
	{
		if (iter->x == posX && iter->y == posY)
		{
			return true;
		}
	}
	return false;
}

//�� ���� �Լ�
void Player::StoneDrop(int posX, int posY)
{
	StoneXY stone(posX, posY);
	StoneLOG.push_back(stone);
	m_DrawManager.TextDraw(m_strStoneShape, posX, posY);
}

//���� ���� �� ��� ���
void Player::StoneDrow()
{
	for (list<StoneXY>::iterator iter = StoneLOG.begin(); iter != StoneLOG.end(); iter++)
	{
		m_DrawManager.TextDraw(m_strStoneShape, iter->x, iter->y);
	}
}

//��ȯ�Լ�//
//����� ����
string Player::GetStoneShape()
{
	return m_strStoneShape;
}
//�̸� ����
string Player::GetName()
{
	return m_strName;
}
//X��ǥ�� Y��ǥ ����
int Player::GetXPos()
{
	return m_ix;
}
int Player::GetYPos()
{
	return m_iy;
}

//���� ������ Ƚ�� ��ȯ
int Player::GetUndo()
{
	return m_iundoCount;
}

