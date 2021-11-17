#include "Player.h"

//생성자
Player::Player(string name, int x, int y, string Shape, int undoCount)
{
	m_strName = name; //이름
	m_strStoneShape = Shape; //돌 모양
	m_iundoCount = undoCount; //무르기 횟수 

	//좌표 갱신
	m_ix = x;
	if (m_ix % 2 == 1)//만약 짝수가 아닐경우
		m_ix++;
	m_iy = y;

}

//소멸자
Player::~Player() 
{

}

//마지막에 돌 놓은곳 갱신
void Player::PosUpdate(int x, int y) 
{
	m_ix = x;
	m_iy = y;
}

//돌모양 변경 함수
void Player::ChangeStoneShape(string Shape)
{
	m_strStoneShape = Shape;
}

//무르기
void Player::Undo(int width, int height)
{
	m_ix = StoneLOG.back().x; //가장 마지막 위치 갱신
	m_iy = StoneLOG.back().y; //가장 마지막 위치 갱신
	m_DrawManager.PlayingBoxEmpty(width, height, m_ix, m_iy);
	StoneLOG.pop_back();//돌 없앰
}


void  Player::Undocount()
{
	m_iundoCount--;
}

//승리체크 함수
bool Player::WinCheck()
{
	int count = 0;
	if (6 == WinCheckStoneCount(count, m_ix, m_iy, -2, 0)+ WinCheckStoneCount(count, m_ix, m_iy, 2, 0)) //가로
	{
		return true;
	}
	else if (6 == WinCheckStoneCount(count, m_ix, m_iy, 0, 1) + WinCheckStoneCount(count, m_ix, m_iy, 0, -1))//세로
	{
		return true;
	}
	else if (6 == WinCheckStoneCount(count, m_ix, m_iy, 2, -1) + WinCheckStoneCount(count, m_ix, m_iy, -2, 1))//오른쪽위에서 왼쪽 아래로
	{
		return true;
	}
	else if (6 == WinCheckStoneCount(count, m_ix, m_iy, -2, -1) + WinCheckStoneCount(count, m_ix, m_iy, 2, 1))//왼쪽 위에서 오른쪽 아래로
	{
		return true;
	}
	return false;
}

int Player::WinCheckStoneCount(int count, int posX, int posY, int ChangeX, int ChangeY)
{
	if (posX < 0 || posY < 0)
	{
		return count;
	}

	for (list<StoneXY>::iterator iter = StoneLOG.begin(); iter != StoneLOG.end(); iter++)
	{
		if (iter->x == posX && iter->y == posY)
		{
			count++;
			count = WinCheckStoneCount(count, posX+ChangeX, posY+ChangeY, ChangeX, ChangeY);
		}
	}

	return count;
}


//돌 체크 함수 > 해당좌표에 돌을 둘 수 있는지 없는지 확인
bool Player::StoneCheck(int posX, int posY)
{
	//돌이 있으면 true 반환
	for (list<StoneXY>::iterator iter = StoneLOG.begin(); iter != StoneLOG.end(); iter++)
	{
		if (iter->x == posX && iter->y == posY)
		{
			return true;
		}
	}
	return false;
}

//돌 놓는 함수
void Player::StoneDrop(int posX, int posY)
{
	StoneXY stone(posX, posY);
	StoneLOG.push_back(stone);
	m_DrawManager.TextDraw(m_strStoneShape, posX, posY);
}

//내가 놓은 돌 모두 출력
void Player::StoneDrow()
{
	for (list<StoneXY>::iterator iter = StoneLOG.begin(); iter != StoneLOG.end(); iter++)
	{
		m_DrawManager.TextDraw(m_strStoneShape, iter->x, iter->y);
	}
}

//반환함수//
//돌모양 리턴
string Player::GetStoneShape()
{
	return m_strStoneShape;
}
//이름 리턴
string Player::GetName()
{
	return m_strName;
}
//X좌표와 Y좌표 리턴
int Player::GetXPos()
{
	return m_ix;
}
int Player::GetYPos()
{
	return m_iy;
}

//남은 무르기 횟수 반환
int Player::GetUndo()
{
	return m_iundoCount;
}

