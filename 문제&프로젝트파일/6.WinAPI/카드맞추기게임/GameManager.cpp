#include "GameManager.h"

GameManager* GameManager::m_hThis = NULL; //�ʱ�ȭ

GameManager::GameManager() : m_WindowWidth(800), m_WindowHeight(1000) , m_GameState(GAME_MAIN), m_count(0)//�ϴ� �÷��� ���·� ��
{
	srand(time(NULL)); //�õ� �� �ʱ�ȭ
	m_CardList = new Card[IMAGE_BLACK*2]; //ī�帮��Ʈ
}

void GameManager::Init(HWND hWnd) //���� ����
{
	BitMapManager::GetInstance()->Init(hWnd); //ī�� �ʱ�ȭ
	MoveWindow(hWnd, 500, 0, m_WindowWidth, m_WindowHeight, true); //������ ������ �ٽ� �׸�  > �׸� ���� ��ǥ(X,Y) �� ���� ����(800x1000)������
	m_BackGround = BitMapManager::GetInstance()->GetImage(IMAGE_BACKGROUND); //�̹��� ��ġ �Ѱ���
	CardSetting(); //ī�� ���� ��ǥ �־���
}

void GameManager::Draw(HDC hdc)
{
	BackGroundDraw(hdc);
	//m_BackGround->Draw(hdc, 0, 0, m_WindowWidth, m_WindowHeight); //�� ��� ���� ��ο� �ϰ� ����

	switch (m_GameState) //���� ���¿� ���� ��ο�
	{
	case GAME_MAIN:
		MainDraw(hdc);
		break;
	case GAME_PLAY:
	case GAME_PAUSE:
		//BackGroundDraw(hdc);
		CardDraw(hdc);
		break;
	}
}

void GameManager::ColliderCheck(HWND hWnd, POINT Point)
{
	switch (m_GameState) //���� ���¿� ���� �ݶ��̴� üũ
	{
	case GAME_MAIN:
		GameStart(hWnd, Point);
		break;
	case GAME_PLAY:
		CardSelect(hWnd, Point);
		break;
	}
}

void GameManager::MainDraw(HDC hdc)
{
	Rectangle(hdc, 340, 590, 440, 630);
	std::string str = "�� �� �� ��";
	TextOutA(hdc, 350, 600, str.c_str(), str.length());
}

void GameManager::GameStart(HWND hWnd, POINT Point)
{
	RECT rect = { 340, 590, 440, 630 };
	if (PtInRect(&rect, Point))//�簢����ǥ ������ ������ üũ
	{
		m_GameState = GAME_PLAY;
		InvalidateRect(hWnd, NULL, true);
	}
	return;//�ƴ϶�� �� ���ư�
}


void GameManager::BackGroundDraw(HDC hdc)//��� ��ο�
{
	m_BackGround->Draw(hdc, 0, 0, m_WindowWidth, m_WindowHeight);
}

void GameManager::CardSetting() //ī�� ��ġ �迭
{
	std::vector<int> card; 
	for (int i = 0; i < IMAGE_BLACK; i++)
	{
		card.push_back(i);
		card.push_back(i);
	}

	int select;//���� ���� ���� ����
	int x = 50; 
	int y = 100;
	int count = 0;

	for (int i = IMAGE_START; i < IMAGE_BLACK*2; i++)
	{
		int select = rand() % card.size(); //�������� ī�� �̾Ƽ�
		if (count == 5)
		{
			count = 0;
			x = 50;
			y += 200; //ī�� ���� ������+���� ������(50)
		}
		m_CardList[i].Init((IMAGE)card[select] , x, y);//ī�帮��Ʈ�� �������
		m_CardList[i].CardRear();
		card.erase(card.begin() + select);
		x += 150; //ī�� ���� ������+���� ������(50)
		count++;
	}

}

void GameManager::CardDraw(HDC hdc)
{
	for (int i = IMAGE_START; i < IMAGE_BLACK*2; i++)
	{
		m_CardList[i].Draw(hdc);
	}
}

void GameManager::CardColliderCheck(HWND hWnd, POINT Point)
{
	for (int i = IMAGE_START; i < IMAGE_BLACK*2; i++)
	{
		if (m_CardList[i].ColliderCheck(Point))
		{
			if (m_CardSelect.size() != 0)//ó�� ���� ī�尡�ƴϰ�
			{
				if (m_CardSelect[0] != i) //���� ī��� ���� �ڸ��� ī�尡 �ƴ϶�� = ��ī��
				{
					m_CardList[i].CardFront();//�ո����� �ٲ���
					m_CardSelect.push_back(i);
					InvalidateRect(hWnd, NULL, true);
					CardMatch(hWnd);
				}				
			}
			else
			{
				m_CardList[i].CardFront();
				m_CardSelect.push_back(i);
				InvalidateRect(hWnd, NULL, true);
			}
		}
	}
}

void GameManager::CardSelect(HWND hWnd, POINT Point)//�÷��̾ ī�带 �ִ� 2������� ���� �����ϰ� �ϰ� / ������ ������������ CardMatch() ȣ��
{
	CardColliderCheck(hWnd, Point);
}

void GameManager::CardMatch(HWND hWnd) //�÷��̾ ������ ������ ī�尡 ¦�� �´��� �ƴ��� üũ
{
	if (m_CardList[m_CardSelect[0]].CardImage() == m_CardList[m_CardSelect[1]].CardImage())//���� �̹����̸� �´� ¦
	{
		m_CardList[m_CardSelect[0]].RectNULL(); //�ݶ��̴� ���ֹ���
		m_CardList[m_CardSelect[1]].RectNULL();
		m_count++;
		m_CardSelect.clear();
		if (m_count == 10)
		{
			if (MessageBox(hWnd, L"���� Ŭ����", L"�����մϴ�!", MB_OK) == IDOK)
			{
				Reset();
				InvalidateRect(hWnd, NULL, true);
			}
		}
	}
	else //���� ī�尡 �ƴ϶��
	{
		m_GameState = GAME_PAUSE;
		m_waitclock = clock();
		//m_CardList[m_CardSelect[0]].CardRear();
		//m_CardList[m_CardSelect[1]].CardRear();
		//m_CardSelect.clear();
	}
}

bool GameManager::Pause() //�Ͻ����� 
{
	if (m_GameState == GAME_PAUSE && clock() - m_waitclock >= WAITTIME) //���� ���°� �Ͻ������� /�Ͻ����̰� Ǯ�� �ð��� �Ǿ�����
	{
		m_CardList[m_CardSelect[0]].CardRear(); //ī�� �������ְ�
		m_CardList[m_CardSelect[1]].CardRear();
		m_CardSelect.clear(); //���õ� ī�� ����
		m_GameState = GAME_PLAY; //�ٽ� �÷��� ���·� ����
		return true;
	}
	return false;
}

void GameManager::Reset()
{
	m_GameState = GAME_MAIN;
	CardSetting(); //ī�� �ٽ� �����ְ�
	m_count = 0; //���� ī����� ������ 0 ���� �������
}

GameManager::~GameManager()
{
	delete[] m_CardList;
	delete BitMapManager::GetInstance();
}
