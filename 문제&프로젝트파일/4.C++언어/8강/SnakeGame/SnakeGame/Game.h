#pragma once
#include "Macro.h"
#include "Snake.h"
#include "Block.h"

#define MAKEFOOD 1000
#define MAX_WALL 35

//��ü Game�� �����ϴ� Class

class Game
{
	int PlayStartTime;//�ð������� ����
	int score;//����
	list<Pos> wallList;//�� ���迭
	list<Pos> foodList;//���� ���迭
	Snake* player; //��
	Block blockManager; //�� �� ��� ��ο츦 ���� blockManager
public:
	Game();
	void Menu();//�޴�
	void PrintScore(); //���ھ� ���

	//-����-//
	void PlaySetting(); //���� ���� �� ����
	void PlayGame(); //���� �÷���
	void Update(); //������Ʈ �Լ�
	void GameOver(); //���� ����
	void ResetGame(); //���� ������ �Ҵ��ߴ��͵� ó��/���� �ʱ�ȭ
	void MakeFood();//���� ����� �Լ�
	void MakeWall();//�� ����� �Լ�
	void ListErase(list<Pos> *blocklist, int x, int y);//����Ʈ ���� ����
	bool BlockCheck(list<Pos> blocklist, int x, int y);//��üũ
	bool GameOverCheck();//���ӿ��� üũ
	void SnakeFoodCheck();//���� �Ծ����� Ȯ��
};

