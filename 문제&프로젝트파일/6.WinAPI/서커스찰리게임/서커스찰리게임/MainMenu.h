#pragma once
#include "BitMap.h"
#include "서커스찰리게임.h"

//메인 메뉴 드로우용 클래스
class MainMenu
{
private:
	BitMap* m_Title; //타이틀
	BitMap* m_Menu; //메뉴
	BitMap m_Black; //검은 화면
	BitMap m_Point; //화살표
	float m_Animationtimer;
	int m_StarCount; // 별 색갈 변경용 변수
	int m_PointSelect; //화살표가 가르키는 메뉴 (번호)
public:
	MainMenu();
	~MainMenu();
	void ImageInit(HDC hdc, const char* name, int count, BitMap* arr);
	void Init(HDC hdc);
	void PointDraw(HDC hdc, int x, int y, int interval);
	void StarDraw(HDC hdc, int posX, int titleWidth, int titleHeight);
	void Update(float elapsed);
	void Draw(HDC hdc, int windowWidth, int windowHeight);
};

