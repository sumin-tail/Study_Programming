#pragma once
#include"Mecro.h"
#include"MapDraw.h"


//�� Ŭ����
class Map
{
private:
	int m_ix;
	int m_iy; //��ǥ x�� y
	int m_iWidth; //����
	int m_iHeight; //����
public:
	void MapDraw();
	int StartPlayerX();
	int StartPlayerY();
	bool WidthCheck(int x);
	bool HeightCheck(int y);
	Map();
	~Map();
};

