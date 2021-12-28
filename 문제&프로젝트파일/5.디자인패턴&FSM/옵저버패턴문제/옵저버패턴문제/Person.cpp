#include "Person.h"

Person::Person()
{
	cout << "°í°´´ÔÀÇ ÀÌ¸§À» ÀÔ·ÂÇÏ½Ã¿À : ";
	cin >> m_Name;
}

void Person::Update(string news, string day)
{
	m_News = news;
	m_Time = day;
}

void Person::Print()
{
	cout << m_Time << endl;
	cout << m_News << endl << endl;
	cout <<"		"<< m_Name << " °í°´´Ô" << endl;
}
