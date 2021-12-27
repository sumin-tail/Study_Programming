#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

class Observer //������
{
public:
	//���� ������Ʈ �Լ�, ���� ��� �Լ�
	Observer() {}
	virtual ~Observer() {}
	virtual void Update() abstract;
	virtual void Print() abstract;
};

class Subject //�������
{
public:
	Subject() {}
	virtual ~Subject() { }
	virtual void Add(Observer*) abstract;	//������ �߰� �Լ�
	virtual void Update() abstract; //������ ���� ������Ʈ �Լ�
};

