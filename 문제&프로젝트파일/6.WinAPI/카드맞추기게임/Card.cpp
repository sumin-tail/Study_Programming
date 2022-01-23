#include "Card.h"

Card::Card() : m_width(100), m_height(150)//세로 사이즈
{
	m_eCardState = CARD_REAR; //카드의 기본 상태는 뒷면
}


void Card::Init(IMAGE Index, int x, int y) //이미지 와 자표
{
	m_pBitMap[CARD_FRONT] = BitMapManager::GetInstance()->GetImage(Index); //카드 앞면 쪽은 해당하는 이미지 넣어줌
	m_pBitMap[CARD_REAR] = BitMapManager::GetInstance()->GetImage(IMAGE_BLACK); //카드 뒷면 쪽은 검은색 이미지 넣어줌
	m_ix = x; //좌표 넣음
	m_iy = y;
	m_BitMapRect.left = x; //사각형 만듬
	m_BitMapRect.top = y;
	m_BitMapRect.right = m_BitMapRect.left + m_width;
	m_BitMapRect.bottom = m_BitMapRect.top + m_height;
}
void Card::Draw(HDC hdc)
{
	m_pBitMap[m_eCardState]->Draw(hdc, m_ix, m_iy, m_width, m_height);//내가 가지고 있는 이미지 드로우
}
bool Card::ColliderCheck(POINT point)
{
	if (PtInRect(&m_BitMapRect, point))//사각형좌표 안인지 밖인지 체크
	{
		//if (m_eCardState == CARD_FRONT)//카드가 앞면이라면= 뒷면으로 뒤집음
		//	m_eCardState = CARD_REAR;
		//else //카드가 뒷면이라면 앞으로 뒤집음
		//	m_eCardState = CARD_FRONT;
		return true;
	}
	return false;//아니라면 걍 돌아감
}

void Card::CardFront()
{
	m_eCardState = CARD_FRONT;
}

void Card::CardRear()
{
	m_eCardState = CARD_REAR;
}

void Card::RectNULL()
{
	m_BitMapRect.left = 0; //사각형 만듬
	m_BitMapRect.top = 0;
	m_BitMapRect.right = 0;
	m_BitMapRect.bottom =0;
}

BitMap* Card::CardImage()
{
	return m_pBitMap[CARD_FRONT];
}

// 800 1000 = 20장  4x5 배치로  50씩 간격 두면  가로 5칸=250 세로 6칸 300 뺴면 550/4 = 100 (가로 첫 띄움만 좀 크게) 랑 700/5  =140

Card::~Card()
{

}
