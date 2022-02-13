#pragma once
#include "BitMap.h"
#include "��Ŀ����������.h"
class BackGround
{
private:
	BitMap* m_Back; //��׶��� �̹���
	int m_BackWidth;
	int m_ClearMove;
	float m_Animationtimer;
	bool m_Clear;
	float m_PosX;
public:
	BackGround();
	~BackGround();
	void Init(HDC hdc);
	void Update(float deltaTime, float speed, float pos);
	void Reset();
	void BackGroundDraw(HDC hdc);
	void AnimationUpdate(float deltaTime);
	void Clear();
};

