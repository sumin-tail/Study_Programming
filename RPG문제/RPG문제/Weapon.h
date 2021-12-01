#pragma once
#include "Mecro.h"
#include "MapDraw.h"
//여기서 상속 이용하기 무기- 무기하위분류(대거,활 등등)

//가격 ,무기타입,무기이름, 공격력
//무기타입
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

//무기 클래스
class Weapon
{
protected:
	int m_Price; //가격
	WEAPON m_WeaponType; //무기타입
	string m_Name; //무기이름
	int m_Atk; //공격력
	MapDraw m_MapDrawManager;
public:
	//-생성/소멸자//
	Weapon() {};
	virtual ~Weapon() {}; //소멸자 가상함수로

	void Info(int x, int y);//무기정보 출력
	void ShowShopInfo(int x, int y);//상점에서 정보출력
	void Save(ofstream& Save);//무기 정보 세이브

	//-반환 함수-//
	inline int GetPrice() //가격 반환
	{
		return m_Price;
	}
	string GetTypeString(WEAPON Type);
};

//활 클래스
class Bow : public Weapon
{

public:
	Bow() { m_WeaponType = WEAPON_BOW; }
	Bow(string Name, int Damage, int Gold);
	~Bow();
};

//단도 클래스
class Dagger : public Weapon
{

public:
	Dagger() { m_WeaponType = WEAPON_DAGGER; }
	Dagger(string Name, int Damage, int Gold);
	~Dagger();
};

//총 클래스
class Gun : public Weapon
{

public:
	Gun() { m_WeaponType = WEAPON_GUN; }
	Gun(string Name, int Damage, int Gold);
	~Gun();
};

//검 클래스
class Sword : public Weapon
{

public:
	Sword() { m_WeaponType = WEAPON_SWORD; }
	Sword(string Name, int Damage, int Gold);
	~Sword();
};

//지팡이 클래스
class Wand : public Weapon
{

public:
	Wand() { m_WeaponType = WEAPON_WAND; }
	Wand(string Name, int Damage, int Gold);
	~Wand();
};

//망치 클래스
class Hammer : public Weapon
{

public:
	Hammer() { m_WeaponType = WEAPON_HAMMER; }
	Hammer(string Name, int Damage, int Gold);
	~Hammer();
};


