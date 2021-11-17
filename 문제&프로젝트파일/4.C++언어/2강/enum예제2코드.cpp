#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

#define WEAPONMAX 5 

enum WEAPON
{
	WEAPON_START,//스타트는 0
	WEAPON_DAGGER = 0,
	WEAPON_GUN,
	WEAPON_SWORD,
	WEAPON_WAND,
	WEAPON_BOW,
	WEAPON_HAMMER,
	WEAPON_END, // 엔드는 6임  > 무기 종류는 6종류(0~5)
};

struct Weapon //무기 구조체
{
	WEAPON WeaponType; //무기 타입
	string Name; //무기이름
	int Damage;
	int Reach;
	int Speed;
};

void ShowWeapon(Weapon w)
{
	cout << "〓〓〓" << w.Name << "〓〓〓" << endl;
	cout << "공격력 : " << w.Damage << "  사정거리 : " << w.Reach << "m" << endl;
	cout << "공격속도 : 분당 " << w.Speed << "회 공격" << endl << endl;
}

void ShowWeaponList(Weapon* WeaponList, WEAPON p)//무기 리스트와 무기 타입
{
	cout << "=========";
	switch (p)
	{
	case WEAPON_DAGGER:
		cout << "Dagger";
		break;
	case WEAPON_GUN:
		cout << "Gun";
		break;
	case WEAPON_SWORD:
		cout << "Sword";
		break;
	case WEAPON_WAND:
		cout << "Wand";
		break;
	case WEAPON_BOW:
		cout << "Bow";
		break;
	case WEAPON_HAMMER:
		cout << "Hammer";
		break;
	default:
		break;
	}
	cout << "=========" << endl << endl;
	for (int i = 0; i < WEAPONMAX; i++)//무기 리스트를 끝까지 돌면서
	{
		if (WeaponList[i].WeaponType == p) //무기리스트에있는 무기타입이 WEAPON p와 같을경우
			ShowWeapon(WeaponList[i]); //무기를 출력함
	}
	cout << endl << "=========================" << endl << endl;
}

void main()
{
	//무기리스트 - 5개 들어감
	Weapon WeaponList[WEAPONMAX] = { { WEAPON_SWORD,"그레이트 소드",500,5,10 },
							 { WEAPON_BOW,"라이트보우",50,300,60 } ,
							 { WEAPON_BOW,"크로스보우",100,400,30 } ,
							 { WEAPON_GUN,"리볼버",50,700,30 } ,
							 { WEAPON_SWORD,"에고 소드",2000,4,20 } };

	for (int i = WEAPON_START; i < WEAPON_END; i++)
		ShowWeaponList(WeaponList, (WEAPON)i);//WEAPON 형변환 잊지 않기
}