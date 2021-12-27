#include "Person.h"

Person::Person()
{
	cout << "고객님의 이름을 입력하시오 : ";
	cin >> m_Name;
}

void Person::Update()
{
}

void Person::Print()
{
	cout << m_Name;
}
