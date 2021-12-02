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

//ĳ���� �̸� ����
void Character::SetName()
{
	YELLOW
	char check;
	m_MapDrawManager.DrawMidText("Player �̸� �Է� : ", WIDTH, HEIGHT * 0.5f);
	while (true)
	{
		if (_kbhit()) 
		{ // Ű���尡 ���ȴ�ġ üũ
			check = _getch(); // ���� �� ����
			if (check == '\r')
			{
				if (m_Name.empty())
				{
					m_MapDrawManager.DrawMidText("Player �̸� �Է� : ", WIDTH, HEIGHT * 0.5f);
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



//������� �÷��̾�/����)
void Character::Info(int x, int y)
{
	switch (m_Type)
	{
	case TYPE_PLAYER: //�÷��̾�� ��������� ����ϰ� ���ʹ� ������� ����ؾ� ��
		YELLOW
		m_MapDrawManager.DrawMidText("====="+m_Name+"("+ to_string(m_Lv)+"Lv)=====", x, y);
		m_MapDrawManager.DrawMidText("���ݷ� = "+ to_string(m_Atk) +"	����� = "+ to_string(m_CurHealth)+"/" +to_string(m_MaxHealth), x, y+1);
		m_MapDrawManager.DrawMidText("����ġ = "+ to_string(m_Exp) +"/"+ to_string(m_MaxExp)+"	 GetEXP : "+ to_string(m_GetExp), x, y+2);
		m_MapDrawManager.DrawMidText("Gold = "+ to_string(m_Gold), x, y+3);
		if (m_Weapon != NULL)
		{
			m_Weapon->Info(x ,y + 4);
		}
		ORIGINAL
		break;
	case TYPE_MONSTER:
		m_MapDrawManager.DrawMidText("=====" + m_Name + "(" + to_string(m_Lv) + "Lv)=====", x, y);
		m_MapDrawManager.DrawMidText("���ݷ� = " + to_string(m_Atk) + "	����� = " + to_string(m_CurHealth) + "/" + to_string(m_MaxHealth), x, y + 1);
		m_MapDrawManager.DrawMidText("����ġ = " + to_string(m_Exp) + "/" + to_string(m_MaxExp) + "	 GetEXP : " + to_string(m_GetExp), x, y + 2);
		m_MapDrawManager.DrawMidText("Gold = " + to_string(m_Gold), x, y + 3);
		break;
	}
}

//�÷��̾� ���� ����
void Character::SetInfo(ifstream& Load, TYPE Type, STARTTYPE StartType)
{

	switch (StartType)
	{
	case STARTTYPE_NEWSTART: //�����ϱ�
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
			m_GetExp = m_Exp; //���θ��� ĳ���ʹ� ���� ����ġ�� ���� ����ġ�� 0���� ����
			m_CurHealth = m_MaxHealth; //���θ��� ĳ���ʹ� ���� ü�°� �ִ�ü���� ����
			break;
		case TYPE_MONSTER:
			Load >> m_Name; //���ʹ� �̸��� ����������
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
	case STARTTYPE_LOADSTART: //�̾��ϱ�
	{
		Load >> m_Name; //���µ� ���Ͽ��� ������ ������
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
			//�������� ����
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
					m_Weapon = new Bow(name, atk, price); //Weapon*�� �� ĳ����
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

//���� ���̺�
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
		//���������� �߰��� ���ⵥ���͵� ����
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

//���� ������ ��
void Character::Hit(int Damage)
{
	m_CurHealth -= Damage; //����ü�¿��� ������ ��ŭ ����
	if (m_CurHealth < 0) //����ü���� 0 ���Ϸ� �������� 0���� �������
	{
		m_CurHealth = 0;
	}
}


//������ 
void Character::LvUp()
{
	PUPPLE
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
	m_MapDrawManager.DrawMidText(m_Name + "������!!", WIDTH, HEIGHT * 0.4f);
	//���ݻ��
	int Num;
	Num = rand() % UPATTACKSTAT + 1;
	m_Atk += Num;
	m_MapDrawManager.DrawMidText("���ݷ� "+to_string(Num) + " ����!!", WIDTH, HEIGHT * 0.5f);
	Num = rand() % UPHEALTHSTAT + 1;
	m_MaxHealth += Num;
	m_MapDrawManager.DrawMidText("����� " + to_string(Num) + " ����!!", WIDTH, HEIGHT * 0.6f);
	m_MaxExp += m_MaxExp * 0.3;
	//
	ResetHealth(); //���� ü���� Ǯ�� 
	ResetExp(); //����ġ�� ����
	ORIGINAL
	_getch();
}

//����ġ �ʱ�ȭ
void Character::ResetExp()
{
	m_Exp = 0;
}

//����ü�� �ʱ�ȭ
void Character::ResetHealth()
{
	m_CurHealth = m_MaxHealth;
}

//����ġ ��� > ��� �ȿ��� ������ üũ�ؼ� LvUp �Լ� �����ϴ°ɷ�
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