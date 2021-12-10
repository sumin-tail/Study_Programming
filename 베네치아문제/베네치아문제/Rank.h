#pragma once
#include "Mecro.h"
#include "Interface.h"

//Rank 시스템 관리 Class
class Rank
{
private:
	Interface m_DrawInterface;//드로우
public:
	void RankSort();
	void RankPrint();
};

