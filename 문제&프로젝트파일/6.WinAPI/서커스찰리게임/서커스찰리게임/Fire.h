#pragma once
#include "BitMap.h"
#include "서커스찰리게임.h"
#include <list>

class Fire
{
private:
	BitMap* m_Fire; //불
	BitMap m_goal;
	float m_PosX;
	int m_MoveFire;
	float m_Animationtimer;
	int m_Width;//가로사이즈
	int m_Height;//세로사이즈
	RECT m_DeadCollider[10]; //사망콜라이더
	RECT m_GoalCollider;//골 콜라이더
public:
	Fire();
	~Fire();
	void ImageInit(HDC hdc, const char* name, int count, BitMap* arr);
	void Init(HDC hdc);
	void Update(float deltaTime, float speed, float pos);
	void AnimationUpdate(float deltaTime);
	bool DeadColliderCheck(RECT PlayerRect);
	bool GoalCheck(RECT PlayerRect);
	void Draw(HDC hdc);
	void Reset();
};

