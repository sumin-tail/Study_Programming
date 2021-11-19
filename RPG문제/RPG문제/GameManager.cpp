#include "GameManager.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

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

		int select = m_MapDrawManager.MenuSelectCursor(6, 2, 10, HEIGHT * 0.38f);
		switch (select)
		{
			//던전
		case 1:
			Dongeon();
			break;
			//플레이어 정보
		case 2:
			m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
			m_Player->Info(WIDTH, HEIGHT * 0.7f);
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
			//종료-> 메인화면으로 돌아감
		case 6:
			delete m_Player;
			delete m_Monster;
			return;
		}
	}
}

//던전 화면 출력
void GameManager::Dongeon()
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
	m_MapDrawManager.DrawMidText("=====던전 입구=====", WIDTH, HEIGHT * 0.2f);
	m_MapDrawManager.DrawMidText("1층 던전 : [고블린]", WIDTH, HEIGHT * 0.38f);
	m_MapDrawManager.DrawMidText("2층 던전 : [오크]", WIDTH, HEIGHT * 0.44f);
	m_MapDrawManager.DrawMidText("3층던전 : [늑대인간]", WIDTH, HEIGHT * 0.5f);
	m_MapDrawManager.DrawMidText("4층던전 : [오우거]", WIDTH, HEIGHT * 0.58f);
	m_MapDrawManager.DrawMidText("5층던전 : [스켈레톤아처]", WIDTH, HEIGHT * 0.64f);
	m_MapDrawManager.DrawMidText("6층던전 : [리치]", WIDTH, HEIGHT * 0.7f);
	m_MapDrawManager.DrawMidText("돌아가기", WIDTH, HEIGHT * 0.78f);

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
	case STARTTYPE_NEWSTART: //새게임
		Load(STARTTYPE_NEWSTART);
		break;
	case STARTTYPE_LOADSTART: //이어하기
		Load(STARTTYPE_LOADSTART);
		break;
	}
}

//파일 로드
bool GameManager::Load(STARTTYPE StartType)
{
	switch (StartType)
	{
	case STARTTYPE_NEWSTART: //새게임
	{
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //화면 지우고
		m_Player = new Character; //새 캐릭터 동적 할당
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
	case STARTTYPE_LOADSTART: //이어하기

		break;
	}
	return false;//오류용 임시 리턴
}


//세이프 파일 리스트 출력
//1번슬롯 : <파일여부 : O>
bool GameManager::FileList(FILESTATE State)
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //화면 지우고
	//출력 예시  1번슬롯 : <파일여부 : O> 또는 X
	for (int i = 1; i < 11; i++)
	{
		if (true)
		{
		}
		else
		{
		}
	}
	return true;//오류용 임시 리턴
}
