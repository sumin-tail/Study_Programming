#include "BitMap.h"



BitMap::BitMap()
{
}

void BitMap::Init(HDC hdc,char* FileName) //DC�� ���� ��ġ ����
{
	MemDC = CreateCompatibleDC(hdc); //DC�� ����-> �׸��� �׸� ���� ����
	m_BitMap = (HBITMAP)LoadImageA(NULL, FileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE); //��Ʈ�� �̹��� �޾ƿ�
	m_OldBitMap = (HBITMAP)SelectObject(MemDC, m_BitMap); //������ �� �׷����ϴ� �� ����
	BITMAP BitMap_Info; //��Ʈ�� ������ ���� ��Ʈ�� ����
	GetObject(m_BitMap, sizeof(BitMap_Info), &BitMap_Info); //��Ʈ�� ������ ����
	m_Size.cx = BitMap_Info.bmWidth; //���� ����
	m_Size.cy = BitMap_Info.bmHeight; //���� ����
}
void BitMap::Draw(HDC hdc, int x, int y)
{
	StretchBlt(hdc, x, y, m_Size.cx, m_Size.cy, MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);
}

BitMap::~BitMap()
{
	SelectObject(MemDC, m_OldBitMap);
	DeleteObject(m_BitMap);
	DeleteDC(MemDC);
}
