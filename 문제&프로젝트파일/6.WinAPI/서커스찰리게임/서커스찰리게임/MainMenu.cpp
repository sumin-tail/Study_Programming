#include "MainMenu.h"

MainMenu::MainMenu() : m_StarCount(0), m_Animationtimer(0) , m_PointSelect(0)
{
	m_Title = new BitMap[4];
	m_Menu = new BitMap[5];
}

MainMenu::~MainMenu()
{
	delete[] m_Title;
	delete[] m_Menu;
}

void MainMenu::ImageInit(HDC hdc, const char* name, int count, BitMap* arr)
{
	char buf[256]; //char형 배열생성
	for (int i = 0; i < count; i++)
	{
		sprintf_s(buf, "Resource//%s_%d.bmp", name, i + 1); //이미지 위치 버퍼에 저장
		arr[i].Init(hdc, buf);//배열 초기화
	}
}

void MainMenu::Init(HDC hdc)
{
	char buf[256]; //char형 배열생성
	sprintf_s(buf, "Resource//black.bmp"); //이미지 위치 버퍼에 저장
	m_Black.Init(hdc, buf);//검은색 초기화
	sprintf_s(buf, "Resource//point.bmp");
	m_Point.Init(hdc, buf);//화살표 초기화
	ImageInit(hdc, "title", 4, m_Title); //타이틀 초기화
	ImageInit(hdc, "menu", 5, m_Menu); // 메뉴 초기화
}


void MainMenu::PointDraw(HDC hdc, int x, int y, int interval)//마우스 포인터 드로우
{

	m_Point.Draw(hdc, x, y + interval* m_PointSelect);
}

void MainMenu::StarDraw(HDC hdc, int posX, int titleWidth, int titleHeight) //타이틀 가로 사이즈랑 세로 사이즈 보냄 
{
	int starW = m_Title[1].GetSize().cx;
	int starH = m_Title[1].GetSize().cy;

	for (int i = 0; i < titleWidth / starW; i++) //가로별 출력
	{
		m_Title[(i + m_StarCount) % 3 + 1].Draw(hdc, posX + starW * i, titleHeight - starH); //위쪽줄 - 왼쪽에서 오른쪽으로
		m_Title[(i + m_StarCount) % 3 + 1].Draw(hdc, posX + starW * i, titleHeight * 2);
	}
	for (int i = 0; i <= titleHeight / starH; i++) //세로별 출력
	{
		m_Title[(i + m_StarCount) % 3 + 1].Draw(hdc, posX - starW, titleHeight + starH * i);
		m_Title[(i + m_StarCount) % 3 + 1].Draw(hdc, posX + titleWidth, titleHeight + starH * i);
	}
}



void MainMenu::Update(float elapsed)
{
	m_Animationtimer += elapsed;
	if (0.1f <= m_Animationtimer) //0.1 초마다 업데이트 
	{
		m_StarCount++; //별이 돌아가게 하기위한 스타카운트 
		m_Animationtimer = 0;
		//별은 m_Title의 1 2 3에 있음
		if (m_StarCount > 2)
		{
			m_StarCount = 0;
		}

		if (GetAsyncKeyState(VK_UP) && m_PointSelect - 1 >= 0)
		{
			m_PointSelect--;
		}

		if (GetAsyncKeyState(VK_DOWN) && m_PointSelect + 1 <= 3)
		{
			m_PointSelect++;
		}
	}

}

void MainMenu::Draw(HDC hdc, int windowWidth, int windowHeight)
{
	m_Black.Draw(hdc, 0, 0, windowWidth, windowHeight); //뒷배경 까맣게 드로우
	m_Title[0].Draw(hdc, windowWidth * 0.5f - m_Title[0].GetSize().cx * 0.5f, m_Title[0].GetSize().cy); //서커스 찰리 단어 출력
	StarDraw(hdc, windowWidth * 0.5f - m_Title[0].GetSize().cx * 0.5f, m_Title[0].GetSize().cx, m_Title[0].GetSize().cy);//그걸 감싸는 별 출력
	m_Menu[0].Draw(hdc, windowWidth * 0.5f - m_Menu[0].GetSize().cx * 0.5f, windowHeight * 0.3f);//플레이어 셀렉트

	int x = windowWidth * 0.5f - m_Menu[1].GetSize().cx * 0.5f;
	int y = windowHeight * 0.5f;

	for (int i = 1; i < 5; i++)
	{
		m_Menu[i].Draw(hdc, x, y);//플레이어 선택
		y += m_Menu[i].GetSize().cy * 1.5f; //플레이어 사이의 간격은 세로사이즈의 1.5배씩
	}

	//m_Point.Draw(hdc, x - m_Point.GetSize().cx, windowHeight * 0.5f, m_Point.GetSize().cx, m_Point.GetSize().cy);//선택 포인터 출력 > 이제 이걸 움직이게 만들어야 함
	PointDraw(hdc, x - m_Point.GetSize().cx, windowHeight * 0.5f, m_Menu[1].GetSize().cy * 1.5f);
}
