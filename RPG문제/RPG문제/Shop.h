#pragma once
#include"Weapon.h"
#include"MapDraw.h"
#include"Mecro.h"
#include"Character.h"

//무기상점- 무기리스트 가지고 있을 것
//업 캐스팅이용 
class Shop
{
private:
	MapDraw m_MapDrawManager; //드로우 용
	Weapon m_pWeaponList; //무기리스트
	int m_iWeaponCount; //무기 갯수
public:
	int GetWeaponCount();
	void ShopMenu(Character* Player);
	void WeaponMenu(Character* Player, WEAPON Type);
	string GetTypeString(WEAPON Type);
	Shop();
	~Shop();
};

