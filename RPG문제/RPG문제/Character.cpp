#include "Character.h"

Character::Character()
{
	
}

Character::~Character()
{

}

//ĳ���� �̸� ����
void Character::SetName()
{
	YELLOW
	m_MapDrawManager.DrawMidText("Player �̸� �Է� : ", WIDTH, HEIGHT * 0.5f);
	cin >> m_Name;
	ORIGINAL
}

//�������9�÷��̾�/����)
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
			Load >> m_Exp;
			Load >> m_Lv;
			Load >> m_Gold;
			m_Type = TYPE_MONSTER;
			m_GetExp = m_Exp; 
			m_CurHealth = m_MaxHealth; 
			break;
		default:
			break;
		}
		break;
	case STARTTYPE_LOADSTART: //�̾��ϱ�
		switch (Type)
		{
		case TYPE_PLAYER:
			Load >> m_Name; //���µ� ���Ͽ��� ������ ������
			Load >> m_Atk;
			Load >> m_MaxHealth;
			Load >> m_MaxExp;
			Load >> m_GetExp;
			Load >> m_Lv;
			Load >> m_Gold;
			Load >> m_Exp;;
			Load >> m_CurHealth;
			//�������� ����
			break;
		case TYPE_MONSTER:
			break;
		default:
			break;
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