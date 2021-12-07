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
	
	while (true)
	{

	}

	for (int i = 0; i <= storySize - 10; i++)
	{
		for (int count = 0; count < 10; count++)
		{
			m_DrawInterface.DrawMidText("                                       ",WIDTH, HEIGHT * 0.3f + count); //이전 문장 지우는거
			m_DrawInterface.DrawMidText(str[i+count], WIDTH, HEIGHT * 0.3f + count);
			if (i == 0)
			{
				Sleep(500);//임시슬립
			}
		}
		Sleep(500);//임시슬립
	}
	_getch();

	if (_kbhit())//키 입력이 들어오고
	{
		if (_getch() == 's') //그게 s 라면 
		{
			return;//돌아가기-스킵
		}
	}
	ORIGINAL
}
