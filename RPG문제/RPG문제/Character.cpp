#include "Character.h"

Character::Character()
{

}

Character::~Character()
{

}

void Character::SetName()
{
	YELLOW
	m_MapDrawManager.DrawMidText("Player 이름 입력 : ", WIDTH, HEIGHT * 0.5f);
	cin >> m_Name;
	ORIGINAL
}