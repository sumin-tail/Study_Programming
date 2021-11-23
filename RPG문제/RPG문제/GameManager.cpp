#include "GameManager.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
	if (NULL != m_Monster)
	{
		delete[] m_Monster;
		m_Monster = NULL;
	}
}

//����(����) �޴�
void GameManager::MainMenu()
{
	int select;
	while (true)
	{
		m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //���� �׸���
        //���� �޴� ���
		m_MapDrawManager.DrawMidText("�١� DunGeonRPG �ڡ�", WIDTH, HEIGHT * 0.4f);
		m_MapDrawManager.DrawMidText("New Game", WIDTH, HEIGHT * 0.5f);
		m_MapDrawManager.DrawMidText("Load Game", WIDTH, HEIGHT * 0.6f);
		m_MapDrawManager.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.7f);

		select = m_MapDrawManager.MenuSelectCursor(3, 3, 10, HEIGHT * 0.5f);
		switch (select)
		{
			//�� ����
		case 1:
			GameSetting(STARTTYPE_NEWSTART); 
			Menu();
			break;
			//�̾��ϱ�
		case 2:
			GameSetting(STARTTYPE_LOADSTART);
			Menu();
			break;
			//���� ����
		case 3:
			return;
		}
	}
}

//�޴�
void GameManager::Menu()
{
	while (true)
	{
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
		m_MapDrawManager.DrawMidText("�١� Menu �ڡ�", WIDTH, HEIGHT * 0.3f);
		m_MapDrawManager.DrawMidText("Dongeon", WIDTH, HEIGHT * 0.38f);
		m_MapDrawManager.DrawMidText("Player Info", WIDTH, HEIGHT * 0.44f);
		m_MapDrawManager.DrawMidText("Monster Info", WIDTH, HEIGHT * 0.5f);
		m_MapDrawManager.DrawMidText("Weapon Shop", WIDTH, HEIGHT * 0.58f);
		m_MapDrawManager.DrawMidText("Save", WIDTH, HEIGHT * 0.64f);
		m_MapDrawManager.DrawMidText("Exit", WIDTH, HEIGHT * 0.7f);

		int select = m_MapDrawManager.MenuSelectCursor(6, 2, 10, HEIGHT * 0.38f);
		switch (select)
		{
			//����
		case 1:
			Dongeon();
			break;
			//�÷��̾� ����
		case 2:
			m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
			m_Player->Info(WIDTH, HEIGHT * 0.5f); //�÷��̾� �������
			_getch();
			break;
			//���� ����
		case 3:
			m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
			//���� ���� ���-> �̰� ��� ���͸� ����ؾ���
			for (int i = 0; i < m_MonsterCount; i++)
			{
				m_Monster[i].Info(WIDTH, HEIGHT * 0.1f + i*4);
			}
			_getch();
			break;
			//���� ����
		case 4:
			break;
			//���̺�
		case 5:
			FileList(FILESTATE_SAVE);
			break;
			//����-> ����ȭ������ ���ư�
		case 6:
			delete m_Player;
			delete m_Monster;
			return;
		}
	}
}

//���� ȭ�� ���
void GameManager::Dongeon()
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
	m_MapDrawManager.DrawMidText("=====���� �Ա�=====", WIDTH, HEIGHT * 0.2f);
	m_MapDrawManager.DrawMidText("1�� ���� : [���]", WIDTH, HEIGHT * 0.38f);
	m_MapDrawManager.DrawMidText("2�� ���� : [��ũ]", WIDTH, HEIGHT * 0.44f);
	m_MapDrawManager.DrawMidText("3������ : [�����ΰ�]", WIDTH, HEIGHT * 0.5f);
	m_MapDrawManager.DrawMidText("4������ : [�����]", WIDTH, HEIGHT * 0.58f);
	m_MapDrawManager.DrawMidText("5������ : [���̷����ó]", WIDTH, HEIGHT * 0.64f);
	m_MapDrawManager.DrawMidText("6������ : [��ġ]", WIDTH, HEIGHT * 0.7f);
	m_MapDrawManager.DrawMidText("���ư���", WIDTH, HEIGHT * 0.78f);

	int select = m_MapDrawManager.MenuSelectCursor(7, 2, 8, HEIGHT * 0.38f);
	switch (select)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 7:
		return;
	}
}

