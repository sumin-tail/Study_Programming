#pragma once
#include "Mecro.h"
#include "Interface.h"

//단어 Class , 필요 맴버 변수 x,y,string 필요 맴버함수 draw drop Live Die
class Word
{
private:
	Interface m_DrawInterface;
	int m_x;
	int m_y;
	string m_word;
public:
	Word(string word);
	void draw();
	void drop();
};

