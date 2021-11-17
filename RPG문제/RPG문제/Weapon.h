#pragma once
#include "Mecro.h"
#include "MapDraw.h"
//���⼭ ��� �̿��ϱ� ����- ���������з�(���,Ȱ ���)

//���� ,����Ÿ��,�����̸�, ���ݷ�
//����Ÿ��
enum WEAPON
{
	WEAPON_BOW,
	WEAPON_DAGGER,
	WEAPON_GUN,
	WEAPON_SWORD,
	WEAPON_WAND,
	WEAPON_HAMMER,
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
	void PrintWeapon() //���� ���� ���
	{

	}
	//-��ȯ �Լ�-//
	inline int GetPrice() //���� ��ȯ
	{
		return m_Price;
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


