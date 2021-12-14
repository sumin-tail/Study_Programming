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

void WordManager::WordClear()
{
	for (auto& word : m_DropList)//��ü Ž��
	{
		delete word;
	}
	m_DropList.clear();
}

void WordManager::WordCreat() //�ܾ� ����
{
	int num = rand() % m_WordCount;//�ܾ� ����
	int x = rand() % WIDTHFULL + 2;
	m_DropList.push_back(new Word(m_WordList[num], x));//ȭ�鿡 ����ִ� �ܾ��Ʈ�� �߰�
}

bool WordManager::DropWord() //�ܾ� ���
{
	bool out = false;
	Word* remove;
	for (auto& word : m_DropList)
	{
		if (!word->drop())
		{
			remove = word;
			out = true;
		}
	}
	m_DropList.remove(remove);
	return out;
}

bool WordManager::WordCheck(string text) //�÷��̾ ģ �ܾ ȭ�鿡 �����ϴ���
{
	Word* remove;
	for (auto& word : m_DropList)
	{
		if (word->WordGet() == text)//�ܾ �����ϸ�
		{
			word->Die();
			remove = word;
			m_DropList.remove(remove);
			return true;
		}
	}
	return false;
}
