#pragma once
#include "Mecro.h"
#include "Word.h"

//�ܾ�� ���� Class //�ܾ�� ������������� ������
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

