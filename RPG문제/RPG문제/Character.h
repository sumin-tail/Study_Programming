#pragma once
#include "Mecro.h"
#include "MapDraw.h"

#define UPATK 4
#define UPHP 10

//����������  Rock Paper Scissors <�빮�ڸ� ��
enum RSP 
{
	RSP_START,
	RSP_ROCK = 0,
	RSP_PAPER,
	RSP_SCISSORS,
	RSP_END,
};

//�÷��̾����� �������� ������ ���� Ÿ�� ����
enum TYPE 
{
	TYPE_PLAYER,
	TYPE_MONSTER,
};

class Character
{ 
private:
	string m_Name; //�̸�
	int	m_Atk; //���ݷ�
	int	 m_CurHealth; //����ü��
	int	 m_MaxHealth; //�ִ�ü��
	int	 m_Exp; //���� ���� ����ġ
	int	 m_MaxExp; //���������� �ʿ��� ����ġ
	int	 m_GetExp; //���ݱ��� ���� �� ����ġ
	int	 m_Lv; //����
	int	 m_Gold;//���� ���
	TYPE m_Type; //���� �Ǵ� �÷��̾� Ÿ��
	MapDraw m_MapDrawManager; //��ο츦 ���� �Լ�
public:
	//-����/�Ҹ���-//
	Character();
	~Character();

	void Hit(); //���� ������ ��
	void Attack(); //�������� ��
	void LvUp(); //������ 
	bool ExpUp(); //����ġ ��� > ��� �ȿ��� ������ üũ�ؼ� LvUp �Լ� �����ϴ°ɷ�
	void Info(int x, int y); //�������
	//�����Լ�//
	void SetName();
	void SetInfo(ifstream& Load, TYPE Type, STARTTYPE StartType);

	//-��ȯ�Լ�-//  -> ���� ���� ������ �ζ�������
	inline string GetName()
	{
		return m_Name;
	}
	inline int GetAtk()
	{
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

