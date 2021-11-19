#pragma once
#include "Mecro.h"
#include "Character.h"
#include "MapDraw.h"
#include "Shop.h"

enum FILESTATE
{
	FILESTATE_SAVE,
	FILESTATE_LOAD
};

//������ �����ΰ� enum Ȱ���ϱ�!! 
//����� Ȱ���ϱ� ����- �������� �� Ȱ���ϸ� �ɵ�
//���� �̸� �� ����
class GameManager
{
private:
	//���� �Ŵ����� ���������� ������- �÷��̾� ,����,����,�ʵ�ο�
	//�÷��̾�� ���Ͱ� �������ִ� �������� ���� = ���� ���� Ŭ������ ���� �������� �ʰ� �÷��̾� Ŭ������ Ȱ���ϴ� ������� ->�÷��̾� Ŭ�������ٴ� ĳ���� Ŭ������
	Character* m_Player; //�÷��̾�
	Character* m_Monster; //����
	Shop m_Shop; //����
	MapDraw m_MapDrawManager; //��ο츦 ���� ����
	string m_PlayerFileName;//�÷��̾� ���� �̸�
	string m_MonsterFileName;//���� ���� �̸�
	int m_MonsterCount; //���� ����(����)

	//--�ٸ������� ���� ���� ���� �Լ���--//
	void Menu(); //�޴�
	void GameSetting(STARTTYPE type); //���Ӽ��� - New ���� Load ���� üũ�ؼ� ����
	void Dongeon(); //���� �޴� ���
	//-���� ����-//
	void Save(); //���� ���̺�
	bool Load(STARTTYPE StartType); //���� �ε�
	bool FileList(FILESTATE State); //���ϸ���Ʈ ���
	//-����-/
	void Fight(Character* Player, Character* Monster);//�÷��̾�� ���� �ο�
public:
	//-����/�Ҹ���-//
	GameManager();
	~GameManager();
	//--//
	void MainMenu(); //����(����) �޴�
};

