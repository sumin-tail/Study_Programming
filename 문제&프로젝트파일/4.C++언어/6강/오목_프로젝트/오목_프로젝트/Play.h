#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"Player.h"

#define ENTER 13
#define ESC 27

enum OPTION //옵션 키
{
	OPTION_UNDO = 'n',
	OPTION_KEY = 'p',
};

//전체 Play상태를 관리하는 class
//필요 맴버변수 – DrawManager, Player, 맵가로크기, 맵세로크기, 턴수, 커서 등등..
//필요 맴버함수 – Init, Reset, Playing, Input등등..

class Play
{
private:
	//기본//
	int m_iWidth;//가로
	int m_iHeight;//세로
	MapDraw m_DrawManager;//맵 드로우 클래스 함수 사용하기 위해

	//옵션//
	int m_iCursor; //커서 모양 번호
	int m_iStone; //돌 모양 번호
	string m_strStoneShape[4][2] = { {"○", "●"} , {"♡", "♥"}, { "☏","☎" }, { "①","②" } };	//바둑 돌 모양 모음
	string m_strCursorShape[4][2] = { {"○", "●"} , {"♡", "♥"}, { "☞","☜" }, { "①","②" } }; //커서 모양 모음

	//게임 플레이
	int m_iTurn; //턴수
	Player* m_Player[2]; //플레이어 1P/2P 담을 배열
	bool m_bPlayCheck; //게임 플레이 체크
	int m_iUndoCount; //무르기 횟수

public:
	//--메인메뉴--//
	void MenuScreen(); //메인메뉴 씬

	//--옵션--//
	void SettingScreen(); //설정 씬
	void MapSizeChange();//맵사이즈 변경 
	void ShapeChange(int *shapeTarget); //커서/돌 모양 변경
	void UndoCount(); //무르기 옵션 변경
	void Warning();//게임 플레이중 설정 변경 불가능 창

	//--게임 플레이--//
	void Init(); //초기화
	void Playing(); //게임 플레이
	void PlayerSet(); //플레이어 생성
	void ControlGuide(int turn); //조작가이드
	void Movement(int *pos, int value,int x, int y);
	void AllPrint(int x, int y);

	Play();
	~Play();
};
