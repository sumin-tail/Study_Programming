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

void WordManager::WordClear() //ȭ�鿡 �ִ� ��� ���� Ŭ����
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
	bool item = false;
	if (rand() % 100 < 30) //������ �ܾ� ���� Ȯ�� 10�ۼ�Ʈ
	{
		item = true;
	}
	m_DropList.push_back(new Word(m_WordList[num], x, item));//ȭ�鿡 ����ִ� �ܾ��Ʈ�� �߰�
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
	bool clearword = false;
	bool ALLClear = false;
	Word* remove;
	for (auto& word : m_DropList)
	{
		if (word->WordGet() == text)//�ܾ �����ϸ�
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
			case HIDE: break;
			}
			//if (word->ItemWord()) //���� ������ �ܾ���
			//{
			//	RandomItem();
			//}
			remove = word;
			m_DropList.remove(remove);
			clearword = true;
			break;
		}
	}
	if (ALLClear)
	{
		WordClear();
	}
	return clearword;
}

void WordManager::RandomItem()
{

}

//1.����ӵ� ����
//2.����ӵ� ����
//3.�����Ͻ�����
//4.ȭ�� Ŭ����
//5.���尡����(1.5��)
