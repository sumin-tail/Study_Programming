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
	char buf[256]; //char�� �迭����
	for (int i = 0; i < count; i++)
	{
		sprintf_s(buf, "Resource//%s_%d.bmp", name, i + 1); //�̹��� ��ġ ���ۿ� ����
		arr[i].Init(hdc, buf);//�迭 �ʱ�ȭ
	}
}

void MainMenu::Init(HDC hdc)
{
	char buf[256]; //char�� �迭����
	sprintf_s(buf, "Resource//black.bmp"); //�̹��� ��ġ ���ۿ� ����
	m_Black.Init(hdc, buf);//������ �ʱ�ȭ
	sprintf_s(buf, "Resource//point.bmp");
	m_Point.Init(hdc, buf);//ȭ��ǥ �ʱ�ȭ
	ImageInit(hdc, "title", 4, m_Title); //Ÿ��Ʋ �ʱ�ȭ
	ImageInit(hdc, "menu", 5, m_Menu); // �޴� �ʱ�ȭ
}


void MainMenu::PointDraw(HDC hdc, int x, int y, int interval)//���콺 ������ ��ο�
{

	m_Point.Draw(hdc, x, y + interval* m_PointSelect);
}

void MainMenu::StarDraw(HDC hdc, int posX, int titleWidth, int titleHeight) //Ÿ��Ʋ ���� ������� ���� ������ ���� 
{
	int starW = m_Title[1].GetSize().cx;
	int starH = m_Title[1].GetSize().cy;

	for (int i = 0; i < titleWidth / starW; i++) //���κ� ���
	{
		m_Title[(i + m_StarCount) % 3 + 1].Draw(hdc, posX + starW * i, titleHeight - starH); //������ - ���ʿ��� ����������
		m_Title[(i + m_StarCount) % 3 + 1].Draw(hdc, posX + starW * i, titleHeight * 2);
	}
	for (int i = 0; i <= titleHeight / starH; i++) //���κ� ���
	{
		m_Title[(i + m_StarCount) % 3 + 1].Draw(hdc, posX - starW, titleHeight + starH * i);
		m_Title[(i + m_StarCount) % 3 + 1].Draw(hdc, posX + titleWidth, titleHeight + starH * i);
	}
}



void MainMenu::Update(float elapsed)
{
	m_Animationtimer += elapsed;
	if (0.1f <= m_Animationtimer) //0.1 �ʸ��� ������Ʈ 
	{
		m_StarCount++; //���� ���ư��� �ϱ����� ��Ÿī��Ʈ 
		m_Animationtimer = 0;
		//���� m_Title�� 1 2 3�� ����
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
	m_Black.Draw(hdc, 0, 0, windowWidth, windowHeight); //�޹�� ��İ� ��ο�
	m_Title[0].Draw(hdc, windowWidth * 0.5f - m_Title[0].GetSize().cx * 0.5f, m_Title[0].GetSize().cy); //��Ŀ�� ���� �ܾ� ���
	StarDraw(hdc, windowWidth * 0.5f - m_Title[0].GetSize().cx * 0.5f, m_Title[0].GetSize().cx, m_Title[0].GetSize().cy);//�װ� ���δ� �� ���
	m_Menu[0].Draw(hdc, windowWidth * 0.5f - m_Menu[0].GetSize().cx * 0.5f, windowHeight * 0.3f);//�÷��̾� ����Ʈ

	int x = windowWidth * 0.5f - m_Menu[1].GetSize().cx * 0.5f;
	int y = windowHeight * 0.5f;

	for (int i = 1; i < 5; i++)
	{
		m_Menu[i].Draw(hdc, x, y);//�÷��̾� ����
		y += m_Menu[i].GetSize().cy * 1.5f; //�÷��̾� ������ ������ ���λ������� 1.5�辿
	}

	//m_Point.Draw(hdc, x - m_Point.GetSize().cx, windowHeight * 0.5f, m_Point.GetSize().cx, m_Point.GetSize().cy);//���� ������ ��� > ���� �̰� �����̰� ������ ��
	PointDraw(hdc, x - m_Point.GetSize().cx, windowHeight * 0.5f, m_Menu[1].GetSize().cy * 1.5f);
}
