#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"Player.h"

#define BLACKTEAMICON "○"
#define WHITETEAMICON "●"

//열거형을 이용해서 옵션 선택 관리
enum OPTIONMENU
{
	OPTIONMENU_MAPSIZE = 1,
	OPTIONMENU_CURSOR,
	OPTIONMENU_STONE,
	OPTIONMENU_UNDO,
	OPTIONMENU_RETURN
};

enum LOBBYMENU
{
	LOBBYMENU_START = 1,
	LOBBYMENU_OPTION,
	LOBBYMENU_EXIT
};

enum PLAYERTYPE
{
	PLAYERTYPE_WHITE,
	PLAYERTYPE_BLACK,
	PLAYERTYPE_END
};

class GameManager
{
private:
	int m_iTurn; //턴수
	int m_iWidth; //가로
	int m_iHeight; //세로
	bool m_bPlayState; //플레이 중인지 아닌지 체크
	MapDraw m_DrawManager; //맵 드로우 
	Player m_Player[PLAYERTYPE_END]; //플레이어 배열
public:
	void SetMapSize();
	void CurPlayerInfoDraw();
	void InputInfoDraw();
	void SetName(string str,PLAYERTYPE type, int x, int y);
	void DrawPoint();
	void Input();
	void GameStart();
	void SetUndo();
	void Option();
	void SetCursor();
	void SetStone();
	void LobbyDraw();
	void GameMain();
	GameManager();
	~GameManager();
};

