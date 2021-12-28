#pragma once
#include "Mecro.h"

class News : public Subject 
{
	static News* m_Instance;
	string m_Time; //날짜변수
	string m_News; //뉴스정보
	vector <Observer*> m_ObserverList;//옵저버 vector 변수
	News() { }
public:
	~News() { }
	static News* get_instance()
	{
		if (NULL == m_Instance) m_Instance = new News;
		return m_Instance;
	}
	void Add(Observer* observer); //옵저버 추가함수(가상)
	void Update(); //옵저버 정보 업데이트 함수(가상)
	void NewsUpdate(); //News 정보 업데이트 함수
	void Print(); //옵져버들 정보 출력 함수
	string CurrentDateTime(); //현재 시간 받는 함수.
};

