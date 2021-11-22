#include "Character.h"

Character::Character()
{
	
}

Character::~Character()
{

}

//캐릭터 이름 설정
void Character::SetName()
{
	YELLOW
	m_MapDrawManager.DrawMidText("Player 이름 입력 : ", WIDTH, HEIGHT * 0.5f);
	cin >> m_Name;
	ORIGINAL
}

//정보출력
void Character::Info(int x, int y)
{
	switch (m_Type)
	{
	case TYPE_PLAYER: //플레이어는 노란색으로 출력하고 몬스터는 흰색으로 출력해야 함
		YELLOW
		m_MapDrawManager.DrawMidText("====="+m_Name+"("+ to_string(m_Lv)+"Lv)=====", x, y);
		m_MapDrawManager.DrawMidText("공격력 = "+ to_string(m_Atk) +"	생명력 = "+ to_string(m_CurHealth)+"/" +to_string(m_MaxHealth), x, y+1);
		m_MapDrawManager.DrawMidText("경험치 = "+ to_string(m_Exp) +"/"+ to_string(m_MaxExp)+"	 GetEXP : "+ to_string(m_GetExp), x, y+2);
		m_MapDrawManager.DrawMidText("Gold = "+ to_string(m_Gold), x, y+3);
		ORIGINAL
		break;
	case TYPE_MONSTER:

		break;
	}
}

//플레이어 정보 설정
void Character::SetInfo(ifstream& Load, TYPE Type, STARTTYPE StartType)
{
	switch (StartType)
	{
	case STARTTYPE_NEWSTART:
		//디폴트 플레이어 파일은 공격력 생명력 레벨업까지 필요한 경험치 현재경험치 레벨 소지골드 순으로 가지고 있음
		switch (Type)
		{
		case TYPE_PLAYER:
			Load >> m_Atk;
			Load >> m_MaxHealth;
			Load >> m_MaxExp;
			Load >> m_Exp;
			Load >> m_Lv;
			Load >> m_Gold;
			m_Type = TYPE_PLAYER;
			m_GetExp = m_Exp; //새로만든 캐릭터니 현재 경험치와 얻은 경험치가 0으로 같음
			m_CurHealth = m_MaxHealth; //새로만든 캐릭터니 현재 체력과 최대체력이 같음
			break;
		case TYPE_MONSTER:
			break;
		default:
			break;
		}
		break;
	case STARTTYPE_LOADSTART:
		break;
	}
}

//파일 세이브
void Character::FileSave(ofstream& Save)
{
	switch (m_Type)
	{
	case TYPE_PLAYER:
		Save << m_Name << " ";
		Save << m_Atk << " ";
		Save << m_MaxHealth << " ";
		Save << m_MaxExp << " ";
		Save << m_GetExp << " ";
		Save << m_Lv << " ";
		Save << m_Gold << " ";
		Save << m_Exp << " ";
		Save << m_CurHealth << endl;
		break;
	case TYPE_MONSTER:

		break;
	}
}