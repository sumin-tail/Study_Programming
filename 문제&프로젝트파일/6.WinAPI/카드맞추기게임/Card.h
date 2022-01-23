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
	BitMap* m_pBitMap[CARD_END]; //��Ʈ �� ������ 
	int m_ix; //x��ǥ
	int m_iy; //y��ǥ
	int m_width; //���� ������
	int m_height; //���� ������
	RECT m_BitMapRect; //�簢��
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

