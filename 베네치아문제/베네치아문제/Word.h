#pragma once
#include "Mecro.h"
#include "Interface.h"

//�ܾ� Class , �ʿ� �ɹ� ���� x,y,string �ʿ� �ɹ��Լ� draw drop Live Die
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

