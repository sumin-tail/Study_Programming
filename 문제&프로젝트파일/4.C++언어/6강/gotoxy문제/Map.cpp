#include "Map.h"

//플레이어 아이콘은 ♤

Map::Map()
{
	cout << "맵 X 입력 :";
	cin >> m_ix;
	cout << "맵 Y 입력 :";
	cin >> m_iy;
	cout << "맵 가로 길이 입력 :";
	cin >> m_iWidth;
	cout << "맵 세로 길이 입력 :";
	cin >> m_iHeight;
}


int Map::StartPlayerX()//플레이어 x좌표 반환
{
	if (m_iWidth%2 == 0) //만약 짝수라면
	{
		return m_iWidth + m_ix;
	}
	return m_iWidth + m_ix - 1; //홀수라면
}

int Map::StartPlayerY()//플레이어 y좌표 반환
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

void Map::MapDraw()//맵 드로우
{
	MapDraw::BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
}

Map::~Map()
{
}
