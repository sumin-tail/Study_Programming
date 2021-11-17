#pragma once
#include "Macro.h"
#include "Block.h"

#define DEFAULT_SPEED 300 //디폴트 스피드

enum DIRECTION //방향 키
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_UP = 'w',
	DIRECTION_DOWN = 's',
};


//뱀의 전체적인 정보를 관리하는 Class
//맴버 변수 - Life정보변수, 방향상태변수, 머리 와 꼬리관리변수, 시간관리변수…
//맴버 함수 – 뱀설정, 꼬리만들기, 꼬리이동, 머리이동, 뱀그리기, 입력, 뱀삭제…

class Snake
{
	int snakeMakeTime; //만들어진 시간
	int direction;// 방향
    int length; //몸길이
    int speed; //속도 
	vector<Pos> snakePosList; //뱀 몸통 좌표
	Pos snakeTail;//뱀꼬리좌표
	Block blockManager;

public:
	Snake();
	void SnakeMoveCheck();
	void Move();
	void MakeBody(int x, int y);
	void PrintSnakeStart();
	void EatFood();//몸통길이늘어남

	//=반환 함수=//
	bool SnakeBodyCheck(int x, int y);//맵 몸통 체크
	Pos GetSnakeHead();
	//=설정 함수=//
	void SetSpeed();
};