//���� �÷��̾� ����
void GameManager::GameSetting(STARTTYPE type)
{
	switch (type)
	{
	case STARTTYPE_NEWSTART: //������
		Load(STARTTYPE_NEWSTART);
		break;
	case STARTTYPE_LOADSTART: //�̾��ϱ�
		Load(STARTTYPE_LOADSTART);
		break;
	}
}

//����
void GameManager::Fight(Character* Player, Character* Monster)
{
	m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //���� �׸���
	Player->Info(WIDTH, HEIGHT*0.1f);
	Monster->Info(WIDTH, HEIGHT*0.8f);
}

//���� �ε�
bool GameManager::Load(STARTTYPE StartType)
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //ȭ�� �����
	switch (StartType)
	{
	case STARTTYPE_NEWSTART: //������
	{
		m_PlayerFileName = "DefaultPlayer.txt";
		m_MonsterFileName = "DefaultMonster.txt";
		//�÷��̾�
		m_Player = new Character; //�� ĳ���� ���� �Ҵ�
		m_Player->SetName();
		ifstream load;
		load.open(m_PlayerFileName);
		if (!load.is_open()) //�ȿ����� ����
		{
			return false;
		}
		m_Player->SetInfo(load, TYPE_PLAYER, StartType);
		load.close();
		//����
		load.open(m_MonsterFileName);
		if (!load.is_open()) //�ȿ����� ����
		{
			return false; 
		}
		load >> m_MonsterCount;//���� ���� �޾ƿ�
		m_Monster = new Character[m_MonsterCount];//(Character*)malloc(sizeof(Character)*m_MonsterCount);
		for (int i = 0; i < m_MonsterCount; i++)
		{
			m_Monster[i].SetInfo(load, TYPE_MONSTER, StartType); //���� �־���
		}
		break;
	}
	case STARTTYPE_LOADSTART: //�̾��ϱ�
		m_Player = new Character; //�� ĳ���� ���� �Ҵ�
		FileList(FILESTATE_LOAD); //���ϸ���Ʈ ��
		return true;
		break;
	}
	return false;//������ �ӽ� ����
}

//������ ���� ����Ʈ ���
bool GameManager::FileList(FILESTATE State)
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //ȭ�� �����
	m_PlayerFileName = "SavePlayer";
	m_MonsterFileName = "SaveMonster";
	GREEN //���⼭ ����
	for (int i = 1; i < 11; i++)
	{
		if (FileOpenCheck(m_PlayerFileName + to_string(i)+".txt")&& FileOpenCheck(m_MonsterFileName+ to_string(i)+".txt"))
		{
			m_MapDrawManager.DrawMidText(to_string(i)+"������ : <���Ͽ��� : O>", WIDTH, HEIGHT*0.1f + i * 2);
		}
		else
		{
			m_MapDrawManager.DrawMidText(to_string(i) + "������ : <���Ͽ��� : X>", WIDTH, HEIGHT * 0.1f + i*2);
		}
	}
	m_MapDrawManager.DrawMidText("11.���ư���              ", WIDTH, HEIGHT * 0.1f + 22);
	ORIGINAL //������� ���̺� ���� ����Ʈ ��� 
	int select = m_MapDrawManager.MenuSelectCursor(11, 2, 7, HEIGHT * 0.1f+2);

	m_PlayerFileName += to_string(select) + ".txt"; //������ ���ϸ����� �ٲ�
	m_MonsterFileName = to_string(select) + ".txt";

	switch (State)
	{
	case FILESTATE_SAVE: //���� ���̺� �����ְ� - �÷��̾�� ���Ͷ� �Ѵ� ���Ѿ� ��- ����
	{
		ofstream save;
		//�÷��̾� ���̺�
		save.open(m_PlayerFileName);
		m_Player->FileSave(save);
		save.close();
		//���� ���̺�
		save.open(m_MonsterFileName);
		m_Monster->FileSave(save);
		save.close();
		return true;//����
	}
	    break;
	case FILESTATE_LOAD:
		if (FileOpenCheck(m_PlayerFileName))//������ ������-�����ϸ�-
		{
			ifstream load;
			load.open(m_PlayerFileName);// ���� ����
			m_Player->SetInfo(load, TYPE_PLAYER, STARTTYPE_LOADSTART);
			return true;
		}
		break;
	}
}

//�ش� ������ �ִ���(��������)Ȯ��
bool GameManager::FileOpenCheck(string filename)
{
	ifstream load;
	load.open(filename);
	if (load.is_open())
	{
		load.close(); //�ݾ��ְ� ���ư�
		return true;
	}
	load.close(); 
	return false;
}
