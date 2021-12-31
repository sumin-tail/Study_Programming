#pragma once
#include"BitMap.h"
#include"BitMapManager.h"
enum CARD //카드 상태
{
	CARD_FRONT, //앞면
	CARD_REAR, //뒷면
	CARD_END
};

class Card
{
private:
	CARD m_eCardState;//카드 상태를 저장할 변수
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

