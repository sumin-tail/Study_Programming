#pragma once
#include "GameManager.h"

void main()
{
	system("mode con: cols=60 lines=35"); //�ܼ�â ������ ����
	GameManager play;
	play.MainMenu();
}