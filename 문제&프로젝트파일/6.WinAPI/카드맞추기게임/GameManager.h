#pragma once
#include <time.h>
#include <vector>
#include "Card.h"
#include "BitMapManager.h"
#include "BitMap.h"

#define WAITTIME 500

enum GAME //���� ����
{
	GAME_MAIN, //����
	GAME_PLAY, //�÷��̻���
	GAME_PAUSE, //�Ͻ���������(Ŭ���Ұ�)
	GAME_END //���� ����
};

class GameManager //�̱���
{
private:
	static GameManager* m_hThis; 
	BitMap* m_BackGround; //��� �̹���
	int m_WindowWidth; //���� ������
	int m_WindowHeight; //���� ������
	Card* m_CardList; //ī�� ����Ʈ
	int m_count; //���� ī�� ��
	std::vector<int> m_CardSelect; //�÷��̾ ������ ī�� 
	GAME m_GameState; //���� ����
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
	void Draw(HDC hdc); //���� ȭ�� ��ο�� ����ȭ�� ��ο츦 ��� - ���߿� ����ġ�� ����
	void ColliderCheck(HWND hWnd, POINT Point); //���ӽ��� �ݶ��̴� üũ�� ī�� �ݶ��̴� üũ�� - ���߿� ����ġ�� ����
	void MainDraw(HDC hdc);
	void GameStart(HWND hWnd, POINT Point);
	void BackGroundDraw(HDC hdc);
	void CardSetting();
	void CardDraw(HDC hdc);
	void CardColliderCheck(HWND hWnd,POINT Point);
	void CardSelect(HWND hWnd, POINT Point);//ī�� ����
	void CardMatch(HWND hWnd);// ī���� ¦�� �´��� üũ
	bool Pause();
	void Reset();
	~GameManager();
};

