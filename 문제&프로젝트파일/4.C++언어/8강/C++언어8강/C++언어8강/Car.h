#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<conio.h> //getch
using namespace std;

#define END 100
#define STARTPOS 10

enum SPEED
{
	SPEED_LOW = 200,
	SPEED_FAST = 50
};

class Car
{
	int posX = STARTPOS;
	int posY = STARTPOS;
	int speed = SPEED_LOW;
	int makeTime;

   public:
	   Car();
	   void Drive();
	   bool EndCheck();
	   void Boster();

	   void PrintCar();
	   void RemoveCar();

	   void gotoxy(int x, int y)
	   {
		   COORD Pos = { x, y };
		   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	   }
};

