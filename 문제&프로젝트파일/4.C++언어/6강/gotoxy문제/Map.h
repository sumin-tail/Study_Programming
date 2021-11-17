#pragma once
#include"Mecro.h"
#include"MapDraw.h"


//맵 클래스
class Map
{
private:
	int m_ix;
	int m_iy; //좌표 x와 y
	int m_iWidth; //가로
	int m_iHeight; //세로
public:
	void MapDraw();
	int StartPlayerX();
	int StartPlayerY();
	bool WidthCheck(int x);
	bool HeightCheck(int y);
	Map();
	~Map();
};

