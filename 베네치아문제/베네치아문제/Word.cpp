#include "Word.h"

Word::Word(string word)
{
	m_word = word;
	m_x = 0;
	m_y = 0;
}

void Word::draw()
{
	BLUE
	m_DrawInterface.TextDraw(m_word, m_x, m_y);
}

void Word::drop()
{
	if (!Live()) return;
	m_DrawInterface.gotoxy(m_x, m_y);
	if (m_y != 0)
	{
		for (int i = 0; i < m_word.size(); i++)
		{
			cout << " ";
		}
	}
	m_y++;
	if (!Live())	return;
	draw();
}

void Word::XPosset(int x)
{
	m_x = x;
	if (x + m_word.size() >= WIDTH*2)
	{
		m_x -= m_word.size();
	}
}

bool Word::Live()
{
	if (m_x == 0)
	{
		return false;
	}

	if (m_y >= HEIGHT - 1)
	{
		m_x = 0;
		m_y = 0;
		return false;
	}
	return true;
}

bool Word::Die(string text)
{
	if (text == m_word)
	{
		m_DrawInterface.gotoxy(m_x, m_y);
		if (m_y != 0)
		{
			for (int i = 0; i < m_word.size(); i++)
			{
				cout << " ";
			}
		}
		m_x = 0;
		m_y = 0;
		return true;
	}
	return false;
}
