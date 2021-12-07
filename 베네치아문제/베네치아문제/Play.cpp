#include "Play.h"

Play::Play()
{
	m_name = "? ? ?";
	m_score = 0;
	m_life = 10;
	srand(time(NULL)); //�õ� �ʱ�ȭ
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
		m_DrawInterface.DrawMidText("�� �� �� �� ġ �� �� ��", WIDTH, HEIGHT * 0.2f);
		m_DrawInterface.DrawMidText("1.Game Start", WIDTH, HEIGHT * 0.4f);
		m_DrawInterface.DrawMidText("2.Rank", WIDTH, HEIGHT * 0.4f + 3);
		m_DrawInterface.DrawMidText("3.Exit", WIDTH, HEIGHT * 0.4f + 6);
		ORIGINAL
		PlayerDraw();
		int select = m_DrawInterface.MenuSelectCursor(3, 3, 25, HEIGHT * 0.4f);
		switch (select)
		{
		case 1: //���ӽ���
			Intro();
			break;
		case 2: //��ŷ
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
		cout << "��";
	}
	m_DrawInterface.DrawMidText(" Score : " + to_string(m_score), WIDTH, HEIGHT + 2);
	m_DrawInterface.TextDraw(" Name : " + m_name, WIDTH * 2 - 20, HEIGHT + 2);
	ORIGINAL
}

void Play::Intro()
{
	system("cls");
	ifstream load;
	load.open("����ġ��_���丮.txt");
	if (!load.is_open()) //���� �������� Ȯ��
	{
		m_DrawInterface.DrawMidText("���丮 ������ �������� �ʽ��ϴ�!", WIDTH, HEIGHT * 0.5f);
		_getch();
		return;
	}
	//��ο�
	m_DrawInterface.BoxDraw(WIDTH, HEIGHT);
	m_DrawInterface.BoxDrawPos(WIDTH * 0.3f, 5, HEIGHT * 0.7f);
	PlayerDraw();
	BLUE
	m_DrawInterface.DrawMidText("Skip : s", WIDTH, HEIGHT * 0.7f + 2);

	//���丮 ����ϴ� ��
	int storySize;//��潺�丮 ���� ��������
	load >> storySize;
	string* str = new string[storySize]; //��Ʈ�� ������ �Ҵ� Ǯ�������
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
			m_DrawInterface.DrawMidText("                                       ",WIDTH, HEIGHT * 0.3f + count); //���� ���� ����°�
			m_DrawInterface.DrawMidText(str[i+count], WIDTH, HEIGHT * 0.3f + count);
			if (i == 0)
			{
				Sleep(500);//�ӽý���
			}
		}
		Sleep(500);//�ӽý���
	}
	_getch();

	if (_kbhit())//Ű �Է��� ������
	{
		if (_getch() == 's') //�װ� s ��� 
		{
			return;//���ư���-��ŵ
		}
	}
	ORIGINAL
}
