#include "Shop.h"

int Shop::GetWeaponCount()
{


	return 0;
}

void Shop::ShopMenu(Character* Player)
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
	m_MapDrawManager.DrawMidText("�١� S H O P �ڡ�", WIDTH, HEIGHT * 0.3f);
	m_MapDrawManager.DrawMidText("Bow", WIDTH, HEIGHT * 0.38f);
	m_MapDrawManager.DrawMidText("Dagger", WIDTH, HEIGHT * 0.44f);
	m_MapDrawManager.DrawMidText("Gun", WIDTH, HEIGHT * 0.5f);
	m_MapDrawManager.DrawMidText("Sword", WIDTH, HEIGHT * 0.58f);
	m_MapDrawManager.DrawMidText("Wand", WIDTH, HEIGHT * 0.64f);
	m_MapDrawManager.DrawMidText("Hammer", WIDTH, HEIGHT * 0.7f);
	m_MapDrawManager.DrawMidText("���ư���", WIDTH, HEIGHT * 0.78f);

	int select = m_MapDrawManager.MenuSelectCursor(7, 2, 12, HEIGHT * 0.38f);
	switch (select)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		WeaponMenu(Player, (WEAPON)(select - 1));
		break;
	case 7: //���ư���
		return;
	}
}

void Shop::WeaponMenu(Character* Player, WEAPON Type)
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
	m_MapDrawManager.DrawMidText("���� Gold : "+ to_string(Player->GetGold()), WIDTH, HEIGHT * 0.1f-1);
	m_MapDrawManager.DrawMidText("Shop", WIDTH, HEIGHT * 0.1f+1);
	int i = 0;
	switch (Type)
	{
	case WEAPON_BOW: 
		for (list<Weapon*>::iterator iter = m_WeaponList.find("Bow")->second.begin(); iter != m_WeaponList.find("Bow")->second.end(); iter++,i++)
		{
			(*iter)->ShowShopInfo(WIDTH, HEIGHT * 0.2f+i*3);
		}
		break;
	case WEAPON_DAGGER:
		break;
	case WEAPON_GUN:
		break;
	case WEAPON_SWORD:
		break;
	case WEAPON_WAND:
		break;
	case WEAPON_HAMMER:
		break;
	default:
		break;
	}
	_getch();
	//m_MapDrawManager.DrawMidText("����������", x, y);
	//m_MapDrawManager.DrawMidText("����������", x, y);
	//m_MapDrawManager.DrawMidText("������", x, y);

}

string Shop::GetTypeString(WEAPON Type)
{
	return string();
}

Shop::Shop() //�����ɶ� ���� ����Ʈ�� �޾ƿ;�
{
	ifstream load;

	string type;
	string name;
	int atk;
	int price;

	Weapon* ptr;

	load.open("WeaponList.txt");
	if (load.is_open()) 
	{
		while (!load.eof())
		{
			load >> type;
			load >> name;
			load >> atk;
			load >> price; //�����͸� ��������

			if (type == "Bow")
			{
				ptr = new Bow(name, atk, price); //Weapon*�� �� ĳ����
			}
			else if (type == "Dagger")
			{
				ptr = new Dagger(name, atk, price);
			}
			else if (type == "Gun")
			{
				ptr = new Gun(name, atk, price);
			}
			else if (type == "Sword")
			{
				ptr = new Sword(name, atk, price);
			}
			else if (type == "Wand")
			{
				ptr = new Wand(name, atk, price);
			}
			else if (type == "Hammer")
			{
				ptr = new Hammer(name, atk, price);
			}

			m_WeaponList[type].push_back(ptr); //��ĳ���õ� Weapon* �� list�� �־���
		}
	}
	load.close(); //���� �ݴ°� ���� �ʱ�
}


Shop::~Shop()
{
}
