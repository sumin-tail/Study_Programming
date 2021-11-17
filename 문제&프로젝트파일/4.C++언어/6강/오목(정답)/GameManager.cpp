#include "GameManager.h"



GameManager::GameManager()
{
	m_bPlayState = false; //�� �÷��� ����
	m_iTurn = 1; //�� ����
	//����Ʈ ���� ���� (20) ����
	m_iHeight = HEIGHT;
	m_iWidth = WIDTH;
	//�÷��̾� ������ �ʱ�ȭ
	m_Player[PLAYERTYPE_BLACK].SetCursorIcon(BLACKTEAMICON);
	m_Player[PLAYERTYPE_BLACK].SetStoneIcon(BLACKTEAMICON);
	m_Player[PLAYERTYPE_WHITE].SetCursorIcon(WHITETEAMICON);
	m_Player[PLAYERTYPE_WHITE].SetStoneIcon(WHITETEAMICON);
}

void GameManager::LobbyDraw() //���۸޴� ��ο�
{
	m_DrawManager.DrawMidText("�� �� �� ��", m_iWidth, m_iHeight* 0.3f);
	m_DrawManager.DrawMidText("1.���� ����", m_iWidth, m_iHeight* 0.4f);
	m_DrawManager.DrawMidText("2.�ɼ� ����", m_iWidth, m_iHeight* 0.5f);
	m_DrawManager.DrawMidText("3.���� ����", m_iWidth, m_iHeight* 0.6f);
	m_DrawManager.BoxDraw(m_iWidth, m_iHeight* 0.7, m_iWidth / 2, 3);
	m_DrawManager.gotoxy(m_iWidth, m_iHeight* 0.7 + 1);
}


void GameManager::DrawPoint() //�ش� ��ǥ ä��� (�ٵ���/��/������)
{
	m_DrawManager.Erase(m_Player[m_iTurn % 2].GetCursor().m_ix, m_Player[m_iTurn % 2].GetCursor().m_iy, m_iWidth, m_iHeight); //������ ��ǥ�� (�ٵ���)ä��
	m_Player[PLAYERTYPE_BLACK].DrawStone(m_Player[m_iTurn % 2].GetCursor().m_ix, m_Player[m_iTurn % 2].GetCursor().m_iy);//�ش���ǥ�� ���� ���� �ִٸ� ä��
	m_Player[PLAYERTYPE_WHITE].DrawStone(m_Player[m_iTurn % 2].GetCursor().m_ix, m_Player[m_iTurn % 2].GetCursor().m_iy);//�ش���ǥ�� �Ͼ� ���� �ִٸ� ä��
}

void GameManager::InputInfoDraw() //������ �ʴ� ����Ű ���� ��ο�
{
	m_DrawManager.DrawMidText("====����Ű====", m_iWidth, m_iHeight);
	m_DrawManager.DrawMidText("�̵� : A,S,W,D ������ : ENTER", m_iWidth, m_iHeight+1);
	m_DrawManager.DrawMidText("������ : N �ɼ� : P ���� : ESC", m_iWidth, m_iHeight + 2);
}

void GameManager::CurPlayerInfoDraw()//���ϴ� ���� ��ο�
{
	string Name = m_Player[m_iTurn % 2].GetName(); //�ش����� �÷��̾� ������ �޾ƿ���
	int UndoCount = m_Player[m_iTurn % 2].GetUndo(); //������ Ƚ�� �޾ƿ���
	string str = "Player Name : " + Name + "       ������ : " + to_string(UndoCount) + "  ";//�̰͵��� �� ���ļ�
	m_DrawManager.DrawMidText(str, m_iWidth, m_iHeight + 3); //�߰�����Ѵ�
	m_DrawManager.DrawMidText("Turn : " + to_string(m_iTurn) + "  " , m_iWidth, m_iHeight + 4);
}

