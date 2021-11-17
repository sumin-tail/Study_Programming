#include "Character.h"



Character::Character(int x, int y)
{
	m_ix = x;
	if(m_ix % 2 == 1)//���� ¦���� �ƴҰ��
		m_ix++;
	m_iy = y;
	m_strShape = "��";
}


void Character::Move(int x, int y, int Width, int Height)// �� ��ǥ x,y,�� ���� ���� ũ��
{
	while(1)
	{
		// 01 23 45 67 89
		char ch = _getch();
		m_DrawManager.ErasePoint(m_ix, m_iy);//���� �����
		switch(ch)//�� ���� ��ο� ->  �� ���⿡ ���� ���� üũ��
		{
			case DIRECTION_LEFT:
				if(m_ix*2 - 1 > x+1) //���� ���� ���� Ư�� ���� ������
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
	m_DrawManager.DrawPoint(m_strShape, m_ix, m_iy); //��� x, y ��ǥ�� �Ѱ���
	//�ȿ��� x��ǥ�� *2 �ؼ� �׸�
}


Character::~Character()
{
}
