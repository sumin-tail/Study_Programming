#pragma once
#include "Macro.h"
#include "Snake.h"
#include "Block.h"

#define MAKEFOOD 1000
#define MAX_WALL 35

//전체 Game을 관리하는 Class

class Game
{
	int PlayStartTime;//시간관리용 변수
	int score;//점수
	list<Pos> wallList;//벽 블럭배열
	list<Pos> foodList;//먹이 블럭배열
	Snake* player; //뱀
	Block blockManager; //맵 및 블록 드로우를 위한 blockManager
public:
	Game();
	void Menu();//메뉴
	void PrintScore(); //스코어 출력

	//-게임-//
	void PlaySetting(); //게임 시작 전 세팅
	void PlayGame(); //게임 플레이
	void Update(); //업데이트 함수
	void GameOver(); //게임 오버
	void ResetGame(); //게임 끝나고 할당했던것들 처리/변수 초기화
	void MakeFood();//음식 만드는 함수
	void MakeWall();//벽 만드는 함수
	void ListErase(list<Pos> *blocklist, int x, int y);//리스트 원소 제거
	bool BlockCheck(list<Pos> blocklist, int x, int y);//블럭체크
	bool GameOverCheck();//게임오버 체크
	void SnakeFoodCheck();//음식 먹었는지 확인
};

