#pragma once
#include "MainMenu.h"
#include "BitMap.h"
#include "Player.h"
#include "BackGround.h"
#include "Interface.h"
#include "Fire.h"
#include "Ring.h"
#include <List>

//세로 500 가로 1000

enum GAME //게임 상태
{
	GAME_MAIN, //메인 화면
	GAME_PLAY, //플레이 상태
	GAME_PAUSE, // 일시정지 상태
	GAME_CLEAR, // 게임 클리어
};


//게임 매니저 - 싱글톤으로 제작
//인터페이스 출력 순서는 백그라운드 -> 장애물 -> 링뒤쪽 -> 플레이어 -> 링 앞쪽 -> UI 순
class GameManager
{
private:
	static GameManager* m_hThis;//싱글톤
	GAME m_GameState; //게임 상태
	int m_score;//스코어
	int m_bonus;//보너스 - 시간당 감소
	MainMenu m_MainMenu; //메인 메뉴 출력용
	Player m_Player; //플레이어를 담을 변수
	BackGround m_BackGround; //백그라운드
	Interface m_Interface;//인터페이스
	Fire m_Fire; //불꽃
	Ring* m_Ring[2];//링 넣을 배열
	int m_WindowWidth; //윈도우 가로사이즈(캡선-흰색- 포함)
	int m_WindowHeight; //윈도우 세로사이즈
	int m_WindowScreenWidth; //윈도우 화면 가로사이즈(캡선미포함)
	int m_WindowScreenHeight; //윈도우 화면 세로사이즈
	HWND m_hWnd;//윈도우 핸들
	HDC m_hdc;//h dc 
	HDC m_backDC;//back dc 
	HFONT m_font;//폰트 
	HFONT m_oldfont;//폰트 
	float m_Pausetimer;
public:
	static GameManager* GetInstance()
	{
		if (m_hThis == NULL)
			m_hThis = new GameManager;
		return m_hThis;
	}
	GameManager();
	~GameManager();
	void Init(HWND hWnd);
	void Draw();//더블버퍼 이용
	void Update(float elapsed);//업데이트
	void Reset();
	void ScoreUP(int score);
	HBITMAP CreateDIBSectionRe(HDC hdc, int width, int height);
};

