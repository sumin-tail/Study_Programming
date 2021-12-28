#pragma once
#include "Mecro.h"
#include "News.h"

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
	string m_News;
public:
	Person();
	~Person() {};
	void Update(string news, string day);
	void Print();
};

