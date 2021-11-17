#include "GameManager.h"

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
	int select;
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

		select = m_MapDrawManager.MenuSelectCursor(6, 2, 10, HEIGHT * 0.38f);
		switch (select)
		{
			//����
		case 1:
			break;
			//�÷��̾� ����
		case 2:
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
			//����
		case 6:
			return;
		}
	}
}

void GameManager::GameSetting(STARTTYPE type)
{
	switch (type)
	{
	case STARTTYPE_NEWSTART: //������
		PlayerSetting();
		break;
	case STARTTYPE_LOADSTART: //�̾��ϱ�
		SaveFileList();
		break;
	}
}

//�÷��̾� ����
void GameManager::PlayerSetting()
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //ȭ�� �����
	m_Player = new Character; //�� ĳ���� ���� �Ҵ�
	m_Player->SetName();
}

//������ ���� ����Ʈ ���
void GameManager::SaveFileList()
{
	string print = "������ : <���Ͽ��� : ";
	//��� ����  1������ : <���Ͽ��� : O> �Ǵ� X
	for (int i = 1; i < 11; i++)
	{
		if (true)
		{
			m_MapDrawManager.DrawMidText(print+"O>", WIDTH, HEIGHT * 0.3f);
		}
		else
		{

		}
	}
}
