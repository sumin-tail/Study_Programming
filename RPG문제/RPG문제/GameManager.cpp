#include "GameManager.h"

//메인(시작) 메뉴
void GameManager::MainMenu()
{
	m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //상자 그리기
	//메인 메뉴 출력
	m_MapDrawManager.DrawMidText("☆★ DunGeonRPG ★☆",WIDTH, HEIGHT*0.4f);
	m_MapDrawManager.DrawMidText("New Game",WIDTH, HEIGHT*0.5f);
	m_MapDrawManager.DrawMidText("Load Game",WIDTH, HEIGHT*0.6f);
	m_MapDrawManager.DrawMidText("Game Exit",WIDTH, HEIGHT*0.7f);

	m_MapDrawManager.MenuSelectCursor(3, 3, 10, HEIGHT * 0.5f);
}

//메뉴
void GameManager::Menu()
{

}
