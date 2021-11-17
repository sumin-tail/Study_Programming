#include<iostream>
using namespace std;

//생성자 인자값 없이 자동으로 1 ~10까지의 총합을 구하는 Class를 만드시오.
//생성자의 인자값을 하나만 받고 1~받은 인자값 만큼의 총합을 구하는 class를 만드시오.
//생성자의 인자값을 두개를 받고 받은 두 개의 작은수에서 큰 수 까지의 총 합을 구하는 class를 만드시오.(예외처리 할 것)

class Quiz
{
private:
	int m_iNum1;
	int m_iNum2;
	int sum = 0;
public:
	Quiz()
	{
		for (int i = 1; i <= 10; i++)
		{
			sum += i;
		}
		cout << "Quiz 1() : " << sum << endl;
	}

	Quiz(int Num1)
	{
		m_iNum1 = Num1;
		for (int i = 1; i <= m_iNum1; i++)
		{
			sum += i;
		}
		cout << "Quiz 2(100) : " << sum << endl;
	}

	Quiz(int Num1, int Num2)
	{
		if (Num1> Num2)
		{
			m_iNum1 = Num2;
			m_iNum2 = Num1;
		}
		else
		{
			m_iNum1 = Num1;
			m_iNum2 = Num2;
		}

		for (int i = m_iNum1; i <= m_iNum2; i++)
		{
			sum += i;
		}
		cout << "Quiz 3(5, 10) : " << sum << endl;
	}

};

void  main()
{
	Quiz a;
	Quiz b(100);
	Quiz c(5, 10);
}
