#pragma once
#include"Mecro.h"
#include"MapDraw.h"


enum DIRECTION //열거형 사용해서 직관저긍로 만듬
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
	int m_ix; //캐릭터 x좌표
	int m_iy; //캐릭터 y좌표
public:
	void Draw();
	void Move(int x,int y,int Width,int Height);
	Character(int x,int y);
	~Character();
};

