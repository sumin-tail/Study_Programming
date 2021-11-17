#pragma once
#include "Car.h"

Car::Car()
{
	makeTime = clock();
}

void Car::Drive()
{
	if (clock() - makeTime >= speed)
	{
		posX++;
		PrintCar();
		makeTime = clock();
	}
}

bool Car::EndCheck()
{
	if (posX > END)
	{
		RemoveCar();
		return true;
	}
	return false;
}

void Car::Boster()
{
	if (speed == SPEED_LOW)
	{
		speed = SPEED_FAST;
	}
	else if (speed == SPEED_FAST)
	{
		speed = SPEED_LOW;
	}
}

void Car::PrintCar()
{
	gotoxy(posX, posY);
	cout << "   ¦£¦¡¦¡¦¤   ";
	gotoxy(posX, posY+1);
	cout << " ¦£¦¥¢Æ¢Æ¦¦¦¤ ";
	gotoxy(posX, posY+2);
	cout << " ¦¦¢Á¦¡¦¡¢Á¦¥ ";
}

void Car::RemoveCar()
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(posX, posY+i);
		cout << "              ";
	}

}