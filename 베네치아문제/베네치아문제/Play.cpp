#include "Play.h"

Play::Play()
{
	m_name = "? ? ?";
	m_score = 0;
	m_life = 10;
	srand(time(NULL)); //시드 초기화
}

Play::~Play()
{

}

void Play::MainMenu()
{
	while (true)
	{
		m_DrawInterface.BoxDraw(WIDTH, HEIGHT);
		BLUE
		m_DrawInterface.DrawMidText("☆ ★ 베 네 치 아 ★ ☆", WIDTH, HEIGHT * 0.2f);
		m_DrawInterface.DrawMidText("1.Game Start", WIDTH, HEIGHT * 0.4f);
		m_DrawInterface.DrawMidText("2.Rank", WIDTH, HEIGHT * 0.4f + 3);
		m_DrawInterface.DrawMidText("3.Exit", WIDTH, HEIGHT * 0.4f + 6);
		ORIGINAL
		PlayerDraw();
		int select = m_DrawInterface.MenuSelectCursor(3, 3, 25, HEIGHT * 0.4f);
		switch (select)
		{
		case 1: //게임시작
			Intro();
			NameSetting();
			GamePlay();
			break;
		case 2: //랭킹
			break;
		case 3:
			return;
		}
	}
}

void Play::PlayerDraw()
{
	RED
	m_DrawInterface.TextDraw(" Life : ", 0, HEIGHT + 2);
	for (int i = 0; i < m_life; i++)
	{
		cout << "♥";
	}
	m_DrawInterface.DrawMidText(" Score : " + to_string(m_score), WIDTH, HEIGHT + 2);
	m_DrawInterface.TextDraw(" Name : " + m_name, WIDTH * 2 - 20, HEIGHT + 2);
	ORIGINAL
}

void Play::DrawAll()
{
	system("cls");
	m_DrawInterface.BoxDraw(WIDTH, HEIGHT);//큰박스
	m_DrawInterface.BoxDrawPos(WIDTH * 0.3f, 5, HEIGHT * 0.7f);//작은 박스
	PlayerDraw();
}

void Play::Intro()
{
	system("cls");
	ifstream load;
	load.open("베네치아_스토리.txt");
	if (!load.is_open()) //파일 열리는지 확인
	{
		m_DrawInterface.DrawMidText("스토리 파일이 존재하지 않습니다!", WIDTH, HEIGHT * 0.5f);
		_getch();
		return;
	}
	//드로우
	m_DrawInterface.BoxDraw(WIDTH, HEIGHT);
	m_DrawInterface.BoxDrawPos(WIDTH * 0.3f, 5, HEIGHT * 0.7f);
	PlayerDraw();

	BLUE
	m_DrawInterface.DrawMidText("Skip : s", WIDTH, HEIGHT * 0.7f + 2);
	//스토리 출력하는 곳
	int storySize;//배경스토리 줄이 몇줄인지
	load >> storySize;
	string* str = new string[storySize]; //인트로 끝나고 할당 풀어줘야함
	for (int i = 0; i < storySize; i++)
	{
		getline(load, str[i]);
	}
	
	int startClock = clock(); // 시작 시간 저장

	int startNum = 0;//시작 줄 정보
	int line = 1;
	while (startNum < storySize - 10) //마지막 줄까지 갔을경우 끝남
	{
		if (_kbhit())//키 입력이 들어오고
		{
			if (_getch() == 's') //그게 s 라면 
			{
				return;//돌아가기-스킵
			}
		}

		if (clock() - startClock >= SPEED*0.5f)//만약 글이 나올 시간이 되었다면
		{
			for (int i = startNum; i < (line + startNum); i++)
			{
				int y = (i - startNum);
				m_DrawInterface.DrawMidText("                                       ", WIDTH, HEIGHT * 0.3f + y); //이전 문장 지우는거
				m_DrawInterface.DrawMidText(str[i], WIDTH, HEIGHT * 0.3f + y);
			}
			
			if (10 > line) line++;
			else startNum++;

			//if (startNum == 0) //0에서 9번째 줄까지는 한칸씩 내려가햐함
			//{
			//	m_DrawInterface.DrawMidText(str[startNum + count], WIDTH, HEIGHT * 0.3f + count);
			//	count++;
			//}
			//else
			//{
			//	for (count = 0; count < 10; count++)
			//	{
			//		m_DrawInterface.DrawMidText("                                       ", WIDTH, HEIGHT * 0.3f + count); //이전 문장 지우는거
			//		m_DrawInterface.DrawMidText(str[startNum + count], WIDTH, HEIGHT * 0.3f + count);
			//	}
			//}
			//
			//if (count == 10)//10개의 줄을 출력했다면
			//{
			//	startNum++;//시작 줄 번호에 +1
			//}
			startClock = clock(); //시간갱신
		}

	}
	ORIGINAL
}

void Play::NameSetting()
{
	DrawAll();
	BLUE
	m_DrawInterface.DrawMidText("이름 입력", WIDTH, HEIGHT * 0.7f - 3);
	m_name = "";
	while (!Typing(10, m_name));
	ORIGINAL
}

bool Play::Typing(int textsize, string& text)
{
	if (_kbhit())
	{
		char c = _getch();
		switch (c)
		{
		case '\b': //백 스페이스
			if (text.length() > 0)
			{
				text = text.substr(0, text.length() - 1);
				m_DrawInterface.DrawMidText("              ", WIDTH, HEIGHT * 0.7f - 2); //초과 경고부분 지우기
				m_DrawInterface.DrawMidText("              ", WIDTH, HEIGHT * 0.7f + 2); //이름부분 지우기
			}
			break;
		case '\r': //엔터
			if (text.length() > 0)
			{
				return true;
			}
			break;
		default:
			if (text.length() >= textsize)
			{
				m_DrawInterface.DrawMidText(to_string(textsize) + "글자 초과!!", WIDTH, HEIGHT * 0.7f - 2);
			}
			else
			{
				text += c;
			}
			break;
		}
		m_DrawInterface.DrawMidText(text, WIDTH, HEIGHT * 0.7f + 2);
	}
	return false;
}

void Play::GamePlay()
{
	int stage = 1;
	m_DrawInterface.BoxDraw(WIDTH, HEIGHT);
	BLUE
	StagePrint(stage);//스테이지 출력
	DrawAll();

	m_Playtime = clock();
	while (m_life > 0)//플레이어 라이프가 0보다 클때 돌아감
	{
		Update();
	}

}

void Play::StagePrint(int stage)
{
	int time = clock();
	m_DrawInterface.DrawMidText("★ " + to_string(stage) + " Stage ★", WIDTH, HEIGHT * 0.3f);
	while (clock() - time < SPEED);
	m_DrawInterface.BoxErase(WIDTH, HEIGHT);//박스 지우기
}

void Play::Update()
{
	//단어 한칸씩 내리기 = 속도는 스피드 - 현재 점수
	//플레이어가 단어를 맞췄다면 점수 올리기

}
