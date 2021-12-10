#include "Word.h"

Word::Word(string word, int x) : m_word(word), m_y(1), m_x(x)
{
	int a = x + word.length();
	if (a >= WIDTHFULL-2)
	{
		//특수문자 크기는 2
		int pos = a - (WIDTHFULL - 2);
		m_x = x - pos;
	}
	draw();//만들자 마자 화면에 그려줌
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
	m_DrawInterface.gotoxy(m_x, m_y);//좌표이동
	for (int i = 0; i < m_word.length(); i++)//단어의 길이만 큼 지워줌
	{
		cout << " ";
	}
	m_y++;//단어를 아래로 한칸 내림

}

string Word::WordGet()
{
	return m_word;
}

bool Word::Die(string text)
{
	return false;
}
