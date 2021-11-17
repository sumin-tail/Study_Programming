#pragma once
#include "Macro.h"

//여러가지 블록을 만드는 Class
//맴버 변수 - 블록의상태(벽, 먹이, 뱀머리, 뱀꼬리…),x, y…
//맴버 함수 - 블록충돌체크, 좌표설정, 블럭그리기, 모든블럭지우기,
//특정블럭지우기, 블럭셋팅하기…

class Block
{
	string food ="♡";
	string snakeHead="◎";
	string snakeBody = "○";
public:
	void WallDraw();//벽 드로우
	void DrawPoint(string str, int x, int y); //해당 좌표 드로우
	void ErasePoint(int x, int y);//해당 좌표 지움
	void DrawMidText(string str, int x, int y);//텍스트 중앙출력

	//드로우 함수
	void DrawFood(Pos pos);
	void DrawWall(Pos pos);
	void DrawSnakeHead(Pos pos);
	void DrawSnakeBody(Pos pos);
};

