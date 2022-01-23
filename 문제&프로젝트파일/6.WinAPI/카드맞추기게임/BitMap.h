#pragma once
#include<Windows.h>
#include<string>

class BitMap
{
private:
	HDC MemDC; //DC핸들
	HBITMAP m_BitMap; //비트맵 핸들
	HBITMAP m_OldBitMap; //(교체전)원래 핸들
	SIZE m_Size; //사이즈
public:
	void Init(HDC hdc,char* FileName);
	void Draw(HDC hdc, int x, int y, int width, int height);
	inline SIZE GetSize()
	{
		return m_Size;
	}
	BitMap();
	~BitMap();
};

