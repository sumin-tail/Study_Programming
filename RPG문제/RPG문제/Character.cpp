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

//�������
void Character::Info(int x, int y)
{
	switch (m_Type)
	{
	case TYPE_PLAYER: //�÷��̾�� ��������� ����ϰ� ���ʹ� ������� ����ؾ� ��
		YELLOW
		m_MapDrawManager.DrawMidText("====="+m_Name+"=====", x, y);
		ORIGINAL
		break;
	case TYPE_MONSTER:
		break;
	}
}

void Character::SetInfo(ifstream& Load, TYPE Type, STARTTYPE StartType)
{
	switch (StartType)
	{
	case STARTTYPE_NEWSTART:
		//����Ʈ �÷��̾� ������ ���ݷ� ����� ���������� �ʿ��� ����ġ �������ġ ���� ������� ������ ������ ����
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
			break;
		default:
			break;
		}
		break;
	case STARTTYPE_LOADSTART:
		break;
	}
}