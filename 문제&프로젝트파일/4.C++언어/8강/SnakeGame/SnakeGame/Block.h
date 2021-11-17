#pragma once
#include "Macro.h"

//�������� ����� ����� Class
//�ɹ� ���� - ����ǻ���(��, ����, ��Ӹ�, �첿����),x, y��
//�ɹ� �Լ� - ����浹üũ, ��ǥ����, ���׸���, ���������,
//Ư���������, �������ϱ⡦

class Block
{
	string food ="��";
	string snakeHead="��";
	string snakeBody = "��";
public:
	void WallDraw();//�� ��ο�
	void DrawPoint(string str, int x, int y); //�ش� ��ǥ ��ο�
	void ErasePoint(int x, int y);//�ش� ��ǥ ����
	void DrawMidText(string str, int x, int y);//�ؽ�Ʈ �߾����

	//��ο� �Լ�
	void DrawFood(Pos pos);
	void DrawWall(Pos pos);
	void DrawSnakeHead(Pos pos);
	void DrawSnakeBody(Pos pos);
};

