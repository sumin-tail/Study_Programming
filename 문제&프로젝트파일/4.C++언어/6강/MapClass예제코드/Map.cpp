#include "Map.h"



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


void Map::MapDraw()
{
	MapDraw::BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
}

Map::~Map()
{
}
