#include "Player.h"

Player::Player()
{
	m_pStoneList = NULL;
	m_iStoneCount = 0;
	m_bMyWindState = false;
	m_iUndo = DEFAULT_UNDO;
}


bool Player::CompareStone(int x, int y) //�� ã��
{
	for(int i = 0; i < m_iStoneCount; i++)
	{
		if(m_pStoneList[i].m_ix == x &&m_pStoneList[i].m_iy == y)
			return true;
	}
	return false;
}

void Player::AllStoneDraw() //��� �� ���
{
	for(int i = 0; i < m_iStoneCount; i++)
		m_DrawManager.DrawPoint(m_strStoneIcon, m_pStoneList[i].m_ix, m_pStoneList[i].m_iy);
}

void Player::DrawStone(int x, int y)//�����
{
	if(CompareStone(x, y))//�ش���ǥ�� ���̾��ٸ�
		m_DrawManager.DrawPoint(m_strStoneIcon, x, y);
}

void Player::Undo(int Width, int Height)//������
{
	m_iStoneCount--; //���� �� �ϳ� ���̰�
	m_DrawManager.Erase(m_pStoneList[m_iStoneCount].m_ix, m_pStoneList[m_iStoneCount].m_iy, Width, Height); //�ش絹���ִ� �ڸ��� ����
}

void Player::CreateStone()// ������
{
	if(CompareStone(m_Cursor.m_ix, m_Cursor.m_iy) == false) //���� ������ǥ�� ���� ���ٸ�
	{
		m_pStoneList[m_iStoneCount].m_ix = m_Cursor.m_ix; //m_pStoneList�� m_iStoneCount��° m_ix�� ���� x��ǥ ����
		m_pStoneList[m_iStoneCount++].m_iy = m_Cursor.m_iy; //m_pStoneList�� m_iStoneCount��° m_ix�� ���� x��ǥ ����
		DrawStone(m_Cursor.m_ix, m_Cursor.m_iy); //�ش� ��ǥ�� �� ��ο�
	}
}

void Player::Move(char ch, int Width, int Height) //���� �¿��̵� Ű���� �Է¿� ���� ������ǥ ����
{
	switch(ch)
	{
		case KEY_LEFT:
			if(m_Cursor.m_ix - 1 >= 0)
				m_Cursor.m_ix--;
			break;
		case KEY_RIGHT:
			if(m_Cursor.m_ix + 1 < Width)
				m_Cursor.m_ix++;
			break;
		case KEY_UP:
			if(m_Cursor.m_iy - 1 >= 0)
				m_Cursor.m_iy--;
			break;
		case KEY_DOWN:
			if(m_Cursor.m_iy + 1 < Height)
				m_Cursor.m_iy++;
			break;
	}
}


void Player::EraseCursor(int Width, int Height)//���� �� ��ǥ�� ����
{

	m_DrawManager.Erase(m_Cursor.m_ix, m_Cursor.m_iy,Width,Height); //Ÿ�Ϸ�
}

void Player::DrawCursor() //Ŀ�� ��ο�
{
	m_DrawManager.DrawPoint(m_strCursorIcon, m_Cursor.m_ix, m_Cursor.m_iy);
}

void Player::DeleteStone() //�� ����Ʈ ����
{
	if(m_pStoneList != NULL) //�� ����Ʈ�� NULL �� �ƴ϶��
	{
		delete[] m_pStoneList; //����Ʈ �����
		m_pStoneList = NULL; //NULL �־���
	}
}

void Player::PlayerSet(int Width,int Height) //�÷��̾� ����
{
	DeleteStone(); //�� ����Ʈ ����
	m_pStoneList = new Point[(Width*Height) / 2];//m_pStoneList�� ��ǥ ����ü Point �迭 �Ҵ�
	m_iStoneCount = 0; //�� ī��Ʈ 0���� ����
	m_Cursor.m_ix = Width * 0.5f; //�� �߰� ��ǥ ����
	m_Cursor.m_iy = Height* 0.5f;
	m_bMyWindState = false; //�¸����� ����
}



int Player::NextStoneCheck(int x, int y, int addx, int addy, int Width, int Height)//���� ��ǥ�� ���� �ִ��� üũ
{
	int count = 0;
	for(; (x >= 0 && x < Width) && (y >= 0 && y < Height); x += addx, y += addy)//x��ǥ�� y��ǥ�� 0���ϰ��ǰų� ���� �ʰ����� �ʴ��̻�
	{
		if(CompareStone(x, y)) //�ش���ǥ�� �����ִ��� ������ üũ
			count++; //�ִٸ� ī��Ʈ�� �ø���
		else //���ٸ� Ż��!
			break;
	}
	return count;
}

bool Player::WinCheck(int Width, int Height)//�¸�üũ�Լ� (�� ������ �޾ƿ�)
{
	int Count = 0;
	Count += NextStoneCheck(m_Cursor.m_ix - 1, m_Cursor.m_iy, -1, 0, Width, Height);
	Count += NextStoneCheck(m_Cursor.m_ix + 1, m_Cursor.m_iy, 1, 0, Width, Height);
	if(Count + 1 == 5) //���� �˻�
		return true;
	Count = 0;	
	Count += NextStoneCheck(m_Cursor.m_ix, m_Cursor.m_iy -1, 0, -1, Width, Height);
	Count += NextStoneCheck(m_Cursor.m_ix, m_Cursor.m_iy+1, 0, 1, Width, Height);
	if(Count + 1 == 5)//���ΰ˻�
		return true;
	Count = 0;
	Count += NextStoneCheck(m_Cursor.m_ix - 1, m_Cursor.m_iy-1, -1, -1, Width, Height);
	Count += NextStoneCheck(m_Cursor.m_ix + 1, m_Cursor.m_iy+1, 1, 1, Width, Height);
	if(Count + 1 == 5)//���ʴ밢��
		return true;
	Count = 0;
	Count += NextStoneCheck(m_Cursor.m_ix + 1, m_Cursor.m_iy-1, 1, -1, Width, Height);
	Count += NextStoneCheck(m_Cursor.m_ix - 1, m_Cursor.m_iy+1, -1, 1, Width, Height);
	if(Count + 1 == 5)//�����ʴ밢��
		return true;

	return false;
}

Player::~Player()
{
	if(m_pStoneList != NULL)
		delete[] m_pStoneList;
}
