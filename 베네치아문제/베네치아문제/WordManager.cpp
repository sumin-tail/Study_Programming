#include "WordManager.h"

WordManager::WordManager()
{
	ifstream load;
	string str;
	load.open("Word.txt");
	load >> m_WordCount;
	while (!load.eof())
	{
		load >> str;
		m_WordList.push_back(new Word(str));
	}

}

WordManager::~WordManager()
{
	while (!m_WordList.empty())
	{
		delete [] &m_WordList;
	}
}

void WordManager::WordCreat()
{
	int num = rand() % m_WordCount;
	int num2 = rand() % (WIDTH*2) + 1;
	while (m_WordList[num]->Live())
	{
		num = rand() % m_WordCount;
	}
	m_WordList[num]->XPosset(num2);
	m_WordList[num]->drop();
}

void WordManager::DropWord()
{
	for (int i = 0; i < m_WordCount; i++)
	{
		if (m_WordList[i]->Live())
		{
			m_WordList[i]->drop();
		}
	}
}

bool WordManager::WordCheck(string text)
{
	for (int i = 0; i < m_WordCount; i++)
	{
		if (m_WordList[i]->Live()&&m_WordList[i]->Die(text))
		{
			return true;
		}
	}

	return false;
}
