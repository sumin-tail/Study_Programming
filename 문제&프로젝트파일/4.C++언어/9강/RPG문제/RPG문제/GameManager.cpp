#include "GameManager.h"

GameManager::GameManager()
{
	srand(time(NULL)); //시작할때 시드값줌
}

GameManager::~GameManager()
{
	if (NULL != m_Player) //예외처리> 플레이어가 NULL을 가리키고있지 않을 때
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

//메인(시작) 메뉴
void GameManager::MainMenu()
{
	while (true)
	{
		m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //상자 그리기
        //메인 메뉴 출력
		m_MapDrawManager.DrawMidText("☆★ DunGeonRPG ★☆", WIDTH, HEIGHT * 0.4f);
		m_MapDrawManager.DrawMidText("New Game", WIDTH, HEIGHT * 0.5f);
		m_MapDrawManager.DrawMidText("Load Game", WIDTH, HEIGHT * 0.6f);
		m_MapDrawManager.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.7f);

		int select = m_MapDrawManager.MenuSelectCursor(3, 3, 10, HEIGHT * 0.5f);
		switch (select)
		{
			//새 게임
		case 1:
			if (Load(STARTTYPE_NEWSTART) == false)
			{
				break;
			}
			Menu();
			break;
			//이어하기
		case 2:
			if (Load(STARTTYPE_LOADSTART) == false)
			{
				break;
			}
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
	while (m_Player->GetHealth() != 0)
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
			_getch();//입력들어오면 뒤로
			break;
			//몬스터 정보
		case 3:
			m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
			//몬스터 정보 출력-> 이건 모든 몬스터를 출력해야함
			for (int i = 0; i < m_MonsterCount; i++)
			{
				m_Monster[i].Info(WIDTH, HEIGHT * 0.1f + i*4);
			}
			_getch();
			break;
			//무기 상점
		case 4:
			m_Shop.ShopMenu(m_Player);
			break;
			//세이브
		case 5:
			FileList(FILESTATE_SAVE);
			break;
			//종료-> 메인화면으로 돌아감
		case 6:
			return;
		}
	}

	if (NULL != m_Player) //예외처리> 플레이어가 NULL을 가리키고있지 않을 때
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

//던전 화면 출력
void GameManager::Dongeon()
{
	m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
	m_MapDrawManager.DrawMidText("=====던전 입구=====", WIDTH, HEIGHT * 0.2f);
	for (int i = 0; i < m_MonsterCount; i++)
	{
		m_MapDrawManager.DrawMidText(to_string(i+1)+"층 던전 : ["+ m_Monster[i].GetName()+"]", WIDTH, HEIGHT*0.38f + i*2);
	}
	m_MapDrawManager.DrawMidText("돌아가기", WIDTH, HEIGHT * 0.38f+ m_MonsterCount*2);

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

//전투
void GameManager::Fight(Character* Player, Character* Monster)
{
	string RSPText[3] = { "바위" ,"보", "가위" };
	int playerRSP = NULL;
	int monsterRSP;

	m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //상자 그리기
	m_MapDrawManager.DrowBattleLine(WIDTH, HEIGHT * 0.5f); // 배틀 선 만들기
	YELLOW
		m_MapDrawManager.DrawMidText("가위 : 1   바위 : 2   보 : 3", WIDTH, HEIGHT * 0.3f);
	ORIGINAL
	Player->Info(WIDTH, HEIGHT * 0.1f); //플레이어 정보 드로우
	Monster->Info(WIDTH, HEIGHT * 0.8f); //몬스터 정보 드로우

	while (Player->GetHealth() !=0 && Monster->GetHealth() !=0)//플레이어와 몬스터의 체력이 둘다 0 이 아닐때
	{
		playerRSP = 10;
		//전투가 끝난후 몬스터의 정보는 바뀌면 안됨 > 현제 체력 같은 것
		//그럼 그냥 전투가 끝나면 닳은 몬스터의 체력을 풀로 채워주면 되는게 아닌가?
		while (playerRSP == 10)
		{
			if (_kbhit())//키보드 입력이 들어왔을경우
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
		m_MapDrawManager.BoxDraw(WIDTH, HEIGHT); //상자 그리기
		m_MapDrawManager.DrowBattleLine(WIDTH, HEIGHT * 0.5f); // 배틀 선 만들기
		YELLOW
			m_MapDrawManager.DrawMidText("가위 : 1   바위 : 2   보 : 3", WIDTH, HEIGHT * 0.3f);
		monsterRSP = Monster->GetRSP();
		m_MapDrawManager.DrawMidText(RSPText[playerRSP], WIDTH, HEIGHT * 0.4f);
		ORIGINAL
		m_MapDrawManager.DrawMidText(RSPText[monsterRSP], WIDTH, HEIGHT * 0.6f+1);

		auto result = playerRSP - monsterRSP;

		// 바위 0 보 1 가위 2   
		//플레이어 승리 조건
		//바위/가위 -2  보/바위 1  가위/보 1
		// 몬스터승리조건
		//바위/가위 2   보/바위 -1   가위/보 -1

		//판정존
		RED //승패 출력용
			if (result == 0) //둘이 같을경우에는 비김
			{
				m_MapDrawManager.DrawMidText("Draw", WIDTH, HEIGHT * 0.4f + 1);
				m_MapDrawManager.DrawMidText("Draw", WIDTH, HEIGHT * 0.6f);
			}
		//몬스터가 가위가 아니고 플레이어의 값이 몬스터보다 크거나 / 몬스커가 가위지만 플레이어가 바위일 경우 플레이어 승리
			else if (result == -2 || result == 1)
			{
				m_MapDrawManager.DrawMidText("Win", WIDTH, HEIGHT * 0.4f + 1);
				m_MapDrawManager.DrawMidText("Lose", WIDTH, HEIGHT * 0.6f);
				Monster->Hit(Player->GetAtk());
			}
			else //이외의 경우는 플레이어 패배
			{
				m_MapDrawManager.DrawMidText("Lose", WIDTH, HEIGHT * 0.4f + 1);
				m_MapDrawManager.DrawMidText("Win", WIDTH, HEIGHT * 0.6f);
				Player->Hit(Monster->GetAtk());
			}
		ORIGINAL
		Player->Info(WIDTH, HEIGHT * 0.1f); //플레이어 정보 드로우
		Monster->Info(WIDTH, HEIGHT * 0.8f); //몬스터 정보 드로우
	}

	if (Monster->GetHealth() == 0) //플레이어 승리
	{
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
		RED
		m_MapDrawManager.DrawMidText(Player->GetName()+" 승리!!", WIDTH, HEIGHT * 0.3f);
		m_MapDrawManager.DrawMidText(Player->GetName()+ "가 경험치"+ to_string(Monster->GetExp())+"를 얻었습니다.", WIDTH, HEIGHT * 0.4f);
		ORIGINAL

		_getch();
		Player->ExpUp(Monster->GetExp());
		Monster->ResetHealth();//몬스터 체력 원상 복귀
	}
	else //몬스터 승리
	{
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
		RED
		m_MapDrawManager.DrawMidText(Monster->GetName() + " 승리!!", WIDTH, HEIGHT * 0.3f);
		m_MapDrawManager.DrawMidText(Monster->GetName() + "가 경험치" + to_string(Player->GetExp()) + "를 얻었습니다.", WIDTH, HEIGHT * 0.4f);
		_getch();
		m_MapDrawManager.DrawMidText("Game Over", WIDTH, HEIGHT * 0.5f);
		ORIGINAL
	}
}

//파일 로드
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

	m_MapDrawManager.BoxErase(WIDTH, HEIGHT); //화면 지우고
	switch (StartType)
	{
	case STARTTYPE_NEWSTART: //새게임
	{
		m_PlayerFileName = "DefaultPlayer.txt";
		m_MonsterFileName = "DefaultMonster.txt";
		//플레이어
		m_Player = new Character; //새 캐릭터 동적 할당
		m_Player->SetName();
		ifstream load;
		load.open(m_PlayerFileName);
		if (!load.is_open()) //안열리면 리턴
		{
			return false;
		}
		m_Player->SetInfo(load, TYPE_PLAYER, StartType);
		load.close();
		//몬스터
		load.open(m_MonsterFileName);
		if (!load.is_open()) //안열리면 리턴
		{
			return false; 
		}
		load >> m_MonsterCount;//몬스터 종류 받아옴
		m_Monster = new Character[m_MonsterCount];//(Character*)malloc(sizeof(Character)*m_MonsterCount);
		for (int i = 0; i < m_MonsterCount; i++)
		{
			m_Monster[i].SetInfo(load, TYPE_MONSTER, StartType); //몬스터 넣어줌
		}
		return true;
	}
	case STARTTYPE_LOADSTART: //이어하기
		return FileList(FILESTATE_LOAD); //파일리스트 엶
		break;
	}
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

	if (select == 11)
	{
		return false;
	}

	m_PlayerFileName += to_string(select) + ".txt"; //선택한 파일명으로 바꿈
	m_MonsterFileName += to_string(select) + ".txt";

	switch (State)
	{
	case FILESTATE_SAVE: //파일 세이브 시켜주고 - 플레이어랑 몬스터랑 둘다 시켜야 함- 리턴
	{
		ofstream save;
		//플레이어 세이브
		save.open(m_PlayerFileName);
		m_Player->FileSave(save);
		save.close();
		//몬스터 세이브
		save.open(m_MonsterFileName);
		save << m_MonsterCount <<endl;
		for (int i = 0; i < m_MonsterCount; i++)
		{
			m_Monster[i].FileSave(save);
		}
		save.close();
		m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
		m_MapDrawManager.DrawMidText("Save 완료", WIDTH, HEIGHT * 0.5f);
		_getch();
		return true;//리턴
	}
	return false;//리턴
	    break;
	case FILESTATE_LOAD:
		if (FileOpenCheck(m_PlayerFileName)&&FileOpenCheck(m_MonsterFileName))//파일이 열리면-존재하면-
		{
			m_Player = new Character; //새 캐릭터 동적 할당
			ifstream load;
			load.open(m_PlayerFileName);// 플레이어 파일 열고
			m_Player->SetInfo(load, TYPE_PLAYER, STARTTYPE_LOADSTART);
			load.close();

			load.open(m_MonsterFileName);//몬스터 파일 열고
			load >> m_MonsterCount; // 몬스터 카운트 먼저 빼내고
			m_Monster = new Character[m_MonsterCount]; //몬스터 파일 동적할당
			for (int i = 0; i < m_MonsterCount; i++) //정보저장
			{
				m_Monster[i].SetInfo(load, TYPE_MONSTER, STARTTYPE_LOADSTART);
			}
			m_MapDrawManager.BoxErase(WIDTH, HEIGHT);
			m_MapDrawManager.DrawMidText("Load 완료", WIDTH, HEIGHT *0.5f);
			_getch();
			return true;
		}
		return false;
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
