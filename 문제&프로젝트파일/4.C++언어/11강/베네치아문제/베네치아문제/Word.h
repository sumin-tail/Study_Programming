#pragma once
#include "Mecro.h"
#include "Interface.h"

enum ITEMTYPE
{
	NORMAL,
	SLOW,
	FAST,
	STOP,
	CLEAR,
	HIDE
};

//단어 Class
class Word
{
private:
	Interface m_DrawInterface;
	int m_x;
	int m_y;
	string m_word;//단어
	bool m_hide;//하이드 체크
	ITEMTYPE m_type;
public:
	Word(string word, int x, bool item);
	Word();
	void draw(bool mosaic);
	bool drop(bool mosaic);
	void Die();
	string WordGet();
	ITEMTYPE ItemWord();
};

