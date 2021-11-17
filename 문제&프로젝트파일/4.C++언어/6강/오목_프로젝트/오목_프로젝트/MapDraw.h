#pragma once
#include"Mecro.h"

//맵 드로우 클래스
class MapDraw
{
public:
	//바둑판 그리는 함수 (메인메뉴/게임 플레이)
	void BoxDraw(int Width, int Height);
	//상자 그리는 함수(옵션)
	void SettingDraw(int Width, int Height);
	//상자 그리는 함수(메인 메뉴)
	void SettingMenuDraw(int Width, int Height, int startY);
	//외각(벽) 제외 클리어
	void Erase(int Width, int Height);
	//게임플레이 바둑판 빈곳 채우기
	void PlayingBoxEmpty(int Width, int Height, int x, int y);
	//메뉴 텍스트
	void MenuDraw(int Width, int Height);
	//해당 좌표 지우기
	void ErasePoint(int x, int y);
	//중간에 텍스트 출력해주는 함수
	void DrawMidText(string str, int x, int y);
	//일반 텍스트 출력
	void TextDraw(string str, int x, int y);
	//텍스트 리스트 출력
	void DrawMidTextList(const string str[], int Width, int Height,int len,float margin);
	//좌표 이동 함수
	static inline void gotoxy(int x, int y) 
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//해당 좌표로 이동
	}
	MapDraw();
	~MapDraw();
};
