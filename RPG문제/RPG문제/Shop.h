#pragma once
#include"Weapon.h"
#include"MapDraw.h"
#include"Mecro.h"
#include"Character.h"

//�������- ���⸮��Ʈ ������ ���� ��
//�� ĳ�����̿� 
class Shop
{
private:
	MapDraw m_MapDrawManager; //��ο� ��
	Weapon m_pWeaponList; //���⸮��Ʈ
	int m_iWeaponCount; //���� ����
public:
	int GetWeaponCount();
	void ShopMenu(Character* Player);
	void WeaponMenu(Character* Player, WEAPON Type);
	string GetTypeString(WEAPON Type);
	Shop();
	~Shop();
};

