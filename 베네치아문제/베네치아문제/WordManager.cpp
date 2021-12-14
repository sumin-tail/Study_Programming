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
	for(auto& word : m_DropList)//전체 탐색
	{
		delete word;
	}
}

void WordManager::WordClear()
{
	for (auto& word : m_DropList)//전체 탐색
	{
		delete word;
	}
	m_DropList.clear();
}

void WordManager::WordCreat() //단어 생성
{
	int num = rand() % m_WordCount;//단어 선택
	int x = rand() % WIDTHFULL + 2;
	m_DropList.push_back(new Word(m_WordList[num], x));//화면에 살아있는 단어리스트에 추가
}

bool WordManager::DropWord() //단어 드롭
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

bool WordManager::WordCheck(string text) //플레이어가 친 단어가 화면에 존재하는지
{
	Word* remove;
	for (auto& word : m_DropList)
	{
		if (word->WordGet() == text)//단어가 존재하면
		{
			word->Die();
			remove = word;
			m_DropList.remove(remove);
			return true;
		}
	}
	return false;
}
