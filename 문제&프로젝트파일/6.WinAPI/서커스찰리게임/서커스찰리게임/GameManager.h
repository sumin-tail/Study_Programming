#pragma once
#include "MainMenu.h"
#include "BitMap.h"
#include "Player.h"
#include "BackGround.h"
#include "Interface.h"
#include "Fire.h"
#include "Ring.h"
#include <List>

//���� 500 ���� 1000

enum GAME //���� ����
{
	GAME_MAIN, //���� ȭ��
	GAME_PLAY, //�÷��� ����
	GAME_PAUSE, // �Ͻ����� ����
	GAME_CLEAR, // ���� Ŭ����
};


//���� �Ŵ��� - �̱������� ����
//�������̽� ��� ������ ��׶��� -> ��ֹ� -> ������ -> �÷��̾� -> �� ���� -> UI ��
class GameManager
{
private:
	static GameManager* m_hThis;//�̱���
	GAME m_GameState; //���� ����
	int m_score;//���ھ�
	int m_bonus;//���ʽ� - �ð��� ����
	MainMenu m_MainMenu; //���� �޴� ��¿�
	Player m_Player; //�÷��̾ ���� ����
	BackGround m_BackGround; //��׶���
	Interface m_Interface;//�������̽�
	Fire m_Fire; //�Ҳ�
	Ring* m_Ring[2];//�� ���� �迭
	int m_WindowWidth; //������ ���λ�����(ĸ��-���- ����)
	int m_WindowHeight; //������ ���λ�����
	int m_WindowScreenWidth; //������ ȭ�� ���λ�����(ĸ��������)
	int m_WindowScreenHeight; //������ ȭ�� ���λ�����
	HWND m_hWnd;//������ �ڵ�
	HDC m_hdc;//h dc 
	HDC m_backDC;//back dc 
	HFONT m_font;//��Ʈ 
	HFONT m_oldfont;//��Ʈ 
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
	void Draw();//������� �̿�
	void Update(float elapsed);//������Ʈ
	void Reset();
	void ScoreUP(int score);
	HBITMAP CreateDIBSectionRe(HDC hdc, int width, int height);
};

