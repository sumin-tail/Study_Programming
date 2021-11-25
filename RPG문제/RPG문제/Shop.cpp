#include "Shop.h"

int Shop::GetWeaponCount()
{
	return 0;
}

void Shop::ShopMenu(Character* Player)
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
	m_MapDrawManager.DrawMidText("☆★ S H O P ★☆", WIDTH, HEIGHT * 0.3f);
	m_MapDrawManager.DrawMidText("Dagger", WIDTH, HEIGHT * 0.38f);
	m_MapDrawManager.DrawMidText("Gun", WIDTH, HEIGHT * 0.44f);
	m_MapDrawManager.DrawMidText("Sword", WIDTH, HEIGHT * 0.5f);
	m_MapDrawManager.DrawMidText("Wand", WIDTH, HEIGHT * 0.58f);
	m_MapDrawManager.DrawMidText("Bow", WIDTH, HEIGHT * 0.64f);
	m_MapDrawManager.DrawMidText("Hammer", WIDTH, HEIGHT * 0.7f);
	m_MapDrawManager.DrawMidText("돌아가기", WIDTH, HEIGHT * 0.78f);

	int select = m_MapDrawManager.MenuSelectCursor(7, 2, 12, HEIGHT * 0.38f);
	switch (select)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7: //돌아가기
		return;
	}
}

void Shop::WeaponMenu(Character* Player, WEAPON Type)
{
}

string Shop::GetTypeString(WEAPON Type)
{
	return string();
}

Shop::Shop() //생성될때 무기 리스트를 받아와야
{

}

Shop::~Shop()
{

}
