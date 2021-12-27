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
	 int m_Speed; //�ܾ� ��ӿ� �߰������� ���� �Ǵ� +���ǵ�
	 int m_ItemTime;
	 bool m_ItemUse;
	 bool m_Mosaic;
public:
	WordManager();
	~WordManager();
	void WordClear();
	void WordCreat();
	void ItemCheck();
	bool DropWord();
	bool WordCheck(string text);
	int GetSpeed() { return m_Speed; }
};

