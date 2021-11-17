#pragma once
#include"Car.h"
#define CREATE_TIME 5000

class Gate
{
private:
	Car* m_pFront; //�պκ��� ����Ŵ
	Car* m_pRear; //�޺κ��� ����Ŵ
	int m_iCreateTimer; //����� �ð�
public:
	void Input();
	void Enqueue();
	void Update();
	void CreateCar();
	void Dequeue();
	Gate();
	~Gate();
};

