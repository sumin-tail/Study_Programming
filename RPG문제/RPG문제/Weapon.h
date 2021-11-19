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
private:
	int m_Price; //가격
	WEAPON m_WeaponType; //무기타입
	string m_Name; //무기이름
	int m_Atk; //공격력
protected:

public:
	//-생성/소멸자//
	Weapon();
	virtual ~Weapon(); //소멸자 가상함수로
	//
	void PrintWeapon(int x, int y) //무기 정보 출력
	{

	}
	//-반환 함수-//
	inline int GetPrice() //가격 반환
	{
		return m_Price;
	}
	inline WEAPON GetType() //타입반환 - 샵에서 출력할때 써야함
	{
		return m_WeaponType;
	}
};

//활 클래스
class Bow : public Weapon
{

public:
	Bow();
	~Bow();
};

//단도 클래스
class Dagger : public Weapon
{

public:
	Dagger();
	~Dagger();
};

//총 클래스
class Gun : public Weapon
{

public:
	Gun();
	~Gun();
};

//검 클래스
class Sword : public Weapon
{

public:
	Sword();
	~Sword();
};

//지팡이 클래스
class Wand : public Weapon
{

public:
	Wand();
	~Wand();
};

//망치 클래스
class Hammer : public Weapon
{

public:
	Hammer();
	~Hammer();
};


