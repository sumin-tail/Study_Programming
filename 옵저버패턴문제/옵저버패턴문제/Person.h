#pragma once
#include "Mecro.h"
//(Person:��)
//Observer ���
//--�ʿ� ����
//1.�̸� ����
//2.���� ����
//3.��¥ ����

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

