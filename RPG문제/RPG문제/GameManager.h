#pragma once
#include "Mecro.h"
#include "Player.h"
#include "MapDraw.h"
#include "Monster.h"
#include "Shop.h"

class GameManager
{
private:
	//���� �Ŵ����� ���������� ������- �÷��̾� ,����,����,�ʵ�ο�
	Player* m_Player;
	Monster m_Monster;
	Shop m_Shop;
	MapDraw m_MapDrawManager;
protected:
	void Menu(); //�޴�
public:
	void MainMenu(); //����(����) �޴�
};

