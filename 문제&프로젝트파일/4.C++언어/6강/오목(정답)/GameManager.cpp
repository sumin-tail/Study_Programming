#include "GameManager.h"



GameManager::GameManager()
{
	m_bPlayState = false; //비 플레이 상태
	m_iTurn = 1; //턴 설정
	//디폴트 가로 세로 (20) 설정
	m_iHeight = HEIGHT;
	m_iWidth = WIDTH;
	//플레이어 아이콘 초기화
	m_Player[PLAYERTYPE_BLACK].SetCursorIcon(BLACKTEAMICON);
	m_Player[PLAYERTYPE_BLACK].SetStoneIcon(BLACKTEAMICON);
	m_Player[PLAYERTYPE_WHITE].SetCursorIcon(WHITETEAMICON);
	m_Player[PLAYERTYPE_WHITE].SetStoneIcon(WHITETEAMICON);
}

void GameManager::LobbyDraw() //시작메뉴 드로우
{
	m_DrawManager.DrawMidText("★ 오 목 ★", m_iWidth, m_iHeight* 0.3f);
	m_DrawManager.DrawMidText("1.게임 시작", m_iWidth, m_iHeight* 0.4f);
	m_DrawManager.DrawMidText("2.옵션 설정", m_iWidth, m_iHeight* 0.5f);
	m_DrawManager.DrawMidText("3.게임 종료", m_iWidth, m_iHeight* 0.6f);
	m_DrawManager.BoxDraw(m_iWidth, m_iHeight* 0.7, m_iWidth / 2, 3);
	m_DrawManager.gotoxy(m_iWidth, m_iHeight* 0.7 + 1);
}


void GameManager::DrawPoint() //해당 좌표 채우기 (바둑판/흰/검은동)
{
	m_DrawManager.Erase(m_Player[m_iTurn % 2].GetCursor().m_ix, m_Player[m_iTurn % 2].GetCursor().m_iy, m_iWidth, m_iHeight); //현재턴 좌표를 (바둑판)채움
	m_Player[PLAYERTYPE_BLACK].DrawStone(m_Player[m_iTurn % 2].GetCursor().m_ix, m_Player[m_iTurn % 2].GetCursor().m_iy);//해당좌표에 검은 돌이 있다면 채움
	m_Player[PLAYERTYPE_WHITE].DrawStone(m_Player[m_iTurn % 2].GetCursor().m_ix, m_Player[m_iTurn % 2].GetCursor().m_iy);//해당좌표에 하얀 돌이 있다면 채움
}

void GameManager::InputInfoDraw() //변하지 않는 조작키 설명 드로우
{
	m_DrawManager.DrawMidText("====조작키====", m_iWidth, m_iHeight);
	m_DrawManager.DrawMidText("이동 : A,S,W,D 돌놓기 : ENTER", m_iWidth, m_iHeight+1);
	m_DrawManager.DrawMidText("무르기 : N 옵션 : P 종료 : ESC", m_iWidth, m_iHeight + 2);
}

void GameManager::CurPlayerInfoDraw()//변하는 설명 드로우
{
	string Name = m_Player[m_iTurn % 2].GetName(); //해당턴의 플레이어 네임을 받아오고
	int UndoCount = m_Player[m_iTurn % 2].GetUndo(); //무르기 횟수 받아오고
	string str = "Player Name : " + Name + "       무르기 : " + to_string(UndoCount) + "  ";//이것들을 다 합쳐서
	m_DrawManager.DrawMidText(str, m_iWidth, m_iHeight + 3); //중간출력한다
	m_DrawManager.DrawMidText("Turn : " + to_string(m_iTurn) + "  " , m_iWidth, m_iHeight + 4);
}

