#include "Play.h"

//���� ������� 20 20 ������ ������ ��ǥ ������� 40 20
//�ܼ�â y��+5 �س����� (���۹�)

//������
Play::Play()
{
	m_iWidth = STARTSIZE;//����
	m_iHeight = STARTSIZE;//����

	m_iUndoCount = STARTUNDO; //������ Ƚ��
	m_iCursor = STARTSHAPE; //Ŀ�� �⺻��� ����
	m_iStone = STARTSHAPE; //�÷��̾� �� �⺻��� ����

	m_bPlayCheck = false;
}

//�Ҹ���
Play::~Play()
{

}

//���� �޴� ȭ��
void Play::MenuScreen()
{
	int select;
	const string menuText [] = { "�� �� �� ��","1.���� ����","2.�ɼ� ����", "3.���� ����"};

	while (1)
	{
		system("cls");
		m_DrawManager.BoxDraw(m_iWidth, m_iHeight);
		//�Ʒ� ���ڴ� �� ������ ���� ������ �޶���
		m_DrawManager.DrawMidTextList(menuText, m_iWidth, m_iHeight, sizeof(menuText) / sizeof(string), 0.5f);
		m_DrawManager.SettingMenuDraw(m_iWidth/2, 3, m_iHeight*0.7f);
		m_DrawManager.gotoxy(m_iWidth, m_iHeight * 0.7f + 1);
		cin >> select;
		switch (select)
		{
		case 1: //���� ����
			StartScreen();
			break;
		case 2: //�ɼ� ����
			SettingScreen();
			break;
		case 3: //���� ����
			return;
		default:
			break;
		}
	}
}

void Play::StartScreen()
{
	int select;
	const string settingText[] = { "= Game Play =","1.New Game","2.Load Game","3.RePlay", "4.Return", "�Է� : " };
	string filename;
	while (1)
	{
		//���� â������ �ɼ����� ���ü� �־���ϴϱ� cls�� ���� �ȵ�
		m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
		m_DrawManager.DrawMidTextList(settingText, m_iWidth, m_iHeight, sizeof(settingText) / sizeof(string), 0.5f);
		cin >> select;
		switch (select)
		{
		case 1: //�� ����
			PlayerSet();
			Init();
			m_Save.open("LoadGame.txt");//����� ���
			if (!m_Save.is_open())//������ ���� ������ �ʴ´ٸ�
			{
				cout << "������ ������ ����" << endl;
				_getch();
				break;
			}
			m_Save << m_Player[0]->GetUndo() << " " << m_iStone << " " << m_Player[0]->GetName() << " " << m_Player[1]->GetName(); //�÷��̾� ���� ����(�̸��� ������ Ƚ��)
			Playing();
			return;
		case 2: //�̾� �ϱ�
			if (!FileCheck())
			{
				break;
			}

			m_Read.open("LoadGame.txt"); 
			if (m_Read.is_open() == NULL)
			{
				system("cls");
				m_DrawManager.DrawMidText("������ �������� �ʽ��ϴ�.", m_iWidth, m_iHeight * 0.5f);
				_getch();
				break;
			}
			Init();
			LoadGame();
			m_Save.open("LoadGame.txt", ios::app);//���� ����� �߰����
			if (!m_Save.is_open())//������ ���� ������ �ʴ´ٸ�
			{
				cout << "������ ������ ����" << endl;
				_getch();
				break;
			}
			Playing();
			return;
		case 3: //���÷���
			m_Read.open("RePlay.txt");
			if (m_Read.is_open() == NULL)
			{
				system("cls");
				m_DrawManager.DrawMidText("������ �������� �ʽ��ϴ�.", m_iWidth, m_iHeight * 0.5f);
				_getch();
				break;
			}
			Init();
			RePlay();
			return;
		case 4: //���ư���
			return;
		default: //������ Ű�Է��� ����
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
		m_DrawManager.DrawMidText("������ �������� �ʽ��ϴ�.", m_iWidth, m_iHeight * 0.5f);
		_getch();
		return false;
	}
	int check;
	m_Read >> check;
	if (check == 100)
	{
		system("cls");
		m_DrawManager.DrawMidText("������ �������� �ʽ��ϴ�.", m_iWidth, m_iHeight * 0.5f);
		m_Read.close();
		_getch();
		return false;
	}
	m_Read.close();
}
//--�ɼ� ���� �Լ�--//
//������ ���
//1. �� ������ ���� - ���δ� 20~90 ���δ� 20~45
//2. Ŀ�� Ŀ����
//3. ���� Ŀ����
//4. ������ ���� ���� - ������ Ƚ�� ����(�ִ� 10ȸ) / ������ ����
//5. �ڷΰ���

//�ɼ� ȭ��
void Play::SettingScreen()
{
	int select;
	const string settingText[] = { "= Option =","1.Map Size Set","2.Cursor Custom","3.Stone Custom","4.Undo Count Set","5.Return","�Է� : " };
	while (1)
	{
		//���� â������ �ɼ����� ���ü� �־���ϴϱ� cls�� ���� �ȵ�
		m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
		m_DrawManager.DrawMidTextList(settingText, m_iWidth, m_iHeight, sizeof(settingText) / sizeof(string),0.5f);
		cin >> select;
		switch (select)
		{
		case 1: //�� ������ ����
			if (m_bPlayCheck) //���� �÷��̾� üũ�� �Ǿ��ִٸ�
			{
				Warning(); //���� �Ұ��� 
				break;
			}

			MapSizeChange();//�� ������ ����
			break;
		case 2: //Ŀ�� ��� ����
			ShapeChange(&m_iCursor);
			break;
		case 3: //�� ��� ����
			ShapeChange(&m_iStone);
			if (m_bPlayCheck)
			{
				m_Player[0]->ChangeStoneShape(m_strStoneShape[m_iStone][0]);
				m_Player[1]->ChangeStoneShape(m_strStoneShape[m_iStone][1]);
			}
			break;
		case 4: //������ Ƚ�� ����
			if (m_bPlayCheck) //���� �÷��̾� üũ�� �Ǿ��ִٸ�
			{
				Warning(); //���� �Ұ��� 
				break;
			}
			UndoCount();
			break;
		case 5: //���ư���
			return;
		default: //������ Ű�Է��� ����
			break;
		}
	}
}

//1.�ʻ����� ���� 
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

		if ((width >=20 && width <=90) && (height >= 20 && height <= 45)) // ���ǿ� ������ Ż��
		{
			m_iWidth = width;
			m_iHeight = height;
			break;
		}

		m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
		m_DrawManager.DrawMidText("���� �Ұ���", m_iWidth, m_iHeight * 0.5f);
		m_DrawManager.DrawMidText("(���� : 20 ~ 90 , ���� : 20 ~ 45)", m_iWidth, m_iHeight * 0.5f + 1);
		_getch();
	}
	//�ٲ� ������ ��� �ܼ�â ũ�⺯��� �� �ٽ� ��ο� �ؾ���
}

