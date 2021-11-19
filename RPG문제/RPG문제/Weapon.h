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
private:
	int m_Price; //����
	WEAPON m_WeaponType; //����Ÿ��
	string m_Name; //�����̸�
	int m_Atk; //���ݷ�
protected:

public:
	//-����/�Ҹ���//
	Weapon();
	virtual ~Weapon(); //�Ҹ��� �����Լ���
	//
	void PrintWeapon(int x, int y) //���� ���� ���
	{

	}
	//-��ȯ �Լ�-//
	inline int GetPrice() //���� ��ȯ
	{
		return m_Price;
	}
	inline WEAPON GetType() //Ÿ�Թ�ȯ - ������ ����Ҷ� �����
	{
		return m_WeaponType;
	}
};

//Ȱ Ŭ����
class Bow : public Weapon
{

public:
	Bow();
	~Bow();
};

//�ܵ� Ŭ����
class Dagger : public Weapon
{

public:
	Dagger();
	~Dagger();
};

//�� Ŭ����
class Gun : public Weapon
{

public:
	Gun();
	~Gun();
};

//�� Ŭ����
class Sword : public Weapon
{

public:
	Sword();
	~Sword();
};

//������ Ŭ����
class Wand : public Weapon
{

public:
	Wand();
	~Wand();
};

//��ġ Ŭ����
class Hammer : public Weapon
{

public:
	Hammer();
	~Hammer();
};


