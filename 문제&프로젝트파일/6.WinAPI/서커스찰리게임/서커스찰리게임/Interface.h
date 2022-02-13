#pragma once
#include "BitMap.h"
#include "서커스찰리게임.h"

class Interface
{
private:
	BitMap* m_Interface; //인터페이스 이미지
public:
	Interface();
	~Interface();
	void Init(HDC hdc);
	void Update(float deltaTime);
	void InterfaceDraw(HDC hdc, int windowWidth, float pos, int Life, int score, int bonus);
};

