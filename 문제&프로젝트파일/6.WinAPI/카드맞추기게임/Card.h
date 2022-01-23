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
	BitMap* m_pBitMap[CARD_END]; //비트 맵 포인터 
	int m_ix; //x좌표
	int m_iy; //y좌표
	int m_width; //가로 사이즈
	int m_height; //세로 사이즈
	RECT m_BitMapRect; //사각형
public:
	Card();
	void Init(IMAGE Index, int x, int y);
	void Draw(HDC hdc);
	bool ColliderCheck(POINT point);
	void CardFront();
	void CardRear();
	void RectNULL();
	BitMap* CardImage();
	~Card();
};

