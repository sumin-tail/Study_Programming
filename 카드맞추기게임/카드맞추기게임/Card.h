#pragma once
#include"BitMap.h"
#include"BitMapManager.h"
enum CARD //ī�� ����
{
	CARD_FRONT, //�ո�
	CARD_REAR, //�޸�
	CARD_END
};

class Card
{
private:
	CARD m_eCardState;//ī�� ���¸� ������ ����
	BitMap* m_pBitMap[CARD_END];
	int m_ix;
	int m_iy;
	RECT m_BitMapRect;
public:
	Card();
	void Init(IMAGE Index, int x, int y);
	void Draw(HDC hdc);
	bool ColliderCheck(POINT point);
	~Card();
};

