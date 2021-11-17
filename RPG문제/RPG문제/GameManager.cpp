#include "GameManager.h"

//메인(시작) 메뉴
void GameManager::MainMenu()
{
	int select;
	while (true)
	{
		m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //상자 그리기
        //메인 메뉴 출력
		m_MapDrawManager.DrawMidText("☆★ DunGeonRPG ★☆", WIDTH, HEIGHT * 0.4f);
		m_MapDrawManager.DrawMidText("New Game", WIDTH, HEIGHT * 0.5f);
		m_MapDrawManager.DrawMidText("Load Game", WIDTH, HEIGHT * 0.6f);
		m_MapDrawManager.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.7f);

		select = m_MapDrawManager.MenuSelectCursor(3, 3, 10, HEIGHT * 0.5f);
		switch (select)
		{
			//새 게임
		case 1:
			GameSetting(STARTTYPE_NEWSTART); 
			Menu();
			break;
			//이어하기
		case 2:
			GameSetting(STARTTYPE_LOADSTART);
			Menu();
			break;
			//게임 종료
		case 3:
			return;
		}
	}
}

//메뉴
void GameManager::Menu()
{
	int select;
	while (true)
	{
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
		m_MapDrawManager.DrawMidText("☆★ Menu ★☆", WIDTH, HEIGHT * 0.3f);
		m_MapDrawManager.DrawMidText("Dongeon", WIDTH, HEIGHT * 0.38f);
		m_MapDrawManager.DrawMidText("Player Info", WIDTH, HEIGHT * 0.44f);
		m_MapDrawManager.DrawMidText("Monster Info", WIDTH, HEIGHT * 0.5f);
		m_MapDrawManager.DrawMidText("Weapon Shop", WIDTH, HEIGHT * 0.58f);
		m_MapDrawManager.DrawMidText("Save", WIDTH, HEIGHT * 0.64f);
		m_MapDrawManager.DrawMidText("Exit", WIDTH, HEIGHT * 0.7f);

		select = m_MapDrawManager.MenuSelectCursor(6, 2, 10, HEIGHT * 0.38f);
		switch (select)
		{
			//던전
		case 1:
			break;
			//플레이어 정보
		case 2:
			break;
			//몬스터 정보
		case 3:
			break;
			//무기 상점
		case 4:
			break;
			//세이브
		case 5:
			break;
			//종료
		case 6:
			return;
		}
	}
}

void GameManager::GameSetting(STARTTYPE type)
{
	switch (type)
	{
	case STARTTYPE_NEWSTART: //새게임
		PlayerSetting();
		break;
	case STARTTYPE_LOADSTART: //이어하기
		SaveFileList();
		break;
	}
}

//플레이어 세팅
void GameManager::PlayerSetting()
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //화면 지우고
	m_Player = new Character; //새 캐릭터 동적 할당
	m_Player->SetName();
}

//세이프 파일 리스트 출력
void GameManager::SaveFileList()
{
	string print = "번슬롯 : <파일여부 : ";
	//출력 예시  1번슬롯 : <파일여부 : O> 또는 X
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
