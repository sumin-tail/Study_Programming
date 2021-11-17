#include "Work.h"



Work::Work()
{
}

void Work::SetVelue(int JobDay,int JobHour,int WorkHourly)
{
	m_iJobDay = JobDay;
	m_iJobHour = JobHour;
	m_iWorkHourly = WorkHourly;
}
void Work::ShowVelue()
{
	cout << "시급 : " << m_iWorkHourly << endl;
	cout << "일한 시간 : " << m_iJobHour <<"시간";
	cout << " 일한 날짜 : " << m_iJobDay <<"일" << endl;
	cout << "총 급여 : " << m_iJobDay * m_iJobHour * m_iWorkHourly << "원" << endl;
}


Work::~Work()
{
}
