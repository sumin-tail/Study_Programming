#pragma once
#include"Mecro.h"
#include"Map.h"

class Player
{
private:
	int m_iplayerx;
	int m_iplayery;
public:
	void PlayerStartDraw(int x, int y);
	void PlayerMove(int x, int y, Map m);
	void PlayerPos();
	void PlayerDraw();
	void Erase();
	Player();
	~Player();
};

