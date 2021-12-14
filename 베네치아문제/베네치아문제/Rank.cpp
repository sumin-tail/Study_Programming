#include "Rank.h"

void Rank::RankSort()
{
	//새롭게 점수가 등록 되었을 때
	ifstream load;
	load.open("Rank.txt");
	if (!load.is_open()) //안열리면 리턴
	{
		return;
	}
	string name;
	int score;
	int stage;

	vector<RankPlayer*> list;

	while (!load.eof())
	{
		load >> name;
		load >> score;
		load >> stage;
		list.push_back(new RankPlayer(name, score, stage));
	}

	load.close();
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
	//m_DrawInterface.DrawMidText("Name          Score          Stage", WIDTH, HEIGHT * 0.3f);//박스 안에 드로우

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
		if (HEIGHT * 0.3f + count * 2 >= HEIGHT-1)
		{
			break;
		}
	}
	load.close();
	_getch();
}
