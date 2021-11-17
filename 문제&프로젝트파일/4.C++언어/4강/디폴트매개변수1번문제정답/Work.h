#pragma once
#include<iostream>
using namespace std;
class Work
{
private:
	int m_iJobHour;
	int m_iJobDay;
	int m_iWorkHourly;
public:
	void SetVelue(int JobDay, int JobHour = 8, int WorkHourly = 7500);
	void ShowVelue();
	Work();
	~Work();
};

