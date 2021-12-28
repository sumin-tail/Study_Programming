#include "News.h"
News* News::m_Instance = NULL;

void News::Add(Observer* observer)
{
	m_ObserverList.push_back(observer);
}

void News::NewsUpdate()//���� ������Ʈ
{
	cout << "���ο� ��� ������ �Է� �Ͻÿ�" << endl;
	cin >> m_News;
	m_Time = CurrentDateTime();
}

void News::Update()//���� ���� 
{
	for (auto& Person : m_ObserverList)//��ü Ž��
	{
		Person->Update(m_News, m_Time);
	}
}

void News::Print() //���� ��û
{
	for (auto& Person : m_ObserverList)//��ü Ž��
	{
		Person->Print();
	}
	_getch();
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
