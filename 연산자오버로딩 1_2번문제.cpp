#include <iostream>
using namespace std;


class Time
{
private:
	int m_iHour;
	int m_iMin;
public:
	void ShowTime();//총공부시간 출력
	Time operator + (Time time);
	Time() { m_iHour = 0, m_iMin = 0; };
	Time(int Hour, int Min);
	~Time();
};

void Time::ShowTime()
{
	cout << "총 공부시간 : "<< m_iHour <<" : " << m_iMin << endl;
}

Time Time::operator+(Time time)
{
	return Time();
}

Time::Time(int Hour, int Min)
{
}

Time::~Time()
{
}

void main()
{
	Time A;
	int Day = 0;
	while (true)
	{
		A.ShowTime();
		cout << "=====공부시간 관리 프로그램("<< Day << "Day)=====" << endl;
	}
}