void GameManager::Input() //입력받음
{
	char ch = getch();
	Point Cursor; //Point는 x좌표와 y좌표를 가지고 있음
	switch(ch)
	{
		case KEY_LEFT:
		case KEY_RIGHT:
		case KEY_UP:
		case KEY_DOWN:
			DrawPoint();
			m_Player[m_iTurn % 2].Move(ch, m_iWidth, m_iHeight);
			break;
		case KEY_ESC:
			m_bPlayState = false; //플레이 상태를 비플레이로 변경
			break;
		case KEY_DROP: //돌을 놨을 경우
			Cursor = m_Player[m_iTurn % 2].GetCursor();//현재 턴 플레이어의 좌표를 가지고 옴 
			if(m_Player[PLAYERTYPE_BLACK].CompareStone(Cursor.m_ix, Cursor.m_iy) || m_Player[PLAYERTYPE_WHITE].CompareStone(Cursor.m_ix, Cursor.m_iy))//해당좌표에 무슨색이든 돌이 있을경우
				break;//탈출
			m_Player[m_iTurn % 2].CreateStone();//아니라면 돌을 놓음
			if(m_Player[m_iTurn % 2].WinCheck(m_iWidth, m_iHeight))//승리 체크
			{
				m_bPlayState = false;//플레이 상태를 비플레이로 바꾸고
				m_DrawManager.DrawMidText(m_Player[m_iTurn % 2].GetName() + "팀 승리!!", m_iWidth, m_iHeight* 0.5f); //슬리한 플레이어 이름 출력
				getch();//아무거나 입력이들어오면
				return; //탈출
			}
			m_iTurn++; //턴수 늘림
			CurPlayerInfoDraw(); //하단 가이드 재출력
			break;
		case KEY_UNDO://무르기
			if(m_Player[m_iTurn % 2].GetUndo() > 0 && m_iTurn > 1) //무르기 횟수가 남아있고 / 턴이 1턴 이상일 경우
			{
				m_Player[m_iTurn % 2].EraseCursor(m_iWidth,m_iHeight); //현재 내 커서 좌표 지움
				m_Player[m_iTurn % 2].DownUndo(); //무르기 횟수 한칸 차감
				m_iTurn--; //턴수 -1
				m_Player[m_iTurn % 2].Undo(m_iWidth, m_iHeight);//무르기
				CurPlayerInfoDraw(); //하단 가이드 재출력
			}
			break;
		case KEY_OPTION:
			Option(); //옵션
			system("cls");//클리어
			m_DrawManager.Draw(m_iWidth, m_iHeight); //맵드로우
			InputInfoDraw(); //상단 가이드 재출력
			CurPlayerInfoDraw(); //하단 가이드 재출력
			m_Player[PLAYERTYPE_BLACK].AllStoneDraw(); //검은 돌 모두 재출력
			m_Player[PLAYERTYPE_WHITE].AllStoneDraw(); //흰 돌 모두 재출력
			break;
	}
}


void GameManager::SetName(string str,PLAYERTYPE type, int x, int y)
{
	m_DrawManager.DrawMidText(str, x,y); //P1 이름 중간에 출력
	m_DrawManager.DrawMidText("입력 : ", x, y + 1); //다음줄에 입력 : 출력
	m_Player[type].SetName(); //이름 cin으로 받아서 바로 플레이어 멤버 변수 m_strName에 집어넣음
	m_Player[type].PlayerSet(m_iWidth, m_iHeight); //플레이어 설정
}

void GameManager::GameStart()
{
	system("cls");//클리어
	m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight); //빈 박스 드로우
	SetName("P1 이름", PLAYERTYPE_BLACK, m_iWidth, m_iHeight * 0.3f);
	SetName("P2 이름", PLAYERTYPE_WHITE, m_iWidth, m_iHeight * 0.5f);
	system("cls");//클리어
	m_DrawManager.Draw(m_iWidth, m_iHeight); //바둑판 드로우
	InputInfoDraw();
	CurPlayerInfoDraw();
	while(m_bPlayState) //게임이 플레이중인 동안 
	{
		m_Player[m_iTurn % 2].DrawCursor(); //해당 턴 플레이어 커서 드로우
		Input();
	}
}

