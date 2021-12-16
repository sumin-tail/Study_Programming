#pragma once
#include "Mecro.h"
#include "Word.h"

//�ܾ�� ���� Class //�ܾ�� ������������� ������
class WordManager
{
private:
	 string* m_WordList; //�ܾ��Ʈ
	 int m_WordCount;//�ܾ� ����
	 list<Word*> m_DropList;//���� ȭ�鿡�� ��ӵǴ� �ܾ� ����Ʈ
	 int m_Speed;
public:
	WordManager();
	~WordManager();
	void WordClear();
	void WordCreat();
	bool DropWord();
	bool WordCheck(string text);
	void RandomItem();
	int GetSpeed() { return m_Speed; }
};

