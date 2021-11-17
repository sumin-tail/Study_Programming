#include"MapDraw.h"

MapDraw::MapDraw()
{

}

MapDraw::~MapDraw()
{

}

//�ٵ��� �׸��� �Լ� (���θ޴�/���� �÷���)
void MapDraw::BoxDraw(int Width, int Height)
{
	for (int y = 0; y < Height; y++) //y�� 0 �̰� ���κ��� �۴�
	{
		gotoxy(STARTPOS, STARTPOS + y); //�׸� ��ǥ�� �̵�
		if (y == 0) //�� ù��°���ϰ�� �������������� < �� ���¿�����
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else if (y == Height - 1) //�� ������ ���ϰ��
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else //�Ѵ� �ƴҰ��
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
	}
	return;
}

//���� �׸��� �Լ�(�ɼ�)
void MapDraw::SettingDraw(int Width, int Height)
{
	for (int y = 0; y < Height; y++) //y�� 0 �̰� ���κ��� �۴�
	{
		gotoxy(STARTPOS, STARTPOS + y); //�׸� ��ǥ�� �̵�
		if (y == 0) //�� ù��°���ϰ�� �������������� < �� ���¿�����
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else if (y == Height - 1) //�� ������ ���ϰ��
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else //�Ѵ� �ƴҰ��
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "��";
		}
	}
	return;
}

//���� ���� �׸��� �Լ�(�޴�)
void MapDraw::SettingMenuDraw(int Width, int Height, int startY)
{
	for (int y = 0; y < Height; y++) //y�� 0 �̰� ���κ��� �۴�
	{
		gotoxy(Width, startY + y); //�׸� ��ǥ�� �̵�
		if (y == 0) //�� ù��°���ϰ�� �������������� < �� ���¿�����
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else if (y == Height - 1) //�� ������ ���ϰ��
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else //�Ѵ� �ƴҰ��
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "��";
		}
	}
	return;
}

//�����÷��� �ٵ��� ��� ä���
void MapDraw::PlayingBoxEmpty(int Width, int Height, int x, int y)
{
	gotoxy(x, y);

	if (y == 0) //�� ù��°���ϰ�� �������������� < �� ���¿�����
	{
		if (x == 0)
		    cout << "��";
		if (x < Width - 2)
			cout << "��";
		if (x == Width - 2)
		    cout << "��";
	}
	else if (y == Height - 1) //�� ������ ���ϰ��
	{
		if (x == 0)
		    cout << "��";
		if (x < Width - 2)
			cout << "��";
		if (x == Width - 2)
			cout << "��";
	}
	else //�Ѵ� �ƴҰ��
	{
		if (x == 0)
	      	cout << "��";
		if (x < Width - 2)
			cout << "��";
		if (x == Width - 2)
		    cout << "��";
	}
	return;
}

//�� ���� Ŭ����
void MapDraw::Erase(int Width, int Height)
{
	for (int y = 1; y < Height-1; y++) 
	{
		gotoxy(STARTPOS + 2, STARTPOS + y); //Ư�����ڴ� ������ 2ĭ
		for (int x = 1; x < Width-1; x++)
		{
			cout << "  ";
		}
	}
	return;
}

//Ư�� ��ǥ Ŭ����
void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

//�߰��� �ؽ�Ʈ ����ϴ� �Լ�
void MapDraw::DrawMidText(string str, int x, int y)
{
	//�ش� ���ڼ��� ����ؼ� �߰��� ��� �ؾ���
	//���� ������ ����-��� ���ڼ� ����  = ���� ��� ���� ����
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

//�ؽ�Ʈ ����Ʈ ���
void MapDraw::DrawMidTextList(const string str[], int x, int y, int len, float margin)
{
	int temp;
	margin -= ((len / 2) * 0.1f);
	for(int j = 0; j<len; j++, margin += 0.1f)
	{
		temp = x;
		if (temp > str[j].size() / 2)
			temp -= str[j].size() / 2;
		gotoxy(temp, y * margin);
		cout << str[j];

	}
}

void MapDraw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}