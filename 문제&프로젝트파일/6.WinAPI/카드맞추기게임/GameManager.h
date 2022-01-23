#pragma once
#include <time.h>
#include <vector>
#include "Card.h"
#include "BitMapManager.h"
#include "BitMap.h"

#define WAITTIME 500

enum GAME //게임 상태
{
	GAME_MAIN, //메인
	GAME_PLAY, //플레이상태
	GAME_PAUSE, //일시정지상태(클릭불가)
	GAME_END //게임 종료
};

class GameManager //싱글톤
{
private:
	static GameManager* m_hThis; 
	BitMap* m_BackGround; //배경 이미지
	int m_WindowWidth; //가로 사이즈
	int m_WindowHeight; //세로 사이즈
	Card* m_CardList; //카드 리스트
	int m_count; //맞춘 카드 쌍
	std::vector<int> m_CardSelect; //플레이어가 선택한 카드 
	GAME m_GameState; //게임 상태
	int m_waitclock;
public:
	static GameManager* GetInstance()
	{
		if (m_hThis == NULL)
			m_hThis = new GameManager;
		return m_hThis;
	}
	GameManager();
	void Init(HWND hWnd);
	void Draw(HDC hdc); //메인 화면 드로우와 게임화면 드로우를 담당 - 나중에 스위치로 구현
	void ColliderCheck(HWND hWnd, POINT Point); //게임시작 콜라이더 체크와 카드 콜라이더 체크용 - 나중에 스위치로 구현
	void MainDraw(HDC hdc);
	void GameStart(HWND hWnd, POINT Point);
	void BackGroundDraw(HDC hdc);
	void CardSetting();
	void CardDraw(HDC hdc);
	void CardColliderCheck(HWND hWnd,POINT Point);
	void CardSelect(HWND hWnd, POINT Point);//카드 선택
	void CardMatch(HWND hWnd);// 카드의 짝이 맞는지 체크
	bool Pause();
	void Reset();
	~GameManager();
};

