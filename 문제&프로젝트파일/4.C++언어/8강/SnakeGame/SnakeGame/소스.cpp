#pragma once
#include "Game.h"
#include "Macro.h"

//��� ������ �ϱ�!!
//enum ����

//-����
//��Ʈ�� �ִ� 10�� ������ �����̵ǰ� �����Ǵ� �ð��� ����/���� �������������� ���� ����
//���� ��������� ������
//���� ���� ����(������ ����-35�� ����) 
//���� �ڱ� ���� ��Ƶ� ����

void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	Game startGame;
	startGame.Menu();

}
