#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Weapon.h"

#define UPATTACKSTAT 4
#define UPHEALTHSTAT 10

//가위바위보  Rock Paper Scissors <대문자만 땀
enum RSP 
{
	RSP_START,
	RSP_ROCK = 0,
	RSP_PAPER,
	RSP_SCISSORS,
	RSP_END,
};

//플레이어인지 몬스터인지 구분을 위해 타입 만듬
enum TYPE 
{
	TYPE_PLAYER,
	TYPE_MONSTER,
};

class Character
{ 
private:
	string m_Name; //이름
	int	m_Atk; //공격력
	int	 m_CurHealth; //현재체력
	int	 m_MaxHealth; //최대체력
	int	 m_Exp; //현재 소지 경험치
	int	 m_MaxExp; //레벨업까지 필요한 경험치
	int	 m_GetExp; //지금까지 얻은 총 경험치
	int	 m_Lv; //레벨
	int	 m_Gold;//소지 골드
	TYPE m_Type; //몬스터 또는 플레이어 타입
	MapDraw m_MapDrawManager; //드로우를 위한 함수
	Weapon* m_Weapon; //무기를 담을 변수
public:
	//-생성/소멸자-//
	Character();
	~Character();

	void Hit(int Damage); //공격 당했을 때
	void LvUp(); //레벨업 
	void ResetExp(); //경험치 초기화
	void ResetHealth(); //현재체력 초기화(풀로)
	void ExpUp(int exp); //경험치 상승 > 상승 안에서 레벨업 체크해서 LvUp 함수 실행하는걸로
	void Info(int x, int y); //정보출력
	void FileSave(ofstream& Save); //세이브
	RSP GetRSP(); //가위바위보 랜덤값 반환

	//설정함수//
	void SetName();
	void WeaponGet(Weapon* weapon);
	void SetInfo(ifstream& Load, TYPE Type, STARTTYPE StartType);

	//-반환함수-//  -> 많이 쓸것 같은건 인라인으로
	inline string GetName()
	{
		return m_Name;
	}
	inline int GetAtk()
	{
		if (m_Weapon != NULL)
		{
			return m_Atk + m_Weapon->GetWeaponAtk();
		}
		return m_Atk;
	}
	inline int GetExp()
	{
		return m_GetExp;
	}
	inline int GetHealth()
	{
		return m_CurHealth;
	}
	inline int GetGold()
	{
		return m_Gold;
	}
};

