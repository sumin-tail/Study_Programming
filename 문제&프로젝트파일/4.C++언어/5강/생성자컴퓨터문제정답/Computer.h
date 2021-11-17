#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

//함수 이름을 잘 짓자

class Computer
{
private:
	string m_strname; 
	string m_strgr;
	string m_strcpu;
	string m_strmemo;
public:
	void display();
	void condition();
	void function();
	Computer();
	~Computer();
};

