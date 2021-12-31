#include "BitMap.h"



BitMap::BitMap()
{
}

void BitMap::Init(HDC hdc,char* FileName) //DC와 파일 위치 받음
{
	MemDC = CreateCompatibleDC(hdc); //DC를 생성-> 그림을 그릴 도구 생성
	m_BitMap = (HBITMAP)LoadImageA(NULL, FileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE); //비트맵 이미지 받아옴
	m_OldBitMap = (HBITMAP)SelectObject(MemDC, m_BitMap); //도구에 뭘 그려야하는 지 연결
	BITMAP BitMap_Info; //비트맵 정보를 받을 비트맵 생성
	GetObject(m_BitMap, sizeof(BitMap_Info), &BitMap_Info); //비트맵 정보를 얻어옴
	m_Size.cx = BitMap_Info.bmWidth; //가로 얻어옴
	m_Size.cy = BitMap_Info.bmHeight; //세로 얻어옴
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
