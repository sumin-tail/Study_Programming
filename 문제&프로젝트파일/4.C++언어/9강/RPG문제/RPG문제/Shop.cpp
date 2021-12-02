#include "Shop.h"

int Shop::GetWeaponCount()
{
	return 0;
}

void Shop::ShopMenu(Character* Player)
{
	while (true)
	{
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
		m_MapDrawManager.DrawMidText("☆★ S H O P ★☆", WIDTH, HEIGHT * 0.3f);
		m_MapDrawManager.DrawMidText("Bow", WIDTH, HEIGHT * 0.38f);
		m_MapDrawManager.DrawMidText("Dagger", WIDTH, HEIGHT * 0.44f);
		m_MapDrawManager.DrawMidText("Gun", WIDTH, HEIGHT * 0.5f);
		m_MapDrawManager.DrawMidText("Sword", WIDTH, HEIGHT * 0.58f);
		m_MapDrawManager.DrawMidText("Wand", WIDTH, HEIGHT * 0.64f);
		m_MapDrawManager.DrawMidText("Hammer", WIDTH, HEIGHT * 0.7f);
		m_MapDrawManager.DrawMidText("돌아가기", WIDTH, HEIGHT * 0.78f);

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
		case 7: //돌아가기
			return;
		}
	}
}

void Shop::WeaponMenu(Character* Player, WEAPON Type)
{
	int page = 0;
	vector<Weapon*> weaponList;
	int i = 0;

	while (true)
	{
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
		m_MapDrawManager.DrawMidText("보유 Gold : " + to_string(Player->GetGold()), WIDTH, HEIGHT * 0.1f - 1);
		string type = GetTypeString(Type);
		if (type == "")
		{
			return;
		}

		m_MapDrawManager.DrawMidText(type+" Shop", WIDTH, HEIGHT * 0.1f + 1);
		weaponList = m_WeaponList[type];
		int count = (page + 1) * 5;
		int length = weaponList.size();
		length = (length > count) ? count : length;

		int print =0; //페이지 넘어갔을때 1번칸부터 출력하기위해서  i를 그대로 쓰면 화면밖으로 튀어나감
		for (i = page * 5; i < length; i++, print++)
		{
			weaponList[i]->ShowShopInfo(WIDTH, HEIGHT *(0.2f + print *0.1f)); 
		}
		int maxLen = print + 3;
		float printheight = (0.2f + print * 0.1f);
		m_MapDrawManager.DrawMidText("이전페이지", WIDTH, HEIGHT * printheight);
		m_MapDrawManager.DrawMidText("다음페이지", WIDTH, HEIGHT * printheight + 3);
		m_MapDrawManager.DrawMidText("나가기", WIDTH, HEIGHT * printheight + 6);

		int select = m_MapDrawManager.MenuSelectCursor(maxLen, 3, 5, HEIGHT*0.2f);
		if (select == maxLen)
		{//ㄴㅏ가기
			return;
		}
		else if(select == maxLen-1)
		{//다음페이지
			if (page < (weaponList.size() / 5))
			{
				page += 1;

			}		
		}
		else if (select == maxLen - 2)
		{//이전페이지
			if (page > 0)
			{
				page -= 1;
			}
		}
		else
		{//무기사기
			if (Player->GetGold() >= weaponList[select-1]->GetPrice())
			{
				Player->WeaponGet(weaponList[select-1]);
			}
		}
		
	}

}

string Shop::GetTypeString(WEAPON Type)
{
	switch (Type)
	{
	case WEAPON_BOW:
		return "Bow";
	case WEAPON_DAGGER:
		return "Dagger";
	case WEAPON_GUN:
		return "Gun";
	case WEAPON_SWORD:
		return "Sword";
	case WEAPON_WAND:
		return "Wand";
	case WEAPON_HAMMER:
		return "Hammer";
	}

	return "";
}

Shop::Shop() //생성될때 무기 리스트를 받아와야
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
			load >> price; //데이터를 가져오고

			if (type == "Bow")
			{
				ptr = new Bow(name, atk, price); //Weapon*로 업 캐스팅
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

			m_WeaponList[type].push_back(ptr); //업캐스팅된 Weapon* 을 list에 넣어줌
		}
	}
	load.close(); //파일 닫는것 잊지 않기
}


Shop::~Shop()
{
}