void GameManager::Input() //�Է¹���
{
	char ch = getch();
	Point Cursor; //Point�� x��ǥ�� y��ǥ�� ������ ����
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
			m_bPlayState = false; //�÷��� ���¸� ���÷��̷� ����
			break;
		case KEY_DROP: //���� ���� ���
			Cursor = m_Player[m_iTurn % 2].GetCursor();//���� �� �÷��̾��� ��ǥ�� ������ �� 
			if(m_Player[PLAYERTYPE_BLACK].CompareStone(Cursor.m_ix, Cursor.m_iy) || m_Player[PLAYERTYPE_WHITE].CompareStone(Cursor.m_ix, Cursor.m_iy))//�ش���ǥ�� �������̵� ���� �������
				break;//Ż��
			m_Player[m_iTurn % 2].CreateStone();//�ƴ϶�� ���� ����
			if(m_Player[m_iTurn % 2].WinCheck(m_iWidth, m_iHeight))//�¸� üũ
			{
				m_bPlayState = false;//�÷��� ���¸� ���÷��̷� �ٲٰ�
				m_DrawManager.DrawMidText(m_Player[m_iTurn % 2].GetName() + "�� �¸�!!", m_iWidth, m_iHeight* 0.5f); //������ �÷��̾� �̸� ���
				getch();//�ƹ��ų� �Է��̵�����
				return; //Ż��
			}
			m_iTurn++; //�ϼ� �ø�
			CurPlayerInfoDraw(); //�ϴ� ���̵� �����
			break;
		case KEY_UNDO://������
			if(m_Player[m_iTurn % 2].GetUndo() > 0 && m_iTurn > 1) //������ Ƚ���� �����ְ� / ���� 1�� �̻��� ���
			{
				m_Player[m_iTurn % 2].EraseCursor(m_iWidth,m_iHeight); //���� �� Ŀ�� ��ǥ ����
				m_Player[m_iTurn % 2].DownUndo(); //������ Ƚ�� ��ĭ ����
				m_iTurn--; //�ϼ� -1
				m_Player[m_iTurn % 2].Undo(m_iWidth, m_iHeight);//������
				CurPlayerInfoDraw(); //�ϴ� ���̵� �����
			}
			break;
		case KEY_OPTION:
			Option(); //�ɼ�
			system("cls");//Ŭ����
			m_DrawManager.Draw(m_iWidth, m_iHeight); //�ʵ�ο�
			InputInfoDraw(); //��� ���̵� �����
			CurPlayerInfoDraw(); //�ϴ� ���̵� �����
			m_Player[PLAYERTYPE_BLACK].AllStoneDraw(); //���� �� ��� �����
			m_Player[PLAYERTYPE_WHITE].AllStoneDraw(); //�� �� ��� �����
			break;
	}
}


void GameManager::SetName(string str,PLAYERTYPE type, int x, int y)
{
	m_DrawManager.DrawMidText(str, x,y); //P1 �̸� �߰��� ���
	m_DrawManager.DrawMidText("�Է� : ", x, y + 1); //�����ٿ� �Է� : ���
	m_Player[type].SetName(); //�̸� cin���� �޾Ƽ� �ٷ� �÷��̾� ��� ���� m_strName�� �������
	m_Player[type].PlayerSet(m_iWidth, m_iHeight); //�÷��̾� ����
}

void GameManager::GameStart()
{
	system("cls");//Ŭ����
	m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight); //�� �ڽ� ��ο�
	SetName("P1 �̸�", PLAYERTYPE_BLACK, m_iWidth, m_iHeight * 0.3f);
	SetName("P2 �̸�", PLAYERTYPE_WHITE, m_iWidth, m_iHeight * 0.5f);
	system("cls");//Ŭ����
	m_DrawManager.Draw(m_iWidth, m_iHeight); //�ٵ��� ��ο�
	InputInfoDraw();
	CurPlayerInfoDraw();
	while(m_bPlayState) //������ �÷������� ���� 
	{
		m_Player[m_iTurn % 2].DrawCursor(); //�ش� �� �÷��̾� Ŀ�� ��ο�
		Input();
	}
}

