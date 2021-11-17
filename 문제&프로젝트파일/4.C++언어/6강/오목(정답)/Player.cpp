#include "Player.h"

Player::Player()
{
	m_pStoneList = NULL;
	m_iStoneCount = 0;
	m_bMyWindState = false;
	m_iUndo = DEFAULT_UNDO;
}


bool Player::CompareStone(int x, int y) //돌 찾기
{
	for(int i = 0; i < m_iStoneCount; i++)
	{
		if(m_pStoneList[i].m_ix == x &&m_pStoneList[i].m_iy == y)
			return true;
	}
	return false;
}

void Player::AllStoneDraw() //모든 돌 출력
{
	for(int i = 0; i < m_iStoneCount; i++)
		m_DrawManager.DrawPoint(m_strStoneIcon, m_pStoneList[i].m_ix, m_pStoneList[i].m_iy);
}

void Player::DrawStone(int x, int y)//돌출력
{
	if(CompareStone(x, y))//해당좌표에 돌이없다면
		m_DrawManager.DrawPoint(m_strStoneIcon, x, y);
}

void Player::Undo(int Width, int Height)//무르기
{
	m_iStoneCount--; //현재 돌 하나 줄이고
	m_DrawManager.Erase(m_pStoneList[m_iStoneCount].m_ix, m_pStoneList[m_iStoneCount].m_iy, Width, Height); //해당돌이있던 자리를 지움
}

void Player::CreateStone()// 돌놓기
{
	if(CompareStone(m_Cursor.m_ix, m_Cursor.m_iy) == false) //만약 현재좌표에 돌이 없다면
	{
		m_pStoneList[m_iStoneCount].m_ix = m_Cursor.m_ix; //m_pStoneList의 m_iStoneCount번째 m_ix에 현재 x좌표 넣음
		m_pStoneList[m_iStoneCount++].m_iy = m_Cursor.m_iy; //m_pStoneList의 m_iStoneCount번째 m_ix에 현재 x좌표 넣음
		DrawStone(m_Cursor.m_ix, m_Cursor.m_iy); //해당 좌표에 돌 드로우
	}
}

void Player::Move(char ch, int Width, int Height) //들어온 좌우이동 키보드 입력에 따라 현재좌표 변경
{
	switch(ch)
	{
		case KEY_LEFT:
			if(m_Cursor.m_ix - 1 >= 0)
				m_Cursor.m_ix--;
			break;
		case KEY_RIGHT:
			if(m_Cursor.m_ix + 1 < Width)
				m_Cursor.m_ix++;
			break;
		case KEY_UP:
			if(m_Cursor.m_iy - 1 >= 0)
				m_Cursor.m_iy--;
			break;
		case KEY_DOWN:
			if(m_Cursor.m_iy + 1 < Height)
				m_Cursor.m_iy++;
			break;
	}
}


void Player::EraseCursor(int Width, int Height)//현재 내 좌표를 지움
{

	m_DrawManager.Erase(m_Cursor.m_ix, m_Cursor.m_iy,Width,Height); //타일로
}

void Player::DrawCursor() //커서 드로우
{
	m_DrawManager.DrawPoint(m_strCursorIcon, m_Cursor.m_ix, m_Cursor.m_iy);
}

void Player::DeleteStone() //돌 리스트 지움
{
	if(m_pStoneList != NULL) //돌 리스트가 NULL 이 아니라면
	{
		delete[] m_pStoneList; //리스트 지우고
		m_pStoneList = NULL; //NULL 넣어줌
	}
}

void Player::PlayerSet(int Width,int Height) //플레이어 세팅
{
	DeleteStone(); //돌 리스트 지움
	m_pStoneList = new Point[(Width*Height) / 2];//m_pStoneList에 좌표 구조체 Point 배열 할당
	m_iStoneCount = 0; //톨 카운트 0으로 설정
	m_Cursor.m_ix = Width * 0.5f; //맵 중간 좌표 넣음
	m_Cursor.m_iy = Height* 0.5f;
	m_bMyWindState = false; //승리상태 설정
}



int Player::NextStoneCheck(int x, int y, int addx, int addy, int Width, int Height)//다음 좌표에 돌이 있는지 체크
{
	int count = 0;
	for(; (x >= 0 && x < Width) && (y >= 0 && y < Height); x += addx, y += addy)//x좌표와 y좌표가 0이하가되거나 맵을 초과하지 않는이상
	{
		if(CompareStone(x, y)) //해달좌표의 돌이있는지 없는지 체크
			count++; //있다면 카운트를 올리고
		else //없다면 탈출!
			break;
	}
	return count;
}

bool Player::WinCheck(int Width, int Height)//승리체크함수 (맵 사이즈 받아옴)
{
	int Count = 0;
	Count += NextStoneCheck(m_Cursor.m_ix - 1, m_Cursor.m_iy, -1, 0, Width, Height);
	Count += NextStoneCheck(m_Cursor.m_ix + 1, m_Cursor.m_iy, 1, 0, Width, Height);
	if(Count + 1 == 5) //가로 검사
		return true;
	Count = 0;	
	Count += NextStoneCheck(m_Cursor.m_ix, m_Cursor.m_iy -1, 0, -1, Width, Height);
	Count += NextStoneCheck(m_Cursor.m_ix, m_Cursor.m_iy+1, 0, 1, Width, Height);
	if(Count + 1 == 5)//세로검사
		return true;
	Count = 0;
	Count += NextStoneCheck(m_Cursor.m_ix - 1, m_Cursor.m_iy-1, -1, -1, Width, Height);
	Count += NextStoneCheck(m_Cursor.m_ix + 1, m_Cursor.m_iy+1, 1, 1, Width, Height);
	if(Count + 1 == 5)//왼쪽대각선
		return true;
	Count = 0;
	Count += NextStoneCheck(m_Cursor.m_ix + 1, m_Cursor.m_iy-1, 1, -1, Width, Height);
	Count += NextStoneCheck(m_Cursor.m_ix - 1, m_Cursor.m_iy+1, -1, 1, Width, Height);
	if(Count + 1 == 5)//오른쪽대각선
		return true;

	return false;
}

Player::~Player()
{
	if(m_pStoneList != NULL)
		delete[] m_pStoneList;
}
