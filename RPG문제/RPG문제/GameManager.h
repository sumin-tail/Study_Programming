#pragma once
#include "Mecro.h"
#include "Player.h"
#include "MapDraw.h"
#include "Monster.h"
#include "Shop.h"

class GameManager
{
private:
	//게임 매니저가 가지고있을 변수들- 플레이어 ,몬스터,상점,맵드로우
	Player* m_Player;
	Monster m_Monster;
	Shop m_Shop;
	MapDraw m_MapDrawManager;
protected:
	void Menu(); //메뉴
public:
	void MainMenu(); //메인(시작) 메뉴
};