//2,3. Ŀ��/�� ��� ����
void Play::ShapeChange(int *shapeTarget) 
{
	int select;
	string ShapeText[] = {"= Set Cusor =", "1.","2.","3.","4.","5.Return", "�Է� : "};
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
			//���⿡ Ŀ�����
			*shapeTarget = select - 1;
			system("pause");
			return;
		case 5:
			return;
		default: //�߸��� �������� �ٽ�
			break;
		}
	}
}

//4.������ �ɼ� ����
void Play::UndoCount()
{
	int select;
	string undoText[] = { "= Set Undo =","1.Set Undo Count","2.Undo Off","3.Return","�Է� : "  };
	while (1)
	{
		system("cls");
		m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
		m_DrawManager.DrawMidTextList(undoText, m_iWidth, m_iHeight, sizeof(undoText) / sizeof(string),0.3f);
		cin >> select;
		switch (select)
		{
		case 1: //������ Ƚ������
			while (true)
			{
				m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
				m_DrawManager.DrawMidText("������ Ƚ�� �Է�(�ִ� 10ȸ) : ", m_iWidth, m_iHeight * 0.5f);
				cin >> m_iUndoCount;
				if (m_iUndoCount <= 10 && m_iUndoCount >= 0) 
				{
					break;
				}
				m_DrawManager.DrawMidText("������ ���� �ʽ��ϴ� ( 0 ~ 10)", m_iWidth, m_iHeight * 0.5f + 1);
				_getch(); //�ƹ�Ű�� ������ �Ѿ
			}
			break;
		case 2: //���������
			m_DrawManager.SettingDraw(m_iWidth, m_iHeight);
			m_DrawManager.DrawMidText("������ OFF", m_iWidth, m_iHeight / 2);
			m_iUndoCount = 0;
			_getch();
			break;
		case 3: //���ư���
			return;
		default: //�߸��� �������� �ٽ�
			break;
		}
	}
}

//���� �÷������϶� �ɼ� ���� �Ұ���(���)
void Play::Warning()
{
	string warningText[] = { "���� �Ұ���", "(Game Play��)"};
	system("cls");
	m_DrawManager.DrawMidTextList(warningText, m_iWidth, m_iHeight, sizeof(warningText) / sizeof(string),0.5f);
	m_DrawManager.gotoxy(STARTPOS, m_iHeight);
	system("pause");
}

//--���� �÷���--//

