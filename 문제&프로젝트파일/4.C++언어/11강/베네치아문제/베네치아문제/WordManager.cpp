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
	m_ItemUse = false;
	m_Mosaic = false;
}

WordManager::~WordManager()
{
	delete[] m_WordList;
	for(auto& word : m_DropList)//전체 탐색
	{
		delete word;
	}
}

void WordManager::WordClear() //화면에 있는 모든 워드 클리어
{
	for (auto& word : m_DropList)//전체 탐색
	{
		word->Die();
		delete word;
	}
	m_DropList.clear();
}

void WordManager::WordCreat() //단어 생성
{
	int num = rand() % m_WordCount;//단어 선택
	int x = rand() % WIDTHFULL + 2;
	bool item = false;
	if (rand() % 100 < 10) //아이템 단어 생성 확률 10퍼센트
	{
		item = true;
	}
	m_DropList.push_back(new Word(m_WordList[num], x, item));//화면에 살아있는 단어리스트에 추가
}

void WordManager::ItemCheck()
{
	if (clock() - m_ItemTime > 3000 && m_ItemUse)
	{
		if (m_Speed != 0)
		{
			m_Speed = 0;
		}
		else
		{
			m_Mosaic = false;
		}
	}
}

bool WordManager::DropWord() //단어 드롭
{
	bool out = false;
	Word* remove;
	for (auto& word : m_DropList)
	{
		if (!word->drop(m_Mosaic))
		{
			remove = word;
			out = true;
		}
	}

	if(out) m_DropList.remove(remove);

	return out;
}

bool WordManager::WordCheck(string text) //플레이어가 친 단어가 화면에 존재하는지
{
	bool clearword = false;
	bool ALLClear = false;
	Word* remove;
	for (auto& word : m_DropList)
	{
		if (word->WordGet() == text)//단어가 존재하면
		{
			word->Die();
			switch (word->ItemWord())
			{
			case SLOW: m_Speed = 500;
				break;
			case FAST: m_Speed = -500; 
				break;
			case STOP: m_Speed = 100000; break;
			case CLEAR: ALLClear = true; break;
			case HIDE: m_Mosaic = true; break;
			}

			m_ItemTime = clock();
			remove = word;
			m_DropList.remove(remove);
			clearword = true;
			m_ItemUse = true;
			break;
		}
	}

	if (ALLClear)
	{
		WordClear();
	}

	return clearword;
}


//1.워드속도 증가
//2.워드속도 감소
//3.워드일시정지
//4.화면 클리어
//5.워드가리기(1.5초)
