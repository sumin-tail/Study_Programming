#include "GameManager.h"

GameManager* GameManager::m_hThis = NULL; //초기화

GameManager::GameManager() : m_WindowWidth(800), m_WindowHeight(1000) , m_GameState(GAME_MAIN), m_count(0)//일단 플레이 상태로 둠
{
	srand(time(NULL)); //시드 값 초기화
	m_CardList = new Card[IMAGE_BLACK*2]; //카드리스트
}

void GameManager::Init(HWND hWnd) //게임 시작
{
	BitMapManager::GetInstance()->Init(hWnd); //카드 초기화
	MoveWindow(hWnd, 500, 0, m_WindowWidth, m_WindowHeight, true); //윈도우 사이즈 다시 그림  > 그릴 시작 좌표(X,Y) 랑 가로 세로(800x1000)사이즈
	m_BackGround = BitMapManager::GetInstance()->GetImage(IMAGE_BACKGROUND); //이미지 위치 넘겨줌
	CardSetting(); //카드 섞고 좌표 넣어줌
}

void GameManager::Draw(HDC hdc)
{
	BackGroundDraw(hdc);
	//m_BackGround->Draw(hdc, 0, 0, m_WindowWidth, m_WindowHeight); //뒷 배경 먼저 드로우 하고 난뒤

	switch (m_GameState) //게임 상태에 따라 드로우
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
	switch (m_GameState) //게임 상태에 따라 콜라이더 체크
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
	std::string str = "게 임 시 작";
	TextOutA(hdc, 350, 600, str.c_str(), str.length());
}

void GameManager::GameStart(HWND hWnd, POINT Point)
{
	RECT rect = { 340, 590, 440, 630 };
	if (PtInRect(&rect, Point))//사각형좌표 안인지 밖인지 체크
	{
		m_GameState = GAME_PLAY;
		InvalidateRect(hWnd, NULL, true);
	}
	return;//아니라면 걍 돌아감
}


void GameManager::BackGroundDraw(HDC hdc)//배경 드로우
{
	m_BackGround->Draw(hdc, 0, 0, m_WindowWidth, m_WindowHeight);
}

void GameManager::CardSetting() //카드 위치 배열
{
	std::vector<int> card; 
	for (int i = 0; i < IMAGE_BLACK; i++)
	{
		card.push_back(i);
		card.push_back(i);
	}

	int select;//랜덤 값을 담을 변수
	int x = 50; 
	int y = 100;
	int count = 0;

	for (int i = IMAGE_START; i < IMAGE_BLACK*2; i++)
	{
		int select = rand() % card.size(); //랜덤으로 카드 뽑아서
		if (count == 5)
		{
			count = 0;
			x = 50;
			y += 200; //카드 세로 사이즈+간격 사이즈(50)
		}
		m_CardList[i].Init((IMAGE)card[select] , x, y);//카드리스트에 집어넣음
		m_CardList[i].CardRear();
		card.erase(card.begin() + select);
		x += 150; //카드 가로 사이즈+간격 사이즈(50)
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
			if (m_CardSelect.size() != 0)//처음 들어온 카드가아니고
			{
				if (m_CardSelect[0] != i) //앞의 카드랑 같은 자리의 카드가 아니라면 = 새카드
				{
					m_CardList[i].CardFront();//앞면으로 바꿔줌
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

void GameManager::CardSelect(HWND hWnd, POINT Point)//플레이어가 카드를 최대 2장까지만 선택 가능하게 하고 / 두장을 선택했을때는 CardMatch() 호출
{
	CardColliderCheck(hWnd, Point);
}

void GameManager::CardMatch(HWND hWnd) //플레이어가 선택한 두장의 카드가 짝이 맞는지 아닌지 체크
{
	if (m_CardList[m_CardSelect[0]].CardImage() == m_CardList[m_CardSelect[1]].CardImage())//같은 이미지이면 맞는 짝
	{
		m_CardList[m_CardSelect[0]].RectNULL(); //콜라이더 없애버림
		m_CardList[m_CardSelect[1]].RectNULL();
		m_count++;
		m_CardSelect.clear();
		if (m_count == 10)
		{
			if (MessageBox(hWnd, L"게임 클리어", L"축하합니다!", MB_OK) == IDOK)
			{
				Reset();
				InvalidateRect(hWnd, NULL, true);
			}
		}
	}
	else //같은 카드가 아니라면
	{
		m_GameState = GAME_PAUSE;
		m_waitclock = clock();
		//m_CardList[m_CardSelect[0]].CardRear();
		//m_CardList[m_CardSelect[1]].CardRear();
		//m_CardSelect.clear();
	}
}

bool GameManager::Pause() //일시정지 
{
	if (m_GameState == GAME_PAUSE && clock() - m_waitclock >= WAITTIME) //현재 상태가 일시정지고 /일시저이가 풀린 시간이 되었으면
	{
		m_CardList[m_CardSelect[0]].CardRear(); //카드 뒤집어주고
		m_CardList[m_CardSelect[1]].CardRear();
		m_CardSelect.clear(); //선택된 카드 비우고
		m_GameState = GAME_PLAY; //다시 플레이 상태로 만듬
		return true;
	}
	return false;
}

void GameManager::Reset()
{
	m_GameState = GAME_MAIN;
	CardSetting(); //카드 다시 섞어주고
	m_count = 0; //맞춘 카드쌍의 갯수를 0 으로 만들어줌
}

GameManager::~GameManager()
{
	delete[] m_CardList;
	delete BitMapManager::GetInstance();
}
