#include<iostream>
using namespace std;

//������ ���ڰ� ���� �ڵ����� 1 ~10������ ������ ���ϴ� Class�� ����ÿ�.
//�������� ���ڰ��� �ϳ��� �ް� 1~���� ���ڰ� ��ŭ�� ������ ���ϴ� class�� ����ÿ�.
//�������� ���ڰ��� �ΰ��� �ް� ���� �� ���� ���������� ū �� ������ �� ���� ���ϴ� class�� ����ÿ�.(����ó�� �� ��)

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
