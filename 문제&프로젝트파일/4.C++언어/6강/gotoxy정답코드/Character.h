#pragma once
#include"Mecro.h"
#include"MapDraw.h"


enum DIRECTION //������ ����ؼ� ��������� ����
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_UP = 'w',
	DIRECTION_DOWN = 's'
};

class Character
{
private:
	MapDraw m_DrawManager;
	string m_strShape;
	int m_ix; //ĳ���� x��ǥ
	int m_iy; //ĳ���� y��ǥ
public:
	void Draw();
	void Move(int x,int y,int Width,int Height);
	Character(int x,int y);
	~Character();
};

