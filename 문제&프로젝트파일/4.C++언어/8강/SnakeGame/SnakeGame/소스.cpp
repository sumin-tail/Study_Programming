#pragma once
#include "Game.h"
#include "Macro.h"

//상수 디파인 하기!!
//enum 쓰기

//-조건
//하트는 최대 10개 까지만 생성이되고 생성되는 시간은 동일/게임 시작했을때부터 생성 시작
//몸이 길어질수록 빨라짐
//벽은 랜덤 생성(갯수는 지정-35개 정도) 
//뱀은 자기 몸에 닿아도 죽음

void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	Game startGame;
	startGame.Menu();

}
