#include "Play.h"

//시작 사이즈는 20 20 이지만 실제로 좌표 사이즈는 40 20
//콘솔창 y축+5 해놓을것 (조작법)

//생성자
Play::Play()
{
	m_iWidth = STARTSIZE;//가로
	m_iHeight = STARTSIZE;//세로

	m_iUndoCount = STARTUNDO; //무르기 횟수
	m_iCursor = STARTSHAPE; //커서 기본모양 설정
	m_iStone = STARTSHAPE; //플레이어 돌 기본모양 설정

	m_bPlayCheck = false;
}

//소멸자
Play::~Play()
{

}

//시작 메뉴 화면
void Play::MenuScreen()
{
	int select;
	const string menuText [] = { "★ 오 목 ★","1.게임 시작","2.옵션 설정", "3.게임 종료"};

	while (1)
	{
		system("cls");
		m_DrawManager.BoxDraw(m_iWidth, m_iHeight);
		//아래 글자는 맵 사이즈 마다 간격이 달라짐
		m_DrawManager.DrawMidTextList(menuText, m_iWidth, m_iHeight, sizeof(menuText) / sizeof(string), 0.5f);
		m_DrawManager.SettingMenuDraw(m_iWidth/2, 3, m_iHeight*0.7f);
		m_DrawManager.gotoxy(m_iWidth, m_iHeight * 0.7f + 1);
		cin >> select;
		switch (select)
		{
		case 1: //게임 시작
			StartScreen();
			break;
		case 2: //옵션 설정
			SettingScreen();
			break;
		case 3: //게임 종료
			return;
		default:
			break;
		}
	}
}

void Play::StartScreen()
{
	int select;
	const string settingText[] = { "= Game Play =","1.New Game","2.Load Game","3.RePlay", "4.Return", "입력 : " };
	string filename;
	while (1)
	{
		//게임 창에서도 옵션으로 들어올수 있어야하니까 cls는 쓰면 안됨
		m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
		m_DrawManager.DrawMidTextList(settingText, m_iWidth, m_iHeight, sizeof(settingText) / sizeof(string), 0.5f);
		cin >> select;
		switch (select)
		{
		case 1: //새 게임
			PlayerSet();
			Init();
			m_Save.open("LoadGame.txt");//덮어쓰기 모드
			if (!m_Save.is_open())//파일이 만약 열리지 않는다면
			{
				cout << "파일이 열리지 않음" << endl;
				_getch();
				break;
			}
			m_Save << m_Player[0]->GetUndo() << " " << m_iStone << " " << m_Player[0]->GetName() << " " << m_Player[1]->GetName(); //플레이어 정보 저장(이름과 무르기 횟수)
			Playing();
			return;
		case 2: //이어 하기
			if (!FileCheck())
			{
				break;
			}

			m_Read.open("LoadGame.txt"); 
			if (m_Read.is_open() == NULL)
			{
				system("cls");
				m_DrawManager.DrawMidText("파일이 존재하지 않습니다.", m_iWidth, m_iHeight * 0.5f);
				_getch();
				break;
			}
			Init();
			LoadGame();
			m_Save.open("LoadGame.txt", ios::app);//파일 입출력 추가모드
			if (!m_Save.is_open())//파일이 만약 열리지 않는다면
			{
				cout << "파일이 열리지 않음" << endl;
				_getch();
				break;
			}
			Playing();
			return;
		case 3: //리플레이
			m_Read.open("RePlay.txt");
			if (m_Read.is_open() == NULL)
			{
				system("cls");
				m_DrawManager.DrawMidText("파일이 존재하지 않습니다.", m_iWidth, m_iHeight * 0.5f);
				_getch();
				break;
			}
			Init();
			RePlay();
			return;
		case 4: //돌아가기
			return;
		default: //나머지 키입력은 무시
			break;
		}
	}
}

bool Play::FileCheck()
{
	m_Read.open("LoadGame.txt");

	if (m_Read.is_open() == NULL)
	{
		system("cls");
		m_DrawManager.DrawMidText("파일이 존재하지 않습니다.", m_iWidth, m_iHeight * 0.5f);
		_getch();
		return false;
	}
	int check;
	m_Read >> check;
	if (check == 100)
	{
		system("cls");
		m_DrawManager.DrawMidText("파일이 존재하지 않습니다.", m_iWidth, m_iHeight * 0.5f);
		m_Read.close();
		_getch();
		return false;
	}
	m_Read.close();
}
//--옵션 관련 함수--//
//구현할 기능
//1. 맵 사이즈 설정 - 가로는 20~90 세로는 20~45
//2. 커서 커스텀
//3. 스톤 커스텀
//4. 무르기 갯수 설정 - 무르기 횟수 설정(최대 10회) / 무르기 끄기
//5. 뒤로가기

