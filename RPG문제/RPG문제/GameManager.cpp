#include "GameManager.h"

//����(����) �޴�
void GameManager::MainMenu()
{
	m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //���� �׸���
	//���� �޴� ���
	m_MapDrawManager.DrawMidText("�١� DunGeonRPG �ڡ�",WIDTH, HEIGHT*0.4f);
	m_MapDrawManager.DrawMidText("New Game",WIDTH, HEIGHT*0.5f);
	m_MapDrawManager.DrawMidText("Load Game",WIDTH, HEIGHT*0.6f);
	m_MapDrawManager.DrawMidText("Game Exit",WIDTH, HEIGHT*0.7f);

	m_MapDrawManager.MenuSelectCursor(3, 3, 10, HEIGHT * 0.5f);
}

//�޴�
void GameManager::Menu()
{

}