void GameManager::SetUndo()//������ ����
{
	while(1)
	{
		system("cls");
		int Height, Width;
		if(m_bPlayState == false)//�÷��� ���°� �ƴҰ�쿡�� 
		{
			int Select;
			system("cls");
			m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
			m_DrawManager.DrawMidText("= Set Undo  =", m_iWidth, m_iHeight* 0.2f);
			m_DrawManager.DrawMidText("1.Set Undo Count", m_iWidth, m_iHeight* 0.3f);
			m_DrawManager.DrawMidText("2.Undo Off", m_iWidth, m_iHeight* 0.4f);
			m_DrawManager.DrawMidText("3.Return", m_iWidth, m_iHeight* 0.5f);
			m_DrawManager.DrawMidText("�Է� : ", m_iWidth, m_iHeight* 0.6f);
			cin >> Select;
			switch(Select)
			{
				case 1:
					while(1)
					{
						system("cls");
						m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
						m_DrawManager.DrawMidText("������ Ƚ�� �Է�(�ִ� 10ȸ) : ", m_iWidth, m_iHeight* 0.5f);
						cin >> Select;
						if(Select <= 10 && Select >= 0)
						{
							m_Player[PLAYERTYPE_BLACK].SetUndo(Select);
							m_Player[PLAYERTYPE_WHITE].SetUndo(Select);
							break;
						}
						m_DrawManager.DrawMidText("������ ���� �ʽ��ϴ� ( 0 ~ 10 )", m_iWidth, m_iHeight* 0.6f);
						getch();
					}
					break;
				case 2:
					system("cls");
					m_DrawManager.BoxDraw(0, 0, m_iWidth, m_iHeight);
					m_DrawManager.DrawMidText("������ Off", m_iWidth, m_iHeight* 0.5f);
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
			m_DrawManager.DrawMidText("���� �Ұ���", m_iWidth, m_iHeight* 0.4f);
			m_DrawManager.DrawMidText("(Game Play��)", m_iWidth, m_iHeight* 0.5f);
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
				m_DrawManager.DrawMidText("���� �Ұ���", m_iWidth, m_iHeight* 0.4f);
				m_DrawManager.DrawMidText("(���� : 20 ~ 90 , ���� : 20 ~ 45)", m_iWidth, m_iHeight* 0.5f);
				m_DrawManager.gotoxy(0, m_iHeight);
				getch();
			}
		}
		else
		{
			system("cls");
			m_DrawManager.DrawMidText("���� �Ұ���", m_iWidth, m_iHeight* 0.4f);
			m_DrawManager.DrawMidText("(Game Play��)", m_iWidth, m_iHeight* 0.5f);
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
	m_DrawManager.DrawMidText("1.��,��", m_iWidth, m_iHeight* 0.3f);
	m_DrawManager.DrawMidText("2.��,��", m_iWidth, m_iHeight* 0.4f);
	m_DrawManager.DrawMidText("3.��,��", m_iWidth, m_iHeight* 0.5f);
	m_DrawManager.DrawMidText("4.��,��", m_iWidth, m_iHeight* 0.6f);
	m_DrawManager.DrawMidText("5.Return", m_iWidth, m_iHeight* 0.7f);
	m_DrawManager.DrawMidText("�Է� : ", m_iWidth, m_iHeight* 0.8f);
	cin >> Select;
	switch(Select)
	{
		case 1:
			m_Player[PLAYERTYPE_BLACK].SetCursorIcon("��");
			m_Player[PLAYERTYPE_WHITE].SetCursorIcon("��");
			system("pause");
			break;
		case 2:
			m_Player[PLAYERTYPE_BLACK].SetCursorIcon("��");
			m_Player[PLAYERTYPE_WHITE].SetCursorIcon("��");
			system("pause");
			break;
		case 3:
			m_Player[PLAYERTYPE_BLACK].SetCursorIcon("��");
			m_Player[PLAYERTYPE_WHITE].SetCursorIcon("��");
			system("pause");
			break;
		case 4:
			m_Player[PLAYERTYPE_BLACK].SetCursorIcon("��");
			m_Player[PLAYERTYPE_WHITE].SetCursorIcon("��");
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
	m_DrawManager.DrawMidText("1.��,��", m_iWidth, m_iHeight* 0.3f);
	m_DrawManager.DrawMidText("2.��,��", m_iWidth, m_iHeight* 0.4f);
	m_DrawManager.DrawMidText("3.��,��", m_iWidth, m_iHeight* 0.5f);
	m_DrawManager.DrawMidText("4.��,��", m_iWidth, m_iHeight* 0.6f);
	m_DrawManager.DrawMidText("5.Return", m_iWidth, m_iHeight* 0.7f);
	m_DrawManager.DrawMidText("�Է� : ", m_iWidth, m_iHeight* 0.8f);
	cin >> Select;
	switch(Select)
	{
		case 1:
			m_Player[PLAYERTYPE_BLACK].SetStoneIcon("��");
			m_Player[PLAYERTYPE_WHITE].SetStoneIcon("��");
			system("pause");
			break;
		case 2:
			m_Player[PLAYERTYPE_BLACK].SetStoneIcon("��");
			m_Player[PLAYERTYPE_WHITE].SetStoneIcon("��");
			system("pause");
			break;
		case 3:
			m_Player[PLAYERTYPE_BLACK].SetStoneIcon("��");
			m_Player[PLAYERTYPE_WHITE].SetStoneIcon("��");
			system("pause");
			break;
		case 4:
			m_Player[PLAYERTYPE_BLACK].SetStoneIcon("��");
			m_Player[PLAYERTYPE_WHITE].SetStoneIcon("��");
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
		m_DrawManager.DrawMidText("�Է� : ", m_iWidth, m_iHeight* 0.8f);
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
				m_bPlayState = true; //�÷��� ���¸� �÷��̷� ����
				m_iTurn = 1; //�ϼ� ����
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
