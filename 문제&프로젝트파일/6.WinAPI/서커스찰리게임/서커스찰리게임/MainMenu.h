#pragma once
#include "BitMap.h"
#include "��Ŀ����������.h"

//���� �޴� ��ο�� Ŭ����
class MainMenu
{
private:
	BitMap* m_Title; //Ÿ��Ʋ
	BitMap* m_Menu; //�޴�
	BitMap m_Black; //���� ȭ��
	BitMap m_Point; //ȭ��ǥ
	float m_Animationtimer;
	int m_StarCount; // �� ���� ����� ����
	int m_PointSelect; //ȭ��ǥ�� ����Ű�� �޴� (��ȣ)
public:
	MainMenu();
	~MainMenu();
	void ImageInit(HDC hdc, const char* name, int count, BitMap* arr);
	void Init(HDC hdc);
	void PointDraw(HDC hdc, int x, int y, int interval);
	void StarDraw(HDC hdc, int posX, int titleWidth, int titleHeight);
	void Update(float elapsed);
	void Draw(HDC hdc, int windowWidth, int windowHeight);
};

