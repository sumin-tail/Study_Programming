#pragma once
#include "Mecro.h"
#include "WordManager.h"
#include "Interface.h"

//��ü ���� �帧 ���� Class
//�̸����̴� 10���� ���Ϸ� = 10���ڱ����� oK
class Play
{
private:
	string m_name;
	int m_score;
	Interface m_DrawInterface;
public:
	void MainMenu();
};

