#pragma once
#include "서커스찰리게임.h"
//비트맵 이미지 담고 있을 클래스 
class BitMap
{
private:
	HDC MemDC; //DC핸들
	HBITMAP m_BitMap; //비트맵 핸들
	HBITMAP m_OldBitMap; //(교체전)원래 핸들
	SIZE m_Size; //사이즈
public:
	void Init(HDC hdc, char* FileName);
	void Draw(HDC backDC, int x, int y, int width, int height);
	void Draw(HDC backDC, int x, int y);
	inline SIZE GetSize()
	{
		return m_Size;
	}
	BitMap();
	~BitMap();
};

