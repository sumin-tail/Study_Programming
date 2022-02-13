#include "Interface.h"

Interface::Interface()
{
	m_Interface = new BitMap[3];
}

Interface::~Interface()
{
	delete[] m_Interface;
}

void Interface::Init(HDC hdc)
{
	char buf[256]; //char�� �迭����
	for (int i = 0; i < 3; i++)
	{
		sprintf_s(buf, "Resource//interface_%d.bmp", i + 1); //�̹��� ��ġ ���ۿ� ����
		m_Interface[i].Init(hdc, buf);//�迭 �ʱ�ȭ
	}

}

void Interface::Update(float deltaTime)
{

}

void Interface::InterfaceDraw(HDC hdc, int windowWidth, float pos, int Life, int score, int bonus)
{
	SetTextColor(hdc, RGB(255, 255, 255)); //���� �� ����
	SetBkColor(hdc, RGB(0, 0, 0)); //���� ����

	m_Interface[0].Draw(hdc, windowWidth * 0.5f - m_Interface[0].GetSize().cx * 0.5f, 10); //UI ����

	for (int i = 0; i < Life; i++) //���߿� �÷��̾� ������ �޾ƿͼ� ó��
	{
		m_Interface[1].Draw(hdc, 850 - m_Interface[1].GetSize().cx*i , 40);
	}

	if (pos > 9200)
	{
		pos = 9200;
	}

	char buf[256];
	//std::string str;
	for (int i = 0; i < 11; i++) //���� ǥ��
	{
		m_Interface[2].Draw(hdc, 50 + 1000*i - pos, 400);
		//str = std::to_string(100 - i * 10);
		sprintf_s(buf, "%d", 100 - i * 10);
		TextOutA(hdc, 70 + 1000 * i - pos, 405, buf, strlen(buf));
	}

	sprintf_s(buf, "score : %d                          bonus : %d", score, bonus);
	TextOutA(hdc, 200, 30, buf, strlen(buf));
}
