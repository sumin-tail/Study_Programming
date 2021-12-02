#include "GameManager.h"

GameManager::GameManager()
{
	srand(time(NULL)); //�����Ҷ� �õ尪��
}

GameManager::~GameManager()
{
	if (NULL != m_Player) //����ó��> �÷��̾ NULL�� ����Ű������ ���� ��
	{
		delete m_Player;
		m_Player = NULL;
	}
	if (NULL != m_Monster)
	{
		delete[] m_Monster;
		m_Monster = NULL;
	}
}

//����(����) �޴�
void GameManager::MainMenu()
{
	while (true)
	{
		m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //���� �׸���
        //���� �޴� ���
		m_MapDrawManager.DrawMidText("�١� DunGeonRPG �ڡ�", WIDTH, HEIGHT * 0.4f);
		m_MapDrawManager.DrawMidText("New Game", WIDTH, HEIGHT * 0.5f);
		m_MapDrawManager.DrawMidText("Load Game", WIDTH, HEIGHT * 0.6f);
		m_MapDrawManager.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.7f);

		int select = m_MapDrawManager.MenuSelectCursor(3, 3, 10, HEIGHT * 0.5f);
		switch (select)
		{
			//�� ����
		case 1:
			if (Load(STARTTYPE_NEWSTART) == false)
			{
				break;
			}
			Menu();
			break;
			//�̾��ϱ�
		case 2:
			if (Load(STARTTYPE_LOADSTART) == false)
			{
				break;
			}
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
	while (m_Player->GetHealth() != 0)
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
			_getch();//�Էµ����� �ڷ�
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
			m_Shop.ShopMenu(m_Player);
			break;
			//���̺�
		case 5:
			FileList(FILESTATE_SAVE);
			break;
			//����-> ����ȭ������ ���ư�
		case 6:
			return;
		}
	}

	if (NULL != m_Player) //����ó��> �÷��̾ NULL�� ����Ű������ ���� ��
	{
		delete m_Player;
		m_Player = NULL;
	}
	if (NULL != m_Monster)
	{
		delete[] m_Monster;
		m_Monster = NULL;
	}
}

//���� ȭ�� ���
void GameManager::Dongeon()
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
	m_MapDrawManager.DrawMidText("=====���� �Ա�=====", WIDTH, HEIGHT * 0.2f);
	for (int i = 0; i < m_MonsterCount; i++)
	{
		m_MapDrawManager.DrawMidText(to_string(i+1)+"�� ���� : ["+ m_Monster[i].GetName()+"]", WIDTH, HEIGHT*0.38f + i*2);
	}
	m_MapDrawManager.DrawMidText("���ư���", WIDTH, HEIGHT * 0.38f+ m_MonsterCount*2);

	int select = m_MapDrawManager.MenuSelectCursor(7, 2, 8, HEIGHT * 0.38f);
	switch (select)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
			Fight(m_Player, &m_Monster[select-1]);
		break;
	case 7:
		return;
	}
}

