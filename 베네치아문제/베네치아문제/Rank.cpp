#include "Rank.h"
#include <algorithm>

//��ŷ ����
void Rank::RankSort(string name, int score, int stage)
{
	//���Ӱ� ������ ��� �Ǿ��� ��
	ifstream load;
	load.open("Rank.txt");
	if (!load.is_open()) //�ȿ����� ����
	{
		return;
	}
	
	vector<RankPlayer*> list;
	list.push_back(new RankPlayer(name, score, stage));
	while (!load.eof())
	{
		load >> name;
		load >> score;
		load >> stage;
		list.push_back(new RankPlayer(name, score, stage));
	}
	load.close();

	//std::sort(list.begin(), list.end(), ���ǽ�);
	//��ŷ ����
	for (int i = 0; i < list.size()-1; i++)
	{
		for (int j = i + 1; j < list.size(); j++)
		{
			if (list[i]->score < list[j]->score)
			{
				RankPlayer* temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}

	//���̺�
	ofstream save;
	save.open("Rank.txt");
	if (save.is_open())
	{
		int i = 0;
		for (; i < list.size()-1; i++)
		{
			save << list[i]->name << " " << list[i]->score << " " << list[i]->stage << endl;
		}
		save << list[i]->name << " " << list[i]->score << " " << list[i]->stage; //������ ��ŷ�� ���� ����
	}
	save.close();

	for (auto& RankPlayer : list)//��ü Ž��
	{
		delete RankPlayer;
	}
}

//��ŷ ���
void Rank::RankPrint()
{
	system("cls");
	m_DrawInterface.BoxDraw(WIDTH, HEIGHT);
	m_DrawInterface.BoxDrawPos(WIDTH * 0.3f, 5, HEIGHT * 0.1f);//���� �ڽ�
	BLUE
	m_DrawInterface.DrawMidText("Ranking", WIDTH, HEIGHT * 0.1f + 2);//�ڽ� �ȿ� ��ο�
	m_DrawInterface.gotoxy(2, HEIGHT * 0.3f-1);
	for (int i = 2; i < WIDTH*2 - 2; i++)
	{
		cout << "=";
	}
	m_DrawInterface.TextDraw("Name", WIDTH * 0.5f, HEIGHT * 0.3f);
	m_DrawInterface.TextDraw("Score", WIDTH * 1.0f, HEIGHT * 0.3f);
	m_DrawInterface.TextDraw("Stage", WIDTH * 1.5f, HEIGHT * 0.3f);

	ifstream load;
	load.open("Rank.txt");
	if (!load.is_open()) //�ȿ����� ����
	{
		return;
	}

	string name;
	int score;
	int stage;
	int count=1;

	while (!load.eof())
	{
		load >> name;
		load >> score;
		load >> stage;
		m_DrawInterface.TextDraw(name, WIDTH * 0.5f, HEIGHT * 0.3f+count*2);
		m_DrawInterface.TextDraw(to_string(score), WIDTH * 1.0f, HEIGHT * 0.3f+ count*2);
		m_DrawInterface.TextDraw(to_string(stage), WIDTH * 1.5f, HEIGHT * 0.3f+ count*2);
		count++;
		// ���� �������� ����.
		if (HEIGHT * 0.3f + count * 2 >= HEIGHT-1) //���� �������� ����ϰ� �극��ũ
		{
			break;
		}
	}
	load.close();
	_getch();
}
