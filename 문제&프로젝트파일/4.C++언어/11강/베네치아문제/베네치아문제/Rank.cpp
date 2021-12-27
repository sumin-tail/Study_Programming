#include "Rank.h"
#include <algorithm>

//랭킹 정렬
void Rank::RankSort(string name, int score, int stage)
{
	//새롭게 점수가 등록 되었을 때
	ifstream load;
	load.open("Rank.txt");
	if (!load.is_open()) //안열리면 리턴
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

	//std::sort(list.begin(), list.end(), 조건식);
	//랭킹 정렬
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

	//세이브
	ofstream save;
	save.open("Rank.txt");
	if (save.is_open())
	{
		int i = 0;
		for (; i < list.size()-1; i++)
		{
			save << list[i]->name << " " << list[i]->score << " " << list[i]->stage << endl;
		}
		save << list[i]->name << " " << list[i]->score << " " << list[i]->stage; //마지막 랭킹은 엔터 없이
	}
	save.close();

	for (auto& RankPlayer : list)//전체 탐색
	{
		delete RankPlayer;
	}
}

//랭킹 출력
void Rank::RankPrint()
{
	system("cls");
	m_DrawInterface.BoxDraw(WIDTH, HEIGHT);
	m_DrawInterface.BoxDrawPos(WIDTH * 0.3f, 5, HEIGHT * 0.1f);//작은 박스
	BLUE
	m_DrawInterface.DrawMidText("Ranking", WIDTH, HEIGHT * 0.1f + 2);//박스 안에 드로우
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
	if (!load.is_open()) //안열리면 리턴
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
		// 개수 조건으로 수정.
		if (HEIGHT * 0.3f + count * 2 >= HEIGHT-1) //일정 순위까지 출력하고 브레이크
		{
			break;
		}
	}
	load.close();
	_getch();
}
