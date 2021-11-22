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
			m_Player->Info(WIDTH, HEIGHT * 0.5f); //플레이어 정보출력
			_getch();
			break;
			//몬스터 정보
		case 3:
			m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
			//몬스터 정보 출력-> 이건 모든 몬스터를 출력해야함
			break;
			//무기 상점
		case 4:
			break;
			//세이브
		case 5:
			FileList(FILESTATE_SAVE);
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
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //화면 지우고
	switch (StartType)
	{
	case STARTTYPE_NEWSTART: //새게임
	{
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
		m_Player = new Character; //새 캐릭터 동적 할당
		FileList(FILESTATE_LOAD); //파일리스트 엶
		break;
	}
	return false;//오류용 임시 리턴
}


//세이프 파일 리스트 출력
bool GameManager::FileList(FILESTATE State)
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //화면 지우고
	m_PlayerFileName = "SavePlayer";
	m_MonsterFileName = "SaveMonster";
	GREEN //여기서 부터
	for (int i = 1; i < 11; i++)
	{
		if (FileOpenCheck(m_PlayerFileName + to_string(i)+".txt")&& FileOpenCheck(m_MonsterFileName+ to_string(i)+".txt"))
		{
			m_MapDrawManager.DrawMidText(to_string(i)+"번슬롯 : <파일여부 : O>", WIDTH, HEIGHT*0.1f + i * 2);
		}
		else
		{
			m_MapDrawManager.DrawMidText(to_string(i) + "번슬롯 : <파일여부 : X>", WIDTH, HEIGHT * 0.1f + i*2);
		}
	}
	m_MapDrawManager.DrawMidText("11.돌아가기              ", WIDTH, HEIGHT * 0.1f + 22);
	ORIGINAL //여기까진 세이브 파일 리스트 출력 
	int select = m_MapDrawManager.MenuSelectCursor(11, 2, 7, HEIGHT * 0.1f+2);

	switch (State)
	{
	case FILESTATE_SAVE:
	{
		//파일 세이브 시켜주고 - 플레이어랑 몬스터랑 둘다 시켜야 함- 리턴
		ofstream save;
		save.open(m_PlayerFileName+ to_string(select) + ".txt");
		m_Player->FileSave(save);
		return true;//리턴
	}
	case FILESTATE_LOAD:
		//해당이름 파일을 열어서  로드 후 리턴

		break;
	}
}

//해당 파일이 있는지(열리는지)확인
bool GameManager::FileOpenCheck(string filename)
{
	ifstream load;
	load.open(filename);
	if (load.is_open())
	{
		load.close(); //닫아주고 돌아감
		return true;
	}
	load.close(); 
	return false;
}
