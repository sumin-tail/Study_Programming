#pragma once
#include "BitMap.h"
#include "��Ŀ����������.h"

class Interface
{
private:
	BitMap* m_Interface; //�������̽� �̹���
public:
	Interface();
	~Interface();
	void Init(HDC hdc);
	void Update(float deltaTime);
	void InterfaceDraw(HDC hdc, int windowWidth, float pos, int Life, int score, int bonus);
};