//����
void GameManager::Fight(Character* Player, Character* Monster)
{
	string RSPText[3] = { "����" ,"��", "����" };
	int playerRSP = NULL;
	int monsterRSP;

	m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //���� �׸���
	m_MapDrawManager.DrowBattleLine(WIDTH, HEIGHT * 0.5f); // ��Ʋ �� �����
	YELLOW
		m_MapDrawManager.DrawMidText("���� : 1   ���� : 2   �� : 3", WIDTH, HEIGHT * 0.3f);
	ORIGINAL
	Player->Info(WIDTH, HEIGHT * 0.1f); //�÷��̾� ���� ��ο�
	Monster->Info(WIDTH, HEIGHT * 0.8f); //���� ���� ��ο�

	while (Player->GetHealth() !=0 && Monster->GetHealth() !=0)//�÷��̾�� ������ ü���� �Ѵ� 0 �� �ƴҶ�
	{
		playerRSP = 10;
		//������ ������ ������ ������ �ٲ�� �ȵ� > ���� ü�� ���� ��
		//�׷� �׳� ������ ������ ���� ������ ü���� Ǯ�� ä���ָ� �Ǵ°� �ƴѰ�?
		while (playerRSP == 10)
		{
			if (_kbhit())//Ű���� �Է��� ���������
			{
				char select = _getch();
				switch (select)
				{
				case '1':
					playerRSP = RSP_SCISSORS;
					break;
				case '2':
					playerRSP = RSP_ROCK;
					break;
				case '3':
					playerRSP = RSP_PAPER;
				break;
				default:
					break;
				}
			}
		}
		m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //���� �׸���
		m_MapDrawManager.DrowBattleLine(WIDTH, HEIGHT * 0.5f); // ��Ʋ �� �����
		YELLOW
			m_MapDrawManager.DrawMidText("���� : 1   ���� : 2   �� : 3", WIDTH, HEIGHT * 0.3f);
		monsterRSP = Monster->GetRSP();
		m_MapDrawManager.DrawMidText(RSPText[playerRSP], WIDTH, HEIGHT * 0.4f);
		ORIGINAL
		m_MapDrawManager.DrawMidText(RSPText[monsterRSP], WIDTH, HEIGHT * 0.6f+1);

		auto result = playerRSP - monsterRSP;

		// ���� 0 �� 1 ���� 2   
		//�÷��̾� �¸� ����
		//����/���� -2  ��/���� 1  ����/�� 1
		// ���ͽ¸�����
		//����/���� 2   ��/���� -1   ����/�� -1

		//������
		RED //���� ��¿�
			if (result == 0) //���� ������쿡�� ���
			{
				m_MapDrawManager.DrawMidText("Draw", WIDTH, HEIGHT * 0.4f + 1);
				m_MapDrawManager.DrawMidText("Draw", WIDTH, HEIGHT * 0.6f);
			}
		//���Ͱ� ������ �ƴϰ� �÷��̾��� ���� ���ͺ��� ũ�ų� / ��Ŀ�� �������� �÷��̾ ������ ��� �÷��̾� �¸�
			else if (result == -2 || result == 1)
			{
				m_MapDrawManager.DrawMidText("Win", WIDTH, HEIGHT * 0.4f + 1);
				m_MapDrawManager.DrawMidText("Lose", WIDTH, HEIGHT * 0.6f);
				Monster->Hit(Player->GetAtk());
			}
			else //�̿��� ���� �÷��̾� �й�
			{
				m_MapDrawManager.DrawMidText("Lose", WIDTH, HEIGHT * 0.4f + 1);
				m_MapDrawManager.DrawMidText("Win", WIDTH, HEIGHT * 0.6f);
				Player->Hit(Monster->GetAtk());
			}
		ORIGINAL
		Player->Info(WIDTH, HEIGHT * 0.1f); //�÷��̾� ���� ��ο�
		Monster->Info(WIDTH, HEIGHT * 0.8f); //���� ���� ��ο�
	}

	if (Monster->GetHealth() == 0) //�÷��̾� �¸�
	{
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
		RED
		m_MapDrawManager.DrawMidText(Player->GetName()+" �¸�!!", WIDTH, HEIGHT * 0.3f);
		m_MapDrawManager.DrawMidText(Player->GetName()+ "�� ����ġ"+ to_string(Monster->GetExp())+"�� ������ϴ�.", WIDTH, HEIGHT * 0.4f);
		ORIGINAL

		_getch();
		Player->ExpUp(Monster->GetExp());
		Monster->ResetHealth();//���� ü�� ���� ����
	}
	else //���� �¸�
	{
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
		RED
		m_MapDrawManager.DrawMidText(Monster->GetName() + " �¸�!!", WIDTH, HEIGHT * 0.3f);
		m_MapDrawManager.DrawMidText(Monster->GetName() + "�� ����ġ" + to_string(Player->GetExp()) + "�� ������ϴ�.", WIDTH, HEIGHT * 0.4f);
		_getch();
		m_MapDrawManager.DrawMidText("Game Over", WIDTH, HEIGHT * 0.5f);
		ORIGINAL
	}
}

//���� �ε�
bool GameManager::Load(STARTTYPE StartType)
{
	if (m_Player != NULL)
	{
		delete m_Player;
	}

	if (m_Monster != NULL)
	{
		delete [] m_Monster;
	}

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
		return true;
	}
	case STARTTYPE_LOADSTART: //�̾��ϱ�
		return FileList(FILESTATE_LOAD); //���ϸ���Ʈ ��
		break;
	}
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

	if (select == 11)
	{
		return false;
	}

	m_PlayerFileName += to_string(select) + ".txt"; //������ ���ϸ����� �ٲ�
	m_MonsterFileName += to_string(select) + ".txt";

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
		save << m_MonsterCount <<endl;
		for (int i = 0; i < m_MonsterCount; i++)
		{
			m_Monster[i].FileSave(save);
		}
		save.close();
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
		m_MapDrawManager.DrawMidText("Save �Ϸ�", WIDTH, HEIGHT * 0.5f);
		_getch();
		return true;//����
	}
	return false;//����
	    break;
	case FILESTATE_LOAD:
		if (FileOpenCheck(m_PlayerFileName)&&FileOpenCheck(m_MonsterFileName))//������ ������-�����ϸ�-
		{
			m_Player = new Character; //�� ĳ���� ���� �Ҵ�
			ifstream load;
			load.open(m_PlayerFileName);// �÷��̾� ���� ����
			m_Player->SetInfo(load, TYPE_PLAYER, STARTTYPE_LOADSTART);
			load.close();

			load.open(m_MonsterFileName);//���� ���� ����
			load >> m_MonsterCount; // ���� ī��Ʈ ���� ������
			m_Monster = new Character[m_MonsterCount]; //���� ���� �����Ҵ�
			for (int i = 0; i < m_MonsterCount; i++) //��������
			{
				m_Monster[i].SetInfo(load, TYPE_MONSTER, STARTTYPE_LOADSTART);
			}
			m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
			m_MapDrawManager.DrawMidText("Load �Ϸ�", WIDTH, HEIGHT *0.5f);
			_getch();
			return true;
		}
		return false;
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
