#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"Player.h"

#define BLACKTEAMICON "��"
#define WHITETEAMICON "��"

//�������� �̿��ؼ� �ɼ� ���� ����
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
	int m_iTurn; //�ϼ�
	int m_iWidth; //����
	int m_iHeight; //����
	bool m_bPlayState; //�÷��� ������ �ƴ��� üũ
	MapDraw m_DrawManager; //�� ��ο� 
	Player m_Player[PLAYERTYPE_END]; //�÷��̾� �迭
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

