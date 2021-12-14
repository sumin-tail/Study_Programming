#pragma once
#include "Mecro.h"
#include "Word.h"

//단어들 관리 Class //단어는 파일입출력으로 가져옴
class WordManager
{
private:
	 string* m_WordList; //단어리스트
	 int m_WordCount;//단어 갯수
	 list<Word*> m_DropList;//현재 화면에서 드롭되는 단어 리스트
public:
	WordManager();
	~WordManager();
	void WordClear();
	void WordCreat();
	bool DropWord();
	bool WordCheck(string text);
};

