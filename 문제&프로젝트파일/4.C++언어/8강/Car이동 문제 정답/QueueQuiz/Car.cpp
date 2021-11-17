#include "Car.h"



Car::Car()
{
	m_iSpeedValue = CARSPEED; 
	Next = NULL;
	m_ix = 10;
	m_iMoveSpeedTime = clock();
	m_iSec = 0;
	DrawCar();
	m_eStatus = STATUS_MOVE;
	m_eSpeedType = MOVEMODE_NORMAL;
	EraseTime();
}


void Car::ChangeSpeed() //스피드 변경
{
	if( m_eSpeedType == MOVEMODE_FAST)
		m_eSpeedType = MOVEMODE_NORMAL;
	else if (m_eSpeedType == MOVEMODE_NORMAL)
		m_eSpeedType = MOVEMODE_FAST;
	switch (m_eSpeedType)
	{
	case MOVEMODE_NORMAL:
		m_iSpeedValue = CARSPEED;
		break;
	case MOVEMODE_FAST:
		m_iSpeedValue = FASTSPEED;
		break;
	}
	if (Next != NULL)//다음차가 있을 경우
		Next->ChangeSpeed(); //다음차 속력 바꿔줌
}

void Car::ChangeStatus()
{
	switch (m_eStatus)
	{
	case STATUS_MOVE:
		m_eStatus = STATUS_STAY;
		break;
	case STATUS_STAY:
		m_eStatus = STATUS_MOVE;
		EraseTime();
		break;
	case STATUS_END:
		break;
	}
}

void Car::Move()
{
	switch (m_eStatus)
	{
	case STATUS_MOVE:
		if (clock() - m_iMoveSpeedTime >= m_iSpeedValue)//이동할 시간이 된다면
		{
			EraseCar();//지우고
			m_ix++;//좌표이동후
			DrawCar();//새로그림
			m_iMoveSpeedTime = clock();//그리고 m_iMoveSpeedTime 갱신
		}
		break;
	case STATUS_STAY:
		if (clock() - m_iStayTime >= TIME)
		{
			m_iSec++;
			m_iStayTime = clock();
			DrawTime();
		}
		break;
	case STATUS_END:
		break;
	}
	if (Next != NULL)
		Next->Move();
}

void Car::EraseTime()
{
	gotoxy(m_ix, 13);
	cout << "                 ";
}
void Car::DrawTime()
{
	gotoxy(m_ix, 13);
	cout << "Stay Time : " << m_iSec << "    ";
}

void Car::EraseCar()
{
	gotoxy(m_ix, 10);
	cout << "            ";
	gotoxy(m_ix, 11);
	cout << "            ";
	gotoxy(m_ix, 12);
	cout << "            ";
}


void Car::DrawCar()
{
	gotoxy(m_ix, 10);
	cout << "  ┌──┐";
	gotoxy(m_ix, 11);
	cout << "┌┘▒▒└┐";
	gotoxy(m_ix, 12);
	cout << "└⊙──⊙┘";
}


Car::~Car()
{
}
