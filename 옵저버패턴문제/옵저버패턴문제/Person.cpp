#include "Person.h"

Person::Person()
{
	cout << "������ �̸��� �Է��Ͻÿ� : ";
	cin >> m_Name;
}

void Person::Update()
{
}

void Person::Print()
{
	cout << m_Name;
}
