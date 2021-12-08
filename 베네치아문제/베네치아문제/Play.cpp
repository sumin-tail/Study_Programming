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
			NameSetting();
			GamePlay();
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

void Play::DrawAll()
{
	system("cls");
	m_DrawInterface.BoxDraw(WIDTH, HEIGHT);//ū�ڽ�
	m_DrawInterface.BoxDrawPos(WIDTH * 0.3f, 5, HEIGHT * 0.7f);//���� �ڽ�
	PlayerDraw();
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
	
	int startClock = clock(); // ���� �ð� ����

	int startNum = 0;//���� �� ����
	int line = 1;
	while (startNum < storySize - 10) //������ �ٱ��� ������� ����
	{
		if (_kbhit())//Ű �Է��� ������
		{
			if (_getch() == 's') //�װ� s ��� 
			{
				return;//���ư���-��ŵ
			}
		}

		if (clock() - startClock >= SPEED*0.5f)//���� ���� ���� �ð��� �Ǿ��ٸ�
		{
			for (int i = startNum; i < (line + startNum); i++)
			{
				int y = (i - startNum);
				m_DrawInterface.DrawMidText("                                       ", WIDTH, HEIGHT * 0.3f + y); //���� ���� ����°�
				m_DrawInterface.DrawMidText(str[i], WIDTH, HEIGHT * 0.3f + y);
			}
			
			if (10 > line) line++;
			else startNum++;

			//if (startNum == 0) //0���� 9��° �ٱ����� ��ĭ�� ����������
			//{
			//	m_DrawInterface.DrawMidText(str[startNum + count], WIDTH, HEIGHT * 0.3f + count);
			//	count++;
			//}
			//else
			//{
			//	for (count = 0; count < 10; count++)
			//	{
			//		m_DrawInterface.DrawMidText("                                       ", WIDTH, HEIGHT * 0.3f + count); //���� ���� ����°�
			//		m_DrawInterface.DrawMidText(str[startNum + count], WIDTH, HEIGHT * 0.3f + count);
			//	}
			//}
			//
			//if (count == 10)//10���� ���� ����ߴٸ�
			//{
			//	startNum++;//���� �� ��ȣ�� +1
			//}
			startClock = clock(); //�ð�����
		}

	}
	ORIGINAL
}

void Play::NameSetting()
{
	DrawAll();
	BLUE
	m_DrawInterface.DrawMidText("�̸� �Է�", WIDTH, HEIGHT * 0.7f - 3);
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
		case '\b': //�� �����̽�
			if (text.length() > 0)
			{
				text = text.substr(0, text.length() - 1);
				m_DrawInterface.DrawMidText("              ", WIDTH, HEIGHT * 0.7f - 2); //�ʰ� ���κ� �����
				m_DrawInterface.DrawMidText("              ", WIDTH, HEIGHT * 0.7f + 2); //�̸��κ� �����
			}
			break;
		case '\r': //����
			if (text.length() > 0)
			{
				return true;
			}
			break;
		default:
			if (text.length() >= textsize)
			{
				m_DrawInterface.DrawMidText(to_string(textsize) + "���� �ʰ�!!", WIDTH, HEIGHT * 0.7f - 2);
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
	StagePrint(stage);//�������� ���
	DrawAll();

	m_Playtime = clock();
	while (m_life > 0)//�÷��̾� �������� 0���� Ŭ�� ���ư�
	{
		Update();
	}

}

void Play::StagePrint(int stage)
{
	int time = clock();
	m_DrawInterface.DrawMidText("�� " + to_string(stage) + " Stage ��", WIDTH, HEIGHT * 0.3f);
	while (clock() - time < SPEED);
	m_DrawInterface.BoxErase(WIDTH, HEIGHT);//�ڽ� �����
}

void Play::Update()
{
	//�ܾ� ��ĭ�� ������ = �ӵ��� ���ǵ� - ���� ����
	//�÷��̾ �ܾ ����ٸ� ���� �ø���

}