void GameManager::SetUndo()//무르기 설정
{
	while(1)
	{
		system("cls");
		int Height, Width;
		if(m_bPlayState == false)//플레이 상태가 아닐경우에만 
		{
			int Select;
			system("cls");
			m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
			m_DrawManager.DrawMidText("= Set Undo  =", m_iWidth, m_iHeight* 0.2f);
			m_DrawManager.DrawMidText("1.Set Undo Count", m_iWidth, m_iHeight* 0.3f);
			m_DrawManager.DrawMidText("2.Undo Off", m_iWidth, m_iHeight* 0.4f);
			m_DrawManager.DrawMidText("3.Return", m_iWidth, m_iHeight* 0.5f);
			m_DrawManager.DrawMidText("입력 : ", m_iWidth, m_iHeight* 0.6f);
			cin >> Select;
			switch(Select)
			{
				case 1:
					while(1)
					{
						system("cls");
						m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
						m_DrawManager.DrawMidText("무르기 횟수 입력(최대 10회) : ", m_iWidth, m_iHeight* 0.5f);
						cin >> Select;
						if(Select <= 10 && Select >= 0)
						{
							m_Player[PLAYERTYPE_BLACK].SetUndo(Select);
							m_Player[PLAYERTYPE_WHITE].SetUndo(Select);
							break;
						}
						m_DrawManager.DrawMidText("범위가 맞지 않습니다 ( 0 ~ 10 )", m_iWidth, m_iHeight* 0.6f);
						getch();
					}
					break;
				case 2:
					system("cls");
					m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
					m_DrawManager.DrawMidText("무르기 Off", m_iWidth, m_iHeight* 0.5f);
					m_Player[PLAYERTYPE_BLACK].SetUndo(0);
					m_Player[PLAYERTYPE_WHITE].SetUndo(0);
					getch();
					break;
				case 3:
					return;
			}
		}
		else
		{
			system("cls");
			m_DrawManager.DrawMidText("접근 불가능", m_iWidth, m_iHeight* 0.4f);
			m_DrawManager.DrawMidText("(Game Play중)", m_iWidth, m_iHeight* 0.5f);
			m_DrawManager.gotoxy(0, m_iHeight);
			system("pause");
			return;
		}
	}
}

void GameManager::SetMapSize()
{
	while(1)
	{
		system("cls");
		int Height, Width;
		if(m_bPlayState == false)
		{
			m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
			m_DrawManager.DrawMidText("Width :", m_iWidth, m_iHeight* 0.4f);
			cin >> Width;
			m_DrawManager.DrawMidText("Height : ", m_iWidth, m_iHeight* 0.6f);
			cin >> Height;
			if(Width >= 20 && Width <= 90 && Height >= 20 && Height <= 45)
			{
				m_iWidth = Width;
				m_iHeight = Height;
				char buf[256];
				sprintf(buf, "mode con: lines=%d cols=%d", m_iHeight + 5, (m_iWidth * 2) + 1);
				system(buf);
				return;
			}
			else
			{
				system("cls");
				m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
				m_DrawManager.DrawMidText("변경 불가능", m_iWidth, m_iHeight* 0.4f);
				m_DrawManager.DrawMidText("(가로 : 20 ~ 90 , 세로 : 20 ~ 45)", m_iWidth, m_iHeight* 0.5f);
				m_DrawManager.gotoxy(0, m_iHeight);
				getch();
			}
		}
		else
		{
			system("cls");
			m_DrawManager.DrawMidText("접근 불가능", m_iWidth, m_iHeight* 0.4f);
			m_DrawManager.DrawMidText("(Game Play중)", m_iWidth, m_iHeight* 0.5f);
			m_DrawManager.gotoxy(0, m_iHeight);
			system("pause");
			return;
		}
	}
}


void GameManager::SetCursor()
{
	int Select;
	system("cls");
	m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
	m_DrawManager.DrawMidText("= Set Cursor =", m_iWidth, m_iHeight* 0.2f);
	m_DrawManager.DrawMidText("1.○,●", m_iWidth, m_iHeight* 0.3f);
	m_DrawManager.DrawMidText("2.♡,♥", m_iWidth, m_iHeight* 0.4f);
	m_DrawManager.DrawMidText("3.☞,☜", m_iWidth, m_iHeight* 0.5f);
	m_DrawManager.DrawMidText("4.①,②", m_iWidth, m_iHeight* 0.6f);
	m_DrawManager.DrawMidText("5.Return", m_iWidth, m_iHeight* 0.7f);
	m_DrawManager.DrawMidText("입력 : ", m_iWidth, m_iHeight* 0.8f);
	cin >> Select;
	switch(Select)
	{
		case 1:
			m_Player[PLAYERTYPE_BLACK].SetCursorIcon("○");
			m_Player[PLAYERTYPE_WHITE].SetCursorIcon("●");
			system("pause");
			break;
		case 2:
			m_Player[PLAYERTYPE_BLACK].SetCursorIcon("♡");
			m_Player[PLAYERTYPE_WHITE].SetCursorIcon("♥");
			system("pause");
			break;
		case 3:
			m_Player[PLAYERTYPE_BLACK].SetCursorIcon("☞");
			m_Player[PLAYERTYPE_WHITE].SetCursorIcon("☜");
			system("pause");
			break;
		case 4:
			m_Player[PLAYERTYPE_BLACK].SetCursorIcon("①");
			m_Player[PLAYERTYPE_WHITE].SetCursorIcon("②");
			system("pause");
			break;
		case 5:
			return;
	}
}


