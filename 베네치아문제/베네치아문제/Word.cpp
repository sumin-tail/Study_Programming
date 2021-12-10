#include "Word.h"

Word::Word(string word, int x) : m_word(word), m_y(1), m_x(x)
{
	int a = x + word.length();
	if (a >= WIDTHFULL-2)
	{
		//Ư������ ũ��� 2
		int pos = a - (WIDTHFULL - 2);
		m_x = x - pos;
	}
	draw();//������ ���� ȭ�鿡 �׷���
}


Word::Word() :
	m_x(0),
	m_y(0)
{}

void Word::draw()
{
	BLUE
	m_DrawInterface.TextDraw(m_word, m_x, m_y);
}

void Word::drop()
{
	m_DrawInterface.gotoxy(m_x, m_y);//��ǥ�̵�
	for (int i = 0; i < m_word.length(); i++)//�ܾ��� ���̸� ŭ ������
	{
		cout << " ";
	}
	m_y++;//�ܾ �Ʒ��� ��ĭ ����

}

string Word::WordGet()
{
	return m_word;
}

bool Word::Die(string text)
{
	return false;
}