//�ʱ�ȭ 
void Play::Init()
{
	//���� �� üũ
	m_bPlayCheck = true;
	//�� �� �ʱ�ȭ
	m_iTurn = 0;
	m_DrawManager.BoxDraw(m_iWidth, m_iHeight);//������ ���
}


//�÷��̾� ����
//*���� ���� �����Ҷ� �÷��̾ �����ؾ��ϴµ� �̶� �÷��̾��� ����0, 0 �����ϸ�ȵ�
//�׸��� �÷��̾� �� ������ ���� ���������� �����Ҽ��־�� ��
void Play::PlayerSet()
{
	string name;
	system("cls");
	m_DrawManager.SettingDraw(m_iWidth, m_iHeight);

	//�÷��̾� 1 �Է�
	m_DrawManager.TextDraw("P1 �̸�", m_iWidth - 5, m_iHeight * 0.3f);
	m_DrawManager.TextDraw("�Է�: ", m_iWidth - 5, m_iHeight * 0.3f+1);
	cin >> name;
	m_Player[0] = new Player(name, m_iWidth, m_iHeight*0.5f, m_strStoneShape[m_iStone][0], m_iUndoCount);

	//�÷��̾� 2 �Է�
	m_DrawManager.TextDraw("P2 �̸�", m_iWidth - 5, m_iHeight * 0.6f);
	m_DrawManager.TextDraw("�Է�: ", m_iWidth - 5, m_iHeight * 0.6f + 1);
	cin >> name;
	m_Player[1] = new Player(name, m_iWidth, m_iHeight*0.5f, m_strStoneShape[m_iStone][1], m_iUndoCount);

}

//�÷��̾� �̵�
void Play::Movement(int *pos, int value, int x, int y) //�ٲ� ��ǥ�� ������ǥ
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

//���÷��� ���� ��������
//1. ������ ������ ���÷��̸� �����ش�.
//2. ���ӵ��� ESC�� ������ ������ ��� �̾��ϱ� ����
//3. ���� �ֱٿ� �� ���� ���÷��� ����
//���� ���� ������ �����ϱ�/ �̾��ϱ�/ ���÷��� 

//���÷���
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

	m_DrawManager.BoxDraw(m_iWidth, m_iHeight);//������ ���

	while (!m_Read.eof())
	{
		m_Read >> posX;
		m_Read >> posY;
		if (posX == UNDO && posY == UNDO)
		{
			m_Player[m_iTurn % 2]->Undocount();//���� �÷��̾� ������ Ƚ���� 1 �����ѵ�
			m_iTurn--;//���� -1
			m_Player[m_iTurn % 2]->Undo(m_iWidth * 2, m_iHeight); //������ ����
			ControlGuide(m_iTurn % 2);
			Sleep(1000);
		}
		else
		{
			if (m_Read.eof())
			{
				break;
			}
			ControlGuide(m_iTurn % 2);//���̵� ���
			m_Player[m_iTurn % 2]->StoneDrop(posX, posY); //�� ����
			m_iTurn++;
			Sleep(1000);
		}
	}
	m_DrawManager.DrawMidText(m_Player[m_iTurn % 2]->GetName() + "�� �¸�!!", m_iWidth, m_iHeight * 0.5f);//�÷��̾� ���� ȭ���߾ӿ� ���
	m_bPlayCheck = false; //������ üũ ����
	//�Ҵ��ߴ� �÷��̾� �Ҵ�����
	delete m_Player[0];
	delete m_Player[1];
	m_Read.close();
	_getch();//�ƹ�Ű�� ������
}

//�̾��ϱ�
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

	m_DrawManager.BoxDraw(m_iWidth, m_iHeight);//������ ���

	while (!m_Read.eof())
	{
		m_Read >> posX;
		m_Read >> posY;
		if (posX == UNDO && posY == UNDO)
		{
			m_Player[m_iTurn % 2]->Undocount();//���� �÷��̾� ������ Ƚ���� 1 �����ѵ�
			m_iTurn--;//���� -1
			m_Player[m_iTurn % 2]->Undo(m_iWidth * 2, m_iHeight); //������ ����
			ControlGuide(m_iTurn % 2);
		}
		else
		{
			ControlGuide(m_iTurn % 2);//���̵� ���
			m_Player[m_iTurn % 2]->PosUpdate(posX, posY); //�÷��̾� ������ ��ǥ ����
			m_Player[m_iTurn % 2]->StoneDrop(posX, posY); //�� ����
			m_iTurn++;
		}
	}
	m_Read.close();
}

