#include "Person.h"

Person::Person()
{
	cout << "������ �̸��� �Է��Ͻÿ� : ";
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
	cout <<"		"<< m_Name << " ����" << endl;
}
