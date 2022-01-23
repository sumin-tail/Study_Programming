#include "Card.h"

Card::Card() : m_width(100), m_height(150)//���� ������
{
	m_eCardState = CARD_REAR; //ī���� �⺻ ���´� �޸�
}


void Card::Init(IMAGE Index, int x, int y) //�̹��� �� ��ǥ
{
	m_pBitMap[CARD_FRONT] = BitMapManager::GetInstance()->GetImage(Index); //ī�� �ո� ���� �ش��ϴ� �̹��� �־���
	m_pBitMap[CARD_REAR] = BitMapManager::GetInstance()->GetImage(IMAGE_BLACK); //ī�� �޸� ���� ������ �̹��� �־���
	m_ix = x; //��ǥ ����
	m_iy = y;
	m_BitMapRect.left = x; //�簢�� ����
	m_BitMapRect.top = y;
	m_BitMapRect.right = m_BitMapRect.left + m_width;
	m_BitMapRect.bottom = m_BitMapRect.top + m_height;
}
void Card::Draw(HDC hdc)
{
	m_pBitMap[m_eCardState]->Draw(hdc, m_ix, m_iy, m_width, m_height);//���� ������ �ִ� �̹��� ��ο�
}
bool Card::ColliderCheck(POINT point)
{
	if (PtInRect(&m_BitMapRect, point))//�簢����ǥ ������ ������ üũ
	{
		//if (m_eCardState == CARD_FRONT)//ī�尡 �ո��̶��= �޸����� ������
		//	m_eCardState = CARD_REAR;
		//else //ī�尡 �޸��̶�� ������ ������
		//	m_eCardState = CARD_FRONT;
		return true;
	}
	return false;//�ƴ϶�� �� ���ư�
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
	m_BitMapRect.left = 0; //�簢�� ����
	m_BitMapRect.top = 0;
	m_BitMapRect.right = 0;
	m_BitMapRect.bottom =0;
}

BitMap* Card::CardImage()
{
	return m_pBitMap[CARD_FRONT];
}

// 800 1000 = 20��  4x5 ��ġ��  50�� ���� �θ�  ���� 5ĭ=250 ���� 6ĭ 300 ���� 550/4 = 100 (���� ù ��� �� ũ��) �� 700/5  =140

Card::~Card()
{

}
