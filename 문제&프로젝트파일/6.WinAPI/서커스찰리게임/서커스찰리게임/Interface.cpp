#include "Interface.h"

Interface::Interface()
{
	m_Interface = new BitMap[3];
}

Interface::~Interface()
{
	delete[] m_Interface;
}

void Interface::Init(HDC hdc)
{
	char buf[256]; //char형 배열생성
	for (int i = 0; i < 3; i++)
	{
		sprintf_s(buf, "Resource//interface_%d.bmp", i + 1); //이미지 위치 버퍼에 저장
		m_Interface[i].Init(hdc, buf);//배열 초기화
	}

}

void Interface::Update(float deltaTime)
{

}

void Interface::InterfaceDraw(HDC hdc, int windowWidth, float pos, int Life, int score, int bonus)
{
	SetTextColor(hdc, RGB(255, 255, 255)); //글자 색 변경
	SetBkColor(hdc, RGB(0, 0, 0)); //배경색 변경

	m_Interface[0].Draw(hdc, windowWidth * 0.5f - m_Interface[0].GetSize().cx * 0.5f, 10); //UI 라인

	for (int i = 0; i < Life; i++) //나중에 플레이어 라이프 받아와서 처리
	{
		m_Interface[1].Draw(hdc, 850 - m_Interface[1].GetSize().cx*i , 40);
	}

	if (pos > 9200)
	{
		pos = 9200;
	}

	char buf[256];
	//std::string str;
	for (int i = 0; i < 11; i++) //미터 표시
	{
		m_Interface[2].Draw(hdc, 50 + 1000*i - pos, 400);
		//str = std::to_string(100 - i * 10);
		sprintf_s(buf, "%d", 100 - i * 10);
		TextOutA(hdc, 70 + 1000 * i - pos, 405, buf, strlen(buf));
	}

	sprintf_s(buf, "score : %d                          bonus : %d", score, bonus);
	TextOutA(hdc, 200, 30, buf, strlen(buf));
}
