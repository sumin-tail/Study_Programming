#pragma once
#include "Mecro.h"
#include "Interface.h"

//´Ü¾î Class
class Word
{
private:
	Interface m_DrawInterface;
	int m_x;
	int m_y;
	string m_word;
public:
	Word(string word, int x);
	Word();
	void draw();
	void drop();
	bool Die(string text);
	string WordGet();
};

