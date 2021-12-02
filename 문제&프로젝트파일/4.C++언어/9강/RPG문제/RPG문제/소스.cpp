#pragma once
#include "GameManager.h"

void main()
{
	system("mode con: cols=60 lines=35"); //콘솔창 사이즈 설정
	GameManager play;
	play.MainMenu();
}