//옵션 화면
void Play::SettingScreen()
{
	int select;
	const string settingText[] = { "= Option =","1.Map Size Set","2.Cursor Custom","3.Stone Custom","4.Undo Count Set","5.Return","입력 : " };
	while (1)
	{
		//게임 창에서도 옵션으로 들어올수 있어야하니까 cls는 쓰면 안됨
		m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
		m_DrawManager.DrawMidTextList(settingText, m_iWidth, m_iHeight, sizeof(settingText) / sizeof(string),0.5f);
		cin >> select;
		switch (select)
		{
		case 1: //맵 사이즈 설정
			if (m_bPlayCheck) //만약 플레이어 체크가 되어있다면
			{
				Warning(); //변경 불가능 
				break;
			}

			MapSizeChange();//맵 사이즈 변경
			break;
		case 2: //커서 모양 설정
			ShapeChange(&m_iCursor);
			break;
		case 3: //돌 모양 설정
			ShapeChange(&m_iStone);
			if (m_bPlayCheck)
			{
				m_Player[0]->ChangeStoneShape(m_strStoneShape[m_iStone][0]);
				m_Player[1]->ChangeStoneShape(m_strStoneShape[m_iStone][1]);
			}
			break;
		case 4: //무르기 횟수 설정
			if (m_bPlayCheck) //만약 플레이어 체크가 되어있다면
			{
				Warning(); //변경 불가능 
				break;
			}
			UndoCount();
			break;
		case 5: //돌아가기
			return;
		default: //나머지 키입력은 무시
			break;
		}
	}
}

//1.맵사이즈 변경 
void Play::MapSizeChange()
{
	int width;
	int height;
	while (true)
	{
		m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
		//m_DrawManager.gotoxy(m_iWidth, m_iHeight / 2);
		m_DrawManager.TextDraw("Width :", m_iWidth - 5, m_iHeight * 0.4f);
		cin >> width;
		m_DrawManager.TextDraw("Height :", m_iWidth - 5, m_iHeight * 0.6f);
		cin >> height;

		if ((width >=20 && width <=90) && (height >= 20 && height <= 45)) // 조건에 맞으면 탈출
		{
			m_iWidth = width;
			m_iHeight = height;
			break;
		}

		m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
		m_DrawManager.DrawMidText("변경 불가능", m_iWidth, m_iHeight * 0.5f);
		m_DrawManager.DrawMidText("(가로 : 20 ~ 90 , 세로 : 20 ~ 45)", m_iWidth, m_iHeight * 0.5f + 1);
		_getch();
	}
	//바꾼 사이즈 대로 콘솔창 크기변경과 맵 다시 드로우 해야함
}

//2,3. 커서/돌 모양 변경
void Play::ShapeChange(int *shapeTarget) 
{
	int select;
	string ShapeText[] = {"= Set Cusor =", "1.","2.","3.","4.","5.Return", "입력 : "};
	if (shapeTarget == &m_iCursor)
	{
		for (int i = 1; i < 5; i++)
		{
			ShapeText[i] += m_strCursorShape[i - 1][0] + "," + m_strCursorShape[i - 1][1];
		}
	}
	else
	{
		for (int i = 1; i < 5; i++)
		{
			ShapeText[i] += m_strStoneShape[i - 1][0] + "," + m_strStoneShape[i - 1][1];
		}
	}

	while (1)
	{
		system("cls");
		m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
		m_DrawManager.DrawMidTextList(ShapeText, m_iWidth, m_iHeight, sizeof(ShapeText) / sizeof(string),0.5f);
		cin >> select;
		switch (select)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			//여기에 커서모양
			*shapeTarget = select - 1;
			system("pause");
			return;
		case 5:
			return;
		default: //잘못된 값들어오면 다시
			break;
		}
	}
}

