#include "Number.h"



Number::Number()
{
	string str;
	m_czNumber = NULL;
	while (1)
	{
		cout << "전화번호 입력 : ";
		cin >> str;
		if (str[1] == '1' && str.length() == 11)
		{
			SetNumber(3, 8, str);
			break;
		}
		else if (str[1] == '2' && str.length() == 9)
		{
			SetNumber(2, 6, str);
			break;
		}
		else if (str[1] >= '3' && str[1] <= '6' && str.length() == 10)
		{
			SetNumber(3, 7, str);
			break;
		}
		else
		{
			cout << "번호를 잘못 입력하셧습니다" << endl;
			system("pause");
		}
	}
}


void Number::SetNumber(int FirstBar, int SecondBar, string str)//FirstBar, SecondBar.....이 생각을 왜 못했지
{
	int i, j;
	if (m_czNumber != NULL)
		delete[] m_czNumber;
	m_czNumber = new char[str.length() + 3];
	for (i = 0, j = 0; j < str.length(); i++)// i와 j를 동시에 선언하고 조건식을 j < str.length()로 해놓아서 식이 더 깔끔하다 
	{
		if (i == FirstBar || i == SecondBar)
			m_czNumber[i] = '-';
		else
		{
			m_czNumber[i] = str[j];
			j++;
		}
	}
	m_czNumber[i] = NULL;
}

void Number::NumberDraw()
{
	cout << "완성된 번호 : " << m_czNumber << endl;
}

Number::~Number()
{
	delete[] m_czNumber;
}
