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
	cout << "�ñ� : " << m_iWorkHourly << endl;
	cout << "���� �ð� : " << m_iJobHour <<"�ð�";
	cout << " ���� ��¥ : " << m_iJobDay <<"��" << endl;
	cout << "�� �޿� : " << m_iJobDay * m_iJobHour * m_iWorkHourly << "��" << endl;
}


Work::~Work()
{
}
