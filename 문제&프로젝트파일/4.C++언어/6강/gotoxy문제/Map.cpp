#include "Map.h"

//�÷��̾� �������� ��

Map::Map()
{
	cout << "�� X �Է� :";
	cin >> m_ix;
	cout << "�� Y �Է� :";
	cin >> m_iy;
	cout << "�� ���� ���� �Է� :";
	cin >> m_iWidth;
	cout << "�� ���� ���� �Է� :";
	cin >> m_iHeight;
}


int Map::StartPlayerX()//�÷��̾� x��ǥ ��ȯ
{
	if (m_iWidth%2 == 0) //���� ¦�����
	{
		return m_iWidth + m_ix;
	}
	return m_iWidth + m_ix - 1; //Ȧ�����
}

int Map::StartPlayerY()//�÷��̾� y��ǥ ��ȯ
{
	return m_iHeight / 2 + m_iy;
}

bool Map::WidthCheck(int x)
{
	if (x < m_ix + 1 || x > (m_iWidth-2)*2 + m_ix)
	{
		return false;
	}
	return true;
}

bool Map::HeightCheck(int y)
{
	if (y < m_iy+1 || y > m_iHeight - 2 + m_iy)
	{
		return false;
	}
	return true;
}

void Map::MapDraw()//�� ��ο�
{
	MapDraw::BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
}

Map::~Map()
{
}
