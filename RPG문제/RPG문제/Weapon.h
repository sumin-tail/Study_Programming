#pragma once
#include "Mecro.h"
#include "MapDraw.h"
//���⼭ ��� �̿��ϱ� ����- ���������з�(���,Ȱ ���)

//���� ,����Ÿ��,�����̸�, ���ݷ�
//����Ÿ��
enum WEAPON
{
	WEAPON_START,
	WEAPON_BOW =0,
	WEAPON_DAGGER,
	WEAPON_GUN,
	WEAPON_SWORD,
	WEAPON_WAND,
	WEAPON_HAMMER,
	WEAPON_END
};

//���� Ŭ����
class Weapon
{
protected:
	int m_Price; //����
	WEAPON m_WeaponType; //����Ÿ��
	string m_Name; //�����̸�
	int m_Atk; //���ݷ�
	MapDraw m_MapDrawManager;
public:
	//-����/�Ҹ���//
	Weapon() {};
	virtual ~Weapon() {}; //�Ҹ��� �����Լ���

	void Info(int x, int y);//�������� ���
	void ShowShopInfo(int x, int y);//�������� �������
	void Save(ofstream& Save);//���� ���� ���̺�

	//-��ȯ �Լ�-//
	inline int GetPrice() //���� ��ȯ
	{
		return m_Price;
	}
	string GetTypeString(WEAPON Type);
};

//Ȱ Ŭ����
class Bow : public Weapon
{

public:
	Bow() { m_WeaponType = WEAPON_BOW; }
	Bow(string Name, int Damage, int Gold);
	~Bow();
};

//�ܵ� Ŭ����
class Dagger : public Weapon
{

public:
	Dagger() { m_WeaponType = WEAPON_DAGGER; }
	Dagger(string Name, int Damage, int Gold);
	~Dagger();
};

//�� Ŭ����
class Gun : public Weapon
{

public:
	Gun() { m_WeaponType = WEAPON_GUN; }
	Gun(string Name, int Damage, int Gold);
	~Gun();
};

//�� Ŭ����
class Sword : public Weapon
{

public:
	Sword() { m_WeaponType = WEAPON_SWORD; }
	Sword(string Name, int Damage, int Gold);
	~Sword();
};

//������ Ŭ����
class Wand : public Weapon
{

public:
	Wand() { m_WeaponType = WEAPON_WAND; }
	Wand(string Name, int Damage, int Gold);
	~Wand();
};

//��ġ Ŭ����
class Hammer : public Weapon
{

public:
	Hammer() { m_WeaponType = WEAPON_HAMMER; }
	Hammer(string Name, int Damage, int Gold);
	~Hammer();
};


