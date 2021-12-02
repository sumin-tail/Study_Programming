#include "Character.h"

Character::Character() : m_Weapon(NULL)
{
	
}

Character::~Character()
{
	if (NULL != m_Weapon)
	{
		delete m_Weapon;
	}
}

//캐릭터 이름 설정
void Character::SetName()
{
	YELLOW
	char check;
	m_MapDrawManager.DrawMidText("Player 이름 입력 : ", WIDTH, HEIGHT * 0.5f);
	while (true)
	{
		if (_kbhit()) 
		{ // 키보드가 눌렸는치 체크
			check = _getch(); // 눌린 값 대입
			if (check == '\r')
			{
				if (m_Name.empty())
				{
					m_MapDrawManager.DrawMidText("Player 이름 입력 : ", WIDTH, HEIGHT * 0.5f);
					continue;
				}

				break;
			}
			else
			{
				m_Name += check;
				cout << check;
			}
		}
	}
	ORIGINAL
}

void Character::WeaponGet(Weapon* weapon)
{
	m_Gold -= weapon->GetPrice();
	m_Weapon = weapon;
}



//정보출력 플레이어/몬스터)
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
		if (m_Weapon != NULL)
		{
			m_Weapon->Info(x ,y + 4);
		}
		ORIGINAL
		break;
	case TYPE_MONSTER:
		m_MapDrawManager.DrawMidText("=====" + m_Name + "(" + to_string(m_Lv) + "Lv)=====", x, y);
		m_MapDrawManager.DrawMidText("공격력 = " + to_string(m_Atk) + "	생명력 = " + to_string(m_CurHealth) + "/" + to_string(m_MaxHealth), x, y + 1);
		m_MapDrawManager.DrawMidText("경험치 = " + to_string(m_Exp) + "/" + to_string(m_MaxExp) + "	 GetEXP : " + to_string(m_GetExp), x, y + 2);
		m_MapDrawManager.DrawMidText("Gold = " + to_string(m_Gold), x, y + 3);
		break;
	}
}

//플레이어 정보 설정
void Character::SetInfo(ifstream& Load, TYPE Type, STARTTYPE StartType)
{

	switch (StartType)
	{
	case STARTTYPE_NEWSTART: //새로하기
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
			Load >> m_Name; //몬스터는 이름이 정해져있음
			Load >> m_Atk;
			Load >> m_MaxHealth;
			Load >> m_MaxExp;
			Load >> m_GetExp;
			Load >> m_Lv;
			Load >> m_Gold;
			m_Exp = 0;
			m_Type = TYPE_MONSTER;
			m_CurHealth = m_MaxHealth; 
			break;
		}
		break;
	case STARTTYPE_LOADSTART: //이어하기
	{
		Load >> m_Name; //오픈된 파일에서 정보들 가져옴
		Load >> m_Atk;
		Load >> m_MaxHealth;
		Load >> m_MaxExp;
		Load >> m_GetExp;
		Load >> m_Lv;
		Load >> m_Gold;
		Load >> m_Exp;;
		Load >> m_CurHealth;
		switch (Type)
		{
		case TYPE_PLAYER:
		{
			m_Type = TYPE_PLAYER;
			//다음줄은 무기
			int check;
			Load >> check;
			if (check != 0)
			{
				string type;
				string name;
				int atk;
				int price;

				Load >> type;
				Load >> name;
				Load >> atk;
				Load >> price;

				if (type == "Bow")
				{
					m_Weapon = new Bow(name, atk, price); //Weapon*로 업 캐스팅
				}
				else if (type == "Dagger")
				{
					m_Weapon = new Dagger(name, atk, price);
				}
				else if (type == "Gun")
				{
					m_Weapon = new Gun(name, atk, price);
				}
				else if (type == "Sword")
				{
					m_Weapon = new Sword(name, atk, price);
				}
				else if (type == "Wand")
				{
					m_Weapon = new Wand(name, atk, price);
				}
				else if (type == "Hammer")
				{
					m_Weapon = new Hammer(name, atk, price);
				}

			}
		}
			break;
		case TYPE_MONSTER:
			m_Type = TYPE_MONSTER;
			break;
		}
	}
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
		//무기있으면 추가로 무기데이터도 저장
		if (m_Weapon !=NULL)
		{
			Save << "1 ";
			m_Weapon->Save(Save);
		}
		else
		{
			Save << NULL;
		}
		break;
	case TYPE_MONSTER:
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
	}
}

//공격 당했을 때
void Character::Hit(int Damage)
{
	m_CurHealth -= Damage; //현재체력에서 데미지 만큼 깎음
	if (m_CurHealth < 0) //현재체력이 0 이하로 떨어지면 0으로 만들어줌
	{
		m_CurHealth = 0;
	}
}


//레벨업 
void Character::LvUp()
{
	PUPPLE
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
	m_MapDrawManager.DrawMidText(m_Name + "레벨업!!", WIDTH, HEIGHT * 0.4f);
	//스텟상승
	int Num;
	Num = rand() % UPATTACKSTAT + 1;
	m_Atk += Num;
	m_MapDrawManager.DrawMidText("공격력 "+to_string(Num) + " 증가!!", WIDTH, HEIGHT * 0.5f);
	Num = rand() % UPHEALTHSTAT + 1;
	m_MaxHealth += Num;
	m_MapDrawManager.DrawMidText("생명력 " + to_string(Num) + " 증가!!", WIDTH, HEIGHT * 0.6f);
	m_MaxExp += m_MaxExp * 0.3;
	//
	ResetHealth(); //현재 체력을 풀로 
	ResetExp(); //경험치를 리셋
	ORIGINAL
	_getch();
}

//경험치 초기화
void Character::ResetExp()
{
	m_Exp = 0;
}

//현재체력 초기화
void Character::ResetHealth()
{
	m_CurHealth = m_MaxHealth;
}

//경험치 상승 > 상승 안에서 레벨업 체크해서 LvUp 함수 실행하는걸로
void Character::ExpUp(int exp)
{
	m_Exp += exp;
	if (m_Exp >= m_MaxExp)
	{
		LvUp();
	}
}

RSP Character::GetRSP()
{
	return  (RSP)(rand() % 3);
}