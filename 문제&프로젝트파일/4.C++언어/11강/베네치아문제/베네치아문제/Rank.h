#pragma once
#include "Mecro.h"
#include "Interface.h"

struct RankPlayer
{
	string name;
	int score;
	int stage;

	RankPlayer(string loadname, int loadscore, int loadstage)
	{
		name = loadname;
		score = loadscore;
		stage = loadstage;
	}
};

//Rank �ý��� ���� Class
class Rank
{
private:
	Interface m_DrawInterface;//��ο�
public:
	void RankSort(string name, int score, int stage);
	void RankPrint();
};