void GameManager::SetStone()
{
	int Select;
	system("cls");
	m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
	m_DrawManager.DrawMidText("= Set Cursor =", m_iWidth, m_iHeight* 0.2f);
	m_DrawManager.DrawMidText("1.○,●", m_iWidth, m_iHeight* 0.3f);
	m_DrawManager.DrawMidText("2.♡,♥", m_iWidth, m_iHeight* 0.4f);
	m_DrawManager.DrawMidText("3.☏,☎", m_iWidth, m_iHeight* 0.5f);
	m_DrawManager.DrawMidText("4.①,②", m_iWidth, m_iHeight* 0.6f);
	m_DrawManager.DrawMidText("5.Return", m_iWidth, m_iHeight* 0.7f);
	m_DrawManager.DrawMidText("입력 : ", m_iWidth, m_iHeight* 0.8f);
	cin >> Select;
	switch(Select)
	{
		case 1:
			m_Player[PLAYERTYPE_BLACK].SetStoneIcon("○");
			m_Player[PLAYERTYPE_WHITE].SetStoneIcon("●");
			system("pause");
			break;
		case 2:
			m_Player[PLAYERTYPE_BLACK].SetStoneIcon("♡");
			m_Player[PLAYERTYPE_WHITE].SetStoneIcon("♥");
			system("pause");
			break;
		case 3:
			m_Player[PLAYERTYPE_BLACK].SetStoneIcon("☏");
			m_Player[PLAYERTYPE_WHITE].SetStoneIcon("☎");
			system("pause");
			break;
		case 4:
			m_Player[PLAYERTYPE_BLACK].SetStoneIcon("①");
			m_Player[PLAYERTYPE_WHITE].SetStoneIcon("②");
			system("pause");
			break;
		case 5:
			return;
	}
}

void GameManager::Option()
{
	int Select;
	while(1)
	{
		m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
		m_DrawManager.DrawMidText("= Option =", m_iWidth, m_iHeight* 0.2f);
		m_DrawManager.DrawMidText("1.Map Size Set", m_iWidth, m_iHeight* 0.3f);
		m_DrawManager.DrawMidText("2.Cursor Custom", m_iWidth, m_iHeight* 0.4f);
		m_DrawManager.DrawMidText("3.Stone Custom", m_iWidth, m_iHeight* 0.5f);
		m_DrawManager.DrawMidText("4.Undo Count Set", m_iWidth, m_iHeight* 0.6f);
		m_DrawManager.DrawMidText("5.Return", m_iWidth, m_iHeight* 0.7f);
		m_DrawManager.DrawMidText("입력 : ", m_iWidth, m_iHeight* 0.8f);
		cin >> Select;
		switch(Select)
		{
			case OPTIONMENU_MAPSIZE:
				SetMapSize();
				break;
			case OPTIONMENU_CURSOR:
				SetCursor();
				break;
			case OPTIONMENU_STONE:
				SetStone();
				break;
			case OPTIONMENU_UNDO:
				SetUndo();
				break;
			case OPTIONMENU_RETURN:
				return;
		}

	}
}

void GameManager::GameMain()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", m_iHeight+5, (m_iWidth*2)+1);
	system(buf);
	while(1)
	{
		system("cls");
		m_DrawManager.Draw(m_iWidth, m_iHeight);
		LobbyDraw();
		int Select;
		cin >> Select;
		switch(Select)
		{
			case LOBBYMENU_START:
				m_bPlayState = true; //플레이 상태를 플레이로 설정
				m_iTurn = 1; //턴수 설정
				GameStart();
				break;
			case LOBBYMENU_OPTION:
				Option();
				break;
			case LOBBYMENU_EXIT:
				return;
		}
	}
}

GameManager::~GameManager()
{
}