//���� �÷���
void Play::Playing()
{
	//ó�� �������� �߰����� ����
	int x = m_Player[m_iTurn % 2]->GetXPos();
	int y = m_Player[m_iTurn % 2]->GetYPos();
	if (x%2 !=0)
	{
		x++;
	}
	ControlGuide(m_iTurn % 2);//���̵� ���
	m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);	//Ŀ�����
	//�ڱ� �������� ��� Ȯ��? - �ϼ�/2 �ؼ� �������� ������ 1P ������ 2P
	//�� ǥ�ô� ��ü �ϼ� + 1�� ǥ��
	while (m_bPlayCheck)
	{
		char select = _getch(); //cin ���� X
		switch (select)
		{
		//���� �̵�
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
			//�� ����
		case ENTER:
			//������ ���� ���� ���
			if (m_Player[0]->StoneCheck(x, y)==false && m_Player[1]->StoneCheck(x, y) == false)
			{
				m_Player[m_iTurn % 2]->PosUpdate(x, y); //�÷��̾� ������ ��ǥ ����
				m_Player[m_iTurn % 2]->StoneDrop(x, y); //�� ����
				m_Save << endl << x << " " << y;
				if (m_Player[m_iTurn % 2]->WinCheck())//���� �÷��̾ �¸��ߴٸ�
				{
					FileCopy();
					m_DrawManager.DrawMidText(m_Player[m_iTurn % 2]->GetName() + "�� �¸�!!", m_iWidth, m_iHeight * 0.5f);//�÷��̾� ���� ȭ���߾ӿ� ���
					m_bPlayCheck = false; //������ üũ ����
					_getch();//�ƹ�Ű�� ������ 
					break;
				}

				m_iTurn += 1; //������
				x = m_Player[m_iTurn % 2]->GetXPos(); //���� �� �÷��̾��� X��ǥ �޾ƿ�
				y = m_Player[m_iTurn % 2]->GetYPos(); //���� �� �÷��̾��� Y��ǥ �޾ƿ�
				ControlGuide(m_iTurn % 2); //���̵� ���
				m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);//������ �÷��̾��� ��ġ�� Ŀ�� ���
			}
			//�ƴҰ�� Ŀ�� �����
			break;
			//������
		case OPTION_UNDO:
			if (m_Player[m_iTurn % 2]->GetUndo() > 0 && m_iTurn > 0) //�����Ⱑ �����ϴٸ� (ù��° ���ΰ�� ������ X)
			{
				m_Save << endl << UNDO << " " << UNDO;
				m_Player[m_iTurn % 2]->Undocount();//���� �÷��̾� ������ Ƚ���� 1 �����ѵ�
				m_iTurn--;//���� -1
				m_Player[m_iTurn % 2]->Undo(m_iWidth * 2, m_iHeight); //������ ����
				m_DrawManager.PlayingBoxEmpty(m_iWidth * 2, m_iHeight, x, y);
				ControlGuide(m_iTurn % 2);
				x = m_Player[m_iTurn % 2]->GetXPos(); //�÷��̾��� X��ǥ �޾ƿ�
				y = m_Player[m_iTurn % 2]->GetYPos(); //�÷��̾��� Y��ǥ �޾ƿ�
				m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);//������ Ŀ�� �����
			}
			break;
			//�ɼ�
		case OPTION_KEY: 
			SettingScreen();
			AllPrint(x, y);
			break;
			//����
		case ESC: 
			m_Save.close(); //���� ���� ����
			m_bPlayCheck = false; //������ üũ ����
			break;
		default:
			break;
		}
	}

	//�Ҵ��ߴ� �÷��̾� �Ҵ�����
	delete m_Player[0];
	delete m_Player[1];
}

void Play::FileCopy()
{
	m_Save.close(); //�̰����� ���� ���� ����
	ifstream load;
	string saveLine;
	load.open("LoadGame.txt");
	m_Save.open("RePlay.txt");//����� ���
	while (!load.eof())
	{
		getline(load, saveLine);
		m_Save << saveLine << " ";
	}
	m_Save.close(); //���� ���� ����
	load.close(); //���� ����
	m_Save.open("LoadGame.txt");//����� ���� �����ٰ�(��� ������ ���ư�)
	m_Save << "100"; //����ٴ� ������ 100 �ְ�
	m_Save.close();//�ٽ� ����
}
//������Ʈ
void Play::AllPrint(int x, int y)
{
	system("cls");
	m_DrawManager.BoxDraw(m_iWidth, m_iHeight); //�� �׸���
	m_Player[0]->StoneDrow();//�� ���
	m_Player[1]->StoneDrow();
	ControlGuide(m_iTurn % 2);//���̵����
	m_DrawManager.TextDraw(m_strCursorShape[m_iCursor][m_iTurn % 2], x, y);//������ Ŀ�� �����
}

//���۰��̵�
void Play::ControlGuide(int turn)
{
	const string ControlGuideText[] = {"====����Ű====","�̵� : W,A,S,D ������ : ENTER","������ : N �ɼ� : P ���� : ESC","PlayerName :        ������ : ", "Thrn: " };
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