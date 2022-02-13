#pragma once
#include "BitMap.h"
#include "��Ŀ����������.h"
#include <list>

class Fire
{
private:
	BitMap* m_Fire; //��
	BitMap m_goal;
	float m_PosX;
	int m_MoveFire;
	float m_Animationtimer;
	int m_Width;//���λ�����
	int m_Height;//���λ�����
	RECT m_DeadCollider[10]; //����ݶ��̴�
	RECT m_GoalCollider;//�� �ݶ��̴�
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

