#include "WordManager.h"

WordManager::WordManager()
{
	ifstream load;
	string str;
	load.open("Word.txt");
	load >> m_WordCount;
	m_WordList = new string[m_WordCount];
	int count = 0;
	while (!load.eof())
	{
		load >> str;
		m_WordList[count++] = str;
	}
}

WordManager::~WordManager()
{
	delete[] m_WordList;
	for(auto& word : m_DropList)//��ü Ž��
	{
		delete word;
	}
}

void WordManager::WordCreat() //�ܾ� ����
{
	int num = rand() % m_WordCount;//�ܾ� ����
	int x = rand() % WIDTHFULL + 2;
	m_DropList.push_back(new Word(m_WordList[num], x));//ȭ�鿡 ����ִ� �ܾ��Ʈ�� �߰�
}

void WordManager::DropWord() //�ܾ� ���
{
	for (auto& word : m_DropList)
	{
		word->drop();
		word->draw();
	}
}

bool WordManager::WordCheck(string text) //�÷��̾ ģ �ܾ ȭ�鿡 �����ϴ���
{
	for (auto& word : m_DropList)
	{
		if (word->WordGet() == text)
		{
			return true;
		}
	}
	return false;
}
