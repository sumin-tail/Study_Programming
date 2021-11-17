#pragma once
#include"Mecro.h"

//�� ��ο� Ŭ����
class MapDraw
{
public:
	//�ٵ��� �׸��� �Լ� (���θ޴�/���� �÷���)
	void BoxDraw(int Width, int Height);
	//���� �׸��� �Լ�(�ɼ�)
	void SettingDraw(int Width, int Height);
	//���� �׸��� �Լ�(���� �޴�)
	void SettingMenuDraw(int Width, int Height, int startY);
	//�ܰ�(��) ���� Ŭ����
	void Erase(int Width, int Height);
	//�����÷��� �ٵ��� ��� ä���
	void PlayingBoxEmpty(int Width, int Height, int x, int y);
	//�޴� �ؽ�Ʈ
	void MenuDraw(int Width, int Height);
	//�ش� ��ǥ �����
	void ErasePoint(int x, int y);
	//�߰��� �ؽ�Ʈ ������ִ� �Լ�
	void DrawMidText(string str, int x, int y);
	//�Ϲ� �ؽ�Ʈ ���
	void TextDraw(string str, int x, int y);
	//�ؽ�Ʈ ����Ʈ ���
	void DrawMidTextList(const string str[], int Width, int Height,int len,float margin);
	//��ǥ �̵� �Լ�
	static inline void gotoxy(int x, int y) 
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//�ش� ��ǥ�� �̵�
	}
	MapDraw();
	~MapDraw();
};
