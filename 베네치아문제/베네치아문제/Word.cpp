#include "Word.h"

Word::Word(string word, int x) : m_word(word), m_y(1), m_x(x), hide(false)
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
	m_y(0), hide(false)
{}

void Word::draw()
{
	//���� ���� ������ǥ x = 46 , y= 21���� y�� 5ĭ x�� 38ĭ
    //x 46 ~ 84 y 21~ 26

	if ((m_y >= 21 && m_y <=25) && ((m_x >= 46 && m_x <= 84) || (m_x <= 46 && m_x + m_word.length() >= 46)))
	{
		hide = true;
		return;
	}
	hide = false;
	BLUE
	m_DrawInterface.TextDraw(m_word, m_x, m_y);
}

bool Word::drop()
{
	if (!hide)
	{
		m_DrawInterface.gotoxy(m_x, m_y);//��ǥ�̵�
		for (int i = 0; i < m_word.length(); i++)//�ܾ��� ���̸� ŭ ������
		{
			cout << " ";
		}
	}
	m_y++;//�ܾ �Ʒ��� ��ĭ ����

	if (m_y > HEIGHT-2)
	{
		return false;
	}
	else
	{
		draw();
		return true;
	}
}

string Word::WordGet()
{
	return m_word;
}

void Word::Die()
{
	m_DrawInterface.gotoxy(m_x, m_y);//��ǥ�̵�
	for (int i = 0; i < m_word.length(); i++)//�ܾ��� ���̸� ŭ ������
	{
		cout << " ";
	}
}


