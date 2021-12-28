#include "News.h"
News* News::m_Instance = NULL;

void News::Add(Observer* observer)
{
	m_ObserverList.push_back(observer);
}

void News::NewsUpdate()//뉴스 업데이트
{
	cout << "새로운 기사 내용을 입력 하시오" << endl;
	cin >> m_News;
	m_Time = CurrentDateTime();
}

void News::Update()//뉴스 전송 
{
	for (auto& Person : m_ObserverList)//전체 탐색
	{
		Person->Update(m_News, m_Time);
	}
}

void News::Print() //뉴스 시청
{
	for (auto& Person : m_ObserverList)//전체 탐색
	{
		Person->Print();
	}
	_getch();
}

string News::CurrentDateTime()
{
	time_t now = time(0); //현재 시간을 time_t 타입으로 저장.
	struct tm tstruct;
	tstruct = *localtime(&now);
	char buf[80];
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss

	return buf;
}
