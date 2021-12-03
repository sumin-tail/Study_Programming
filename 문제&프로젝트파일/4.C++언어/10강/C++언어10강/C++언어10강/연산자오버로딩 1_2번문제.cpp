#include <iostream>
using namespace std;


class Time
{
private:
	int m_iHour;
	int m_iMin;
public:
	void ShowTime();//�Ѱ��νð� ���
	Time operator + (Time time);
	Time() { m_iHour = 0, m_iMin = 0; };
	Time(int Hour, int Min);
	~Time();
};

void Time::ShowTime()
{
	cout << "�� ���νð� : "<< m_iHour <<" : " << m_iMin << endl;
}

Time Time::operator+(Time time)
{
	time.m_iHour += m_iHour;
	time.m_iMin += m_iMin;

	while (time.m_iMin >= 60)
	{
		time.m_iHour++;
		time.m_iMin -= 60;
	}
	return time;
}

Time::Time(int Hour, int Min)
{
	m_iHour = Hour;
	m_iMin = Min;
}

Time::~Time()
{

}

Time StudyTime()
{
	int Hour;
	int Min;
	cout << "�ð�  : ";
	cin >> Hour;
	cout << "��  : ";
	cin >> Min;
	return Time(Hour, Min);
}

void main()
{
	Time A;
	int Day = 1;
	int selet;
	while (true)
	{
		system("cls");
		A.ShowTime();
		cout << "=====���νð� ���� ���α׷�("<< Day << "Day)=====" << endl;
		cout << "\t\t1. �ð� ���" << endl;
		cout << "\t\t2. ����" << endl;
		cout << "\t\t�Է� : ";
		cin >> selet;
		switch (selet)
		{
		case 1:
			A = A+StudyTime();
			Day++;
			break;
		case 2:
			system("cls");
			A.ShowTime();
			return;
		default:
			break;
		}
	}
}

