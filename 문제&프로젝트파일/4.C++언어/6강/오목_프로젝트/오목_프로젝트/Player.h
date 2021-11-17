#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include <list> 

//Player가 필요한 정보를 관리하는 class
//필요 맴버변수 – 돌구조체배열, 돌갯수, 팀이름변수, 돌모양변수 등등..
//필요 맴버함수 – 승리체크함수, 돌놓기함수, 무르기함수, 돌찾기함수 등등..

enum DIRECTION //방향 키
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_UP = 'w',
	DIRECTION_DOWN = 's'
};

typedef struct StoneXY
{
	int x;
	int y;

	StoneXY(int posX, int posY) 
	{
		x = posX;
		y = posY;
	}

}StoneXY;

class Player
{
private:
	string m_strName;//플레이어 이름
	// 게임 첫 시작시 가운데 / 그 이후는 자기가 마지막에 돌을 놓았던 좌표
	int m_ix; //현재 x좌표
	int m_iy; //현재 y좌표

	int m_iundoCount; //무르기 횟수
	MapDraw m_DrawManager;//맵 드로우 함수를 쓰기위해
	string m_strStoneShape;//플레이어 돌 모양 변수
	//돌 놓은 좌표를 기억하는 컨테이너 (스택)>무르기 기능을 위해서
	list<StoneXY> StoneLOG;
public:
	Player(string name, int x, int y, string Shape, int undoCount);
	~Player();
	void ChangeStoneShape(string Shape); //돌모양 변경 함수
	void PosUpdate(int x, int y); //마지막에 돌 놓은곳 갱신
	bool WinCheck(); //승리체크 함수
	bool StoneCheck(int posX, int posY); //돌 체크 함수
	void StoneDrop(int posX, int posY); //돌 두는 함수
	void StoneDrow();
	void Undo(int width,int height);//무르기
	void Undocount();//무르기 횟수 차감
	int WinCheckStoneCount(int count, int posX, int posY, int ChangeX, int ChangeY);

	//반환함수//
	string GetName(); //이름 반환
	string GetStoneShape();//돌모양 반환함수
	int GetXPos(); //x좌표 반환
	int GetYPos(); //y좌표 반환
	int GetUndo();//남은 무르기 횟수 반환
};

