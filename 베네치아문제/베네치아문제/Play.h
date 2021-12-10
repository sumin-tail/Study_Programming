#pragma once
#include "Mecro.h"
#include "WordManager.h"
#include "Interface.h"
#include "Rank.h"

#define SPEED 1000

//��ü ���� �帧 ���� Class
//�̸����̴� 10���� ���Ϸ� = 10���ڱ����� oK
class Play
{
private:
	string m_name; //�÷��̾� �̸�
	int m_score; //�÷��̾� ���ھ�
	int m_life; //�÷��̾� ������
	Interface m_DrawInterface;//�� ��ο�
	WordManager m_WordList; //ȭ�鿡 �ִ� �ܾ������
	Rank m_Rank;
	int m_Drawtime;
	int m_MakeTime;
public:
	Play();
	~Play();
	void MainMenu();
	void PlayerDraw();
	void DrawAll();
	void Intro();
	void NameSetting();
	bool Typing(int textsize, string& text);
	void GamePlay();
	void StagePrint(int stage);
	void Update();
};