//4.무르기 옵션 변경
void Play::UndoCount()
{
	int select;
	string undoText[] = { "= Set Undo =","1.Set Undo Count","2.Undo Off","3.Return","입력 : "  };
	while (1)
	{
		system("cls");
		m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
		m_DrawManager.DrawMidTextList(undoText, m_iWidth, m_iHeight, sizeof(undoText) / sizeof(string),0.3f);
		cin >> select;
		switch (select)
		{
		case 1: //무르기 횟수변경
			while (true)
			{
				m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
				m_DrawManager.DrawMidText("무르기 횟수 입력(최대 10회) : ", m_iWidth, m_iHeight * 0.5f);
				cin >> m_iUndoCount;
				if (m_iUndoCount <= 10 && m_iUndoCount >= 0) 
				{
					break;
				}
				m_DrawManager.DrawMidText("범위가 맞지 않습니다 ( 0 ~ 10)", m_iWidth, m_iHeight * 0.5f + 1);
				_getch(); //아무키나 들어오면 넘어감
			}
			break;
		case 2: //무르기끄기
			m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
			m_DrawManager.DrawMidText("무르기 OFF", m_iWidth, m_iHeight / 2);
			m_iUndoCount = 0;
			_getch();
			break;
		case 3: //돌아가기
			return;
		default: //잘못된 값들어오면 다시
			break;
		}
	}
}

//게임 플레이중일때 옵션 변경 불가능(경고)
void Play::Warning()
{
	string warningText[] = { "접근 불가능", "(Game Play중)"};
	system("cls");
	m_DrawManager.DrawMidTextList(warningText, m_iWidth, m_iHeight, sizeof(warningText) / sizeof(string),0.5f);
	m_DrawManager.gotoxy(STARTPOS, m_iHeight);
	system("pause");
}

//--실제 플레이--//

//초기화 
void Play::Init()
{
	//게임 중 체크
	m_bPlayCheck = true;
	//턴 수 초기화
	m_iTurn = 0;
	m_DrawManager.BoxDraw(m_iWidth, m_iHeight);//게임판 출력
}


//플레이어 생성
//*주의 게임 시작할때 플레이어를 생성해야하는데 이때 플레이어의 돌을0, 0 고정하면안됨
//그리고 플레이어 돌 선택은 게임 시작전에도 선택할수있어야 함
void Play::PlayerSet()
{
	string name;
	system("cls");
	m_DrawManager.SettingDraw(m_iWidth, m_iHeight);

	//플레이어 1 입력
	m_DrawManager.TextDraw("P1 이름", m_iWidth - 5, m_iHeight * 0.3f);
	m_DrawManager.TextDraw("입력: ", m_iWidth - 5, m_iHeight * 0.3f+1);
	cin >> name;
	m_Player[0] = new Player(name, m_iWidth, m_iHeight*0.5f, m_strStoneShape[m_iStone][0], m_iUndoCount);

	//플레이어 2 입력
	m_DrawManager.TextDraw("P2 이름", m_iWidth - 5, m_iHeight * 0.6f);
	m_DrawManager.TextDraw("입력: ", m_iWidth - 5, m_iHeight * 0.6f + 1);
	cin >> name;
	m_Player[1] = new Player(name, m_iWidth, m_iHeight*0.5f, m_strStoneShape[m_iStone][1], m_iUndoCount);

}

//플레이어 이동
void Play::Movement(int *pos, int value, int x, int y) //바뀔 좌표와 현재좌표
{
	m_DrawManager.PlayingBoxEmpty(m_iWidth * 2, m_iHeight, x, y);

	if (m_Player[0]->StoneCheck(x, y))
	{
		m_DrawManager.TextDraw(m_Player[0]->GetStoneShape(), x, y);
	}
	if (m_Player[1]->StoneCheck(x, y))
	{
		m_DrawManager.TextDraw(m_Player[1]->GetStoneShape(), x, y);
	}

	*pos += value;
}

//리플레이 오목 제작조건
//1. 게임이 끝나고 리플레이를 보여준다.
//2. 게임도중 ESC를 눌러서 나갔을 경우 이어하기 지원
//3. 가장 최근에 한 게임 리플레이 가능
//게임 시작 누르면 새로하기/ 이어하기/ 리플레이 

