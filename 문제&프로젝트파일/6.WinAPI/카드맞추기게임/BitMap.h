#pragma once
#include<Windows.h>
#include<string>

class BitMap
{
private:
	HDC MemDC; //DC�ڵ�
	HBITMAP m_BitMap; //��Ʈ�� �ڵ�
	HBITMAP m_OldBitMap; //(��ü��)���� �ڵ�
	SIZE m_Size; //������
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

