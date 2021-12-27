#include "News.h"
News* News::m_Instance = NULL;

void News::Add(Observer* observer)
{
	m_ObserverList.push_back(observer);
}

void News::NewsUpdate()
{

}

void News::Update()
{

}

void News::Print()
{
	m_ObserverList.front()->Print();
}

string News::CurrentDateTime()
{
	time_t now = time(0); //���� �ð��� time_t Ÿ������ ����.
	struct tm tstruct;
	tstruct = *localtime(&now);
	char buf[80];
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss

	return buf;
}
