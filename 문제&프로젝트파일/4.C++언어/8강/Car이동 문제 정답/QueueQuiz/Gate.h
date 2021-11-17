#pragma once
#include"Car.h"
#define CREATE_TIME 5000

class Gate
{
private:
	Car* m_pFront; //앞부분을 가리킴
	Car* m_pRear; //뒷부분을 가리킴
	int m_iCreateTimer; //만드는 시간
public:
	void Input();
	void Enqueue();
	void Update();
	void CreateCar();
	void Dequeue();
	Gate();
	~Gate();
};

