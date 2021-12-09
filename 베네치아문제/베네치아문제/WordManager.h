#pragma once
#include "Mecro.h"
#include "Word.h"

//단어들 관리 Class //단어는 파일입출력으로 가져옴
class WordManager
{
private:
	 vector<Word*> m_WordList;
	 int m_WordCount;

public:
	WordManager();
	~WordManager();
	void WordCreat();
	void DropWord();
	bool WordCheck(string text);
};

