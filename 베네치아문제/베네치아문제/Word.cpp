#include "Word.h"

Word::Word(string word, int x, bool item) : m_word(word), m_y(1), m_x(x), m_hide(false), m_type(NORMAL)
{
	int wordlegth = x + word.length();
	if (item)
	{
		m_type = (ITEMTYPE)((rand() % HIDE)+1);
	}
	if (wordlegth >= WIDTHFULL-2)
	{
		//특수문자 크기는 2
		int pos = wordlegth - (WIDTHFULL - 2);
		m_x = x - pos;
	}
}


Word::Word() :
	m_x(0),
	m_y(0), m_hide(false), m_type(NORMAL)
{}

void Word::draw(bool mosaic)
{
	//작은 상자 시작좌표 x = 46 , y= 21부터 y는 5칸 x는 38칸
    //x 46 ~ 84 y 21~ 26
	if ((m_y >= 21 && m_y <=25) && ((m_x >= 46 && m_x <= 84) || (m_x <= 46 && m_x + m_word.length() >= 46)))
	{
		m_hide = true;
		return;
	}
	m_hide = false;

	switch (m_type)
	{
	case NORMAL: BLUE
		break;
	default: PUPPLE
		break;
	}

	string str = m_word;
	if (mosaic)
	{
		str = "";
		//m_DrawInterface.gotoxy(m_x, m_y);//좌표이동
		for (int i = 0; i < m_word.length(); i++)//단어의 길이만큼 모자이크 처리
		{
			str += "=";
		}
	}
	m_DrawInterface.TextDraw(str, m_x, m_y);
	ORIGINAL
}

bool Word::drop(bool mosaic)
{
	if (!m_hide)
	{
		Die();
		//m_DrawInterface.gotoxy(m_x, m_y);//좌표이동
		//for (int i = 0; i < m_word.length(); i++)//단어의 길이만 큼 지워줌
		//{
		//	cout << " ";
		//}
	}
	m_y++;//단어를 아래로 한칸 내림

	if (m_y > HEIGHT-2)
	{
		return false;
	}
	else
	{
		draw(mosaic);
		return true;
	}
}

string Word::WordGet()
{
	return m_word;
}

ITEMTYPE Word::ItemWord()
{
	return m_type;
}

void Word::Die()
{
	m_DrawInterface.gotoxy(m_x, m_y);//좌표이동
	for (int i = 0; i < m_word.length(); i++)//단어의 길이만 큼 지워줌
	{
		cout << " ";
	}
}