//리플레이
void Play::RePlay()
{
	string PlayerName;
	int nudo;
	int stone;
	int posX;
	int posY;

	m_Read >> nudo;
	m_Read >> stone;

	m_Read >> PlayerName;
	m_Player[0] = new Player(PlayerName, m_iWidth, m_iHeight * 0.5f, m_strStoneShape[stone][0], nudo);
	m_Read >> PlayerName;
	m_Player[1] = new Player(PlayerName, m_iWidth, m_iHeight * 0.5f, m_strStoneShape[stone][1], nudo);

	m_DrawManager.BoxDraw(m_iWidth, m_iHeight);//게임판 출력

	while (!m_Read.eof())
	{
		m_Read >> posX;
		m_Read >> posY;
		if (posX == UNDO && posY == UNDO)
		{
			m_Player[m_iTurn % 2]->Undocount();//현재 플레이어 무르기 횟수를 1 차감한뒤
			m_iTurn--;//턴을 -1
			m_Player[m_iTurn % 2]->Undo(m_iWidth * 2, m_iHeight); //무르기 실행
			ControlGuide(m_iTurn % 2);
			Sleep(1000);
		}
		else
		{
			if (m_Read.eof())
			{
				break;
			}
			ControlGuide(m_iTurn % 2);//가이드 출력
			m_Player[m_iTurn % 2]->StoneDrop(posX, posY); //돌 놓기
			m_iTurn++;
			Sleep(1000);
		}
	}
	m_DrawManager.DrawMidText(m_Player[m_iTurn % 2]->GetName() + "팀 승리!!", m_iWidth, m_iHeight * 0.5f);//플레이어 네임 화면중앙에 출력
	m_bPlayCheck = false; //게임중 체크 해제
	//할당했던 플레이어 할당해제
	delete m_Player[0];
	delete m_Player[1];
	m_Read.close();
	_getch();//아무키나 들어오면
}

//이어하기
void Play::LoadGame()
{
	string PlayerName;
	int nudo;
	int stone;
	int posX;
	int posY;

	m_Read >> nudo;
	m_Read >> stone;

	m_Read >> PlayerName;
	m_Player[0] = new Player(PlayerName, m_iWidth, m_iHeight * 0.5f, m_strStoneShape[m_iStone][0], nudo);
	m_Read >> PlayerName;
	m_Player[1] = new Player(PlayerName, m_iWidth, m_iHeight * 0.5f, m_strStoneShape[m_iStone][1], nudo);

	m_DrawManager.BoxDraw(m_iWidth, m_iHeight);//게임판 출력

	while (!m_Read.eof())
	{
		m_Read >> posX;
		m_Read >> posY;
		if (posX == UNDO && posY == UNDO)
		{
			m_Player[m_iTurn % 2]->Undocount();//현재 플레이어 무르기 횟수를 1 차감한뒤
			m_iTurn--;//턴을 -1
			m_Player[m_iTurn % 2]->Undo(m_iWidth * 2, m_iHeight); //무르기 실행
			ControlGuide(m_iTurn % 2);
		}
		else
		{
			ControlGuide(m_iTurn % 2);//가이드 출력
			m_Player[m_iTurn % 2]->PosUpdate(posX, posY); //플레이어 마지막 좌표 갱신
			m_Player[m_iTurn % 2]->StoneDrop(posX, posY); //돌 놓기
			m_iTurn++;
		}
	}
	m_Read.close();
}

