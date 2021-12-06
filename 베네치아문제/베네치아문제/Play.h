#pragma once
#include "Mecro.h"
#include "WordManager.h"
#include "Interface.h"

//전체 게임 흐름 제어 Class
//이름길이는 10글자 이하로 = 10글자까지는 oK
class Play
{
private:
	string m_name;
	int m_score;
	Interface m_DrawInterface;
public:
	void MainMenu();
};

