#pragma once
#include "Mecro.h"
#include "WordManager.h"
#include "Interface.h"

#define SPEED 1000;

//전체 게임 흐름 제어 Class
//이름길이는 10글자 이하로 = 10글자까지는 oK
class Play
{
private:
	string m_name; //플레이어 이름
	int m_score; //플레이어 스코어
	int m_life; //플레이어 라이프
	Interface m_DrawInterface;//맵 드로우
	WordManager m_WordList; //화면에 있는 단어관리용
public:
	Play();
	~Play();
	void MainMenu();
	void PlayerDraw();
	void Intro();
};

