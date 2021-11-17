#pragma once
#include"Mecro.h"
//�� ��ο� Ŭ����
class MapDraw
{
public:
	static void BoxDraw(int Start_x, int Start_y, int Width, int Height) //���ڸ� �׸��� �Լ�
	{
		for (int y = 0; y < Height; y++) //y�� 0 �̰� ���κ��� �۴�
		{
			gotoxy(Start_x, Start_y + y); //�׸� ��ǥ�� �̵�
			if (y == 0) //�� ù��°���ϰ�� �������������� < �� ���¿�����
			{
				cout << "��";
				for (int x = 1; x < Width - 1; x++)
					cout << "��";//�������� �� ���� �����ȣ �� �� �ٲ� < ����غ��̴µ� �������̳�
				cout << "�� ";
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
				cout << "�� ";
			}
		}
		return;
	}
	static void DrawPoint(string str, int x, int y)
	{
		gotoxy(x * 2, y);
		cout << str; //�ؽ�Ʈ ���
		gotoxy(-1, -1);//Ŀ���� �� �ٽ� -1, -1 ��? ȭ��󿡼� �Ⱥ��̰��Ϸ���.
		return;
	}
	static void DrawMidText(string str, int x, int y) //�ؽ�Ʈ�� ����� ����ϴ� �Լ�
	{
		if (x > str.size() / 2) //���࿡ ���� ���� ��ġ�� ����� ������ ������ ���ݺ��� ���ٸ� 
			x -= str.size() / 2; //����� ������ �����ŭ ���ش�.
		gotoxy(x, y);//��ǥ�̵��ϰ�
		cout << str; //�ؽ�Ʈ ���
		return;
	}
	static void TextDraw(string str, int x, int y)//���� ���
	{
		gotoxy(x, y); //�ش���ǥ�� �̵�
		cout << str; //�������
	}
	static void ErasePoint(int x, int y)// ����
	{
		gotoxy(x * 2, y);//�ش���ǥ�� �̵�
		cout << "  "; //����(�ش� ��ǥ���ִ� �Ϳ� "  "������ؼ� ����)
		gotoxy(-1, -1); //��ǥ����
		return;
	}
	MapDraw() {}
	static inline void gotoxy(int x, int y) //����ƽ ��� �Լ��鼭 �ζ��� �Լ� 
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//�ش� ��ǥ�� �̵�
	}
	~MapDraw() {}
};

