#include "Weapon.h"

//�������� ���
void Weapon::Info(int x, int y)
{
	YELLOW
	m_MapDrawManager.DrawMidText(" ����Ÿ�� : " + GetTypeString(m_WeaponType)+" �����̸� : " + m_Name + " ���ݷ� : " + to_string(m_Atk), x, y);
	ORIGINAL
}

//�������� �������
void Weapon::ShowShopInfo(int x, int y)
{
	YELLOW
		m_MapDrawManager.DrawMidText("���� : " +to_string(m_Price) + " ����Ÿ�� : "+ GetTypeString(m_WeaponType), x, y);
		m_MapDrawManager.DrawMidText("�����̸� : " + m_Name + " ���ݷ� : " + to_string(m_Atk), x, y + 1);
	ORIGINAL
}

void Weapon::Save(ofstream& Save)
{
	Save << GetTypeString(m_WeaponType) << " ";
	Save << m_Name << " ";
	Save << m_Atk << " ";
	Save << m_Price;
}

string Weapon::GetTypeString(WEAPON Type)
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

Bow::Bow(string Name, int Damage, int Gold)
{
	m_Name= Name;
	m_Atk= Damage;
	m_Price= Gold;
	m_WeaponType= WEAPON_BOW;
}

Bow::~Bow()
{
}


Dagger::Dagger(string Name, int Damage, int Gold)
{
	m_Name = Name;
	m_Atk = Damage;
	m_Price = Gold;
	m_WeaponType = WEAPON_DAGGER;
}

Dagger::~Dagger()
{
}



Gun::Gun(string Name, int Damage, int Gold)
{
	m_Name = Name;
	m_Atk = Damage;
	m_Price = Gold;
	m_WeaponType = WEAPON_GUN;
}

Gun::~Gun()
{
}


Sword::Sword(string Name, int Damage, int Gold)
{
	m_Name = Name;
	m_Atk = Damage;
	m_Price = Gold;
	m_WeaponType = WEAPON_SWORD;
}

Sword::~Sword()
{
}

Wand::Wand(string Name, int Damage, int Gold)
{
	m_Name = Name;
	m_Atk = Damage;
	m_Price = Gold;
	m_WeaponType = WEAPON_WAND;
}

Wand::~Wand()
{
}

Hammer::Hammer(string Name, int Damage, int Gold)
{
	m_Name = Name;
	m_Atk = Damage;
	m_Price = Gold;
	m_WeaponType = WEAPON_HAMMER;
}

Hammer::~Hammer()
{
}
