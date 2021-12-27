#pragma once
#include "Mecro.h"
//(Person:고객)
//Observer 상속
//--필요 변수
//1.이름 변수
//2.뉴스 변수
//3.날짜 변수

class Person : public Observer
{
	string m_Name;
	string m_Time;
public:
	Person();
	~Person() {};
	void Update();
	void Print();
};

