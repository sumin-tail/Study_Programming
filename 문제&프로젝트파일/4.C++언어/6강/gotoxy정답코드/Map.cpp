#include "Map.h"



Map::Map()
{
	cout << "맵 X 입력 :";
	cin >> m_ix;
	cout << "맵 y 입력 :";
	cin >> m_iy;
	cout << "맵 가로 길이 입력 :";
	cin >> m_iWidth;
	cout << "맵 세로 길이 입력 :";
	cin >> m_iHeight;
	m_Character = new Character((m_ix + m_iWidth)* 0.5f, m_iy + (m_iHeight * 0.5f)); //캐릭터 x, y 좌표 지정해서 만들어 줌
}


void Map::MapDraw()
{
	m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
	m_Character->Draw();
	m_Character->Move(m_ix,m_iy,m_iWidth,m_iHeight);
}

Map::~Map()
{
	delete m_Character;
}
