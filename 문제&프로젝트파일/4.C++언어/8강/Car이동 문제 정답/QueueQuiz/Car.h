#pragma once
#include<Windows.h>
#include<string>
#include<iostream>
#include<time.h>
#include<conio.h>
using namespace std;
#define SPACE 32
#define CARSPEED 200
#define FASTSPEED 50
#define TIME 1000
#define MAX_WIDTH 100

enum STATUS
{
	STATUS_MOVE,
	STATUS_STAY,
	STATUS_END,
};

enum MOVEMODE
{
	MOVEMODE_NORMAL,
	MOVEMODE_FAST
};

class Car
{
private:
	int m_iSpeedValue;
	int m_iMyNumber;
	int m_iStayTime;
	STATUS m_eStatus;
	MOVEMODE m_eSpeedType;
	int m_iMoveSpeedTime;
	int m_ix;
	int m_iSec;
	void DrawCar();
	Car* Next;
public:
	void EraseCar();
	inline Car* GetNext()
	{
		return Next;
	}
	inline void SetNext(Car* next)
	{
		Next = next;
	}
	void EraseTime();
	void DrawTime();
	void ChangeStatus();
	void Move();
	void ChangeSpeed();
	inline bool DeququqCheck()
	{
		if (m_ix >= MAX_WIDTH)
			return true;
		else
			return false;
	}
	void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	Car();
	~Car();
};

