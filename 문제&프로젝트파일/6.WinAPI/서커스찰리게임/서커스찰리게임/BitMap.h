#pragma once
#include "��Ŀ����������.h"
//��Ʈ�� �̹��� ��� ���� Ŭ���� 
class BitMap
{
private:
	HDC MemDC; //DC�ڵ�
	HBITMAP m_BitMap; //��Ʈ�� �ڵ�
	HBITMAP m_OldBitMap; //(��ü��)���� �ڵ�
	SIZE m_Size; //������
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

