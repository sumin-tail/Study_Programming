#include "GameManager.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

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
			m_Player->Info(WIDTH, HEIGHT * 0.7f);
			break;
			//���� ����
		case 3:
			break;
			//���� ����
		case 4:
			break;
			//���̺�
		case 5:
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

//���� �ε�
bool GameManager::Load(STARTTYPE StartType)
{
	switch (StartType)
	{
	case STARTTYPE_NEWSTART: //������
	{
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //ȭ�� �����
		m_Player = new Character; //�� ĳ���� ���� �Ҵ�
		m_Player->SetName();
		m_PlayerFileName = "DefaultPlayer.txt";
		ifstream load;
		load.open(m_PlayerFileName);
		if (load.is_open())
		{
			m_Player->SetInfo(load, TYPE_PLAYER, StartType);
			load.close();
			return true;
		}
		break;
	}
	case STARTTYPE_LOADSTART: //�̾��ϱ�

		break;
	}
	return false;//������ �ӽ� ����
}


//������ ���� ����Ʈ ���
//1������ : <���Ͽ��� : O>
bool GameManager::FileList(FILESTATE State)
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //ȭ�� �����
	//��� ����  1������ : <���Ͽ��� : O> �Ǵ� X
	for (int i = 1; i < 11; i++)
	{
		if (true)
		{
		}
		else
		{
		}
	}
	return true;//������ �ӽ� ����
}