//게임 플레이
void Play::Playing()
{
	//처음 시작지점 중간으로 맞춤
	int x = m_Player[m_iTurn % 2]->GetXPos();
	int y = m_Player[m_iTurn % 2]->GetYPos();
	if (x%2 !=0)
	{
		x++;
	}
	ControlGuide(m_iTurn % 2);//가이드 출력
	m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);	//커서출력
	//자기 차례인지 어떻게 확인? - 턴수/2 해서 나머지가 없으면 1P 있으면 2P
	//턴 표시는 실체 턴수 + 1로 표시
	while (m_bPlayCheck)
	{
		char select = _getch(); //cin 쓰면 X
		switch (select)
		{
		//방향 이동
		case DIRECTION_LEFT:
			if (x - 2 >= 0)
			{
				Movement(&x, -2, x, y);
				m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);
			}
			break;
		case DIRECTION_RIGHT:
			if (x + 2 < m_iWidth * 2)
			{
				Movement(&x, 2, x, y);
				m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);
			}
			break;
		case DIRECTION_UP:
			if (y - 1 >= 0)
			{
				Movement(&y, -1, x, y);
				m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);
			}
			break;
		case DIRECTION_DOWN:
			if (y + 1 < m_iHeight) 
			{
				Movement(&y, 1, x, y);
				m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);
			}
			break;
			//돌 놓기
		case ENTER:
			//무사히 돌을 놨을 경우
			if (m_Player[0]->StoneCheck(x, y)==false && m_Player[1]->StoneCheck(x, y) == false)
			{
				m_Player[m_iTurn % 2]->PosUpdate(x, y); //플레이어 마지막 좌표 갱신
				m_Player[m_iTurn % 2]->StoneDrop(x, y); //돌 놓기
				m_Save << endl << x << " " << y;
				if (m_Player[m_iTurn % 2]->WinCheck())//만약 플레이어가 승리했다면
				{
					FileCopy();
					m_DrawManager.DrawMidText(m_Player[m_iTurn % 2]->GetName() + "팀 승리!!", m_iWidth, m_iHeight * 0.5f);//플레이어 네임 화면중앙에 출력
					m_bPlayCheck = false; //게임중 체크 해제
					_getch();//아무키나 들어오면 
					break;
				}

				m_iTurn += 1; //턴증가
				x = m_Player[m_iTurn % 2]->GetXPos(); //다음 턴 플레이어의 X좌표 받아옴
				y = m_Player[m_iTurn % 2]->GetYPos(); //다음 턴 플레이어의 Y좌표 받아옴
				ControlGuide(m_iTurn % 2); //가이드 출력
				m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);//다음턴 플레이어의 위치에 커서 출력
			}
			//아닐경우 커서 재출력
			break;
			//무르기
		case OPTION_UNDO:
			if (m_Player[m_iTurn % 2]->GetUndo() > 0 && m_iTurn > 0) //무르기가 가능하다면 (첫번째 턴인경우 무르기 X)
			{
				m_Save << endl << UNDO << " " << UNDO;
				m_Player[m_iTurn % 2]->Undocount();//현재 플레이어 무르기 횟수를 1 차감한뒤
				m_iTurn--;//턴을 -1
				m_Player[m_iTurn % 2]->Undo(m_iWidth * 2, m_iHeight); //무르기 실행
				m_DrawManager.PlayingBoxEmpty(m_iWidth * 2, m_iHeight, x, y);
				ControlGuide(m_iTurn % 2);
				x = m_Player[m_iTurn % 2]->GetXPos(); //플레이어의 X좌표 받아옴
				y = m_Player[m_iTurn % 2]->GetYPos(); //플레이어의 Y좌표 받아옴
				m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);//현재턴 커서 재출력
			}
			break;
			//옵션
		case OPTION_KEY: 
			SettingScreen();
			AllPrint(x, y);
			break;
			//종료
		case ESC: 
			m_Save.close(); //파일 저장 닫음
			m_bPlayCheck = false; //게임중 체크 해제
			break;
		default:
			break;
		}
	}

	//할당했던 플레이어 할당해제
	delete m_Player[0];
	delete m_Player[1];
}

void Play::FileCopy()
{
	m_Save.close(); //이겼으니 파일 저장 닫음
	ifstream load;
	string saveLine;
	load.open("LoadGame.txt");
	m_Save.open("RePlay.txt");//덮어쓰기 모드
	while (!load.eof())
	{
		getline(load, saveLine);
		m_Save << saveLine << " ";
	}
	m_Save.close(); //파일 저장 닫음
	load.close(); //파일 닫음
	m_Save.open("LoadGame.txt");//덮어쓰기 모드로 열었다가(모든 데이터 날아감)
	m_Save << "100"; //비었다는 뜻으로 100 넣고
	m_Save.close();//다시 닫음
}
//재프린트
void Play::AllPrint(int x, int y)
{
	system("cls");
	m_DrawManager.BoxDraw(m_iWidth, m_iHeight); //맵 그리고
	m_Player[0]->StoneDrow();//돌 출력
	m_Player[1]->StoneDrow();
	ControlGuide(m_iTurn % 2);//가이드출력
	m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);//현재턴 커서 재출력
}

//조작가이드
void Play::ControlGuide(int turn)
{
	const string ControlGuideText[] = {"====조작키====","이동 : W,A,S,D 돌놓기 : ENTER","무르기 : N 옵션 : P 종료 : ESC","PlayerName :        무르기 : ", "Thrn: " };
	for (int i = 0; i < 5; i++)
	{
		m_DrawManager.DrawMidText(ControlGuideText[i], m_iWidth, m_iHeight + i);
	}
	cout << m_iTurn + 1 << "   " << endl;
	m_DrawManager.gotoxy(m_iWidth-2, m_iHeight+3);
	cout << m_Player[turn]->GetName();
	m_DrawManager.gotoxy(m_iWidth+14, m_iHeight + 3);
	cout << m_Player[turn]->GetUndo();
}