#include "BackGround.h"

BackGround::BackGround() : m_PosX(0), m_ClearMove(0), m_Clear(false)
{
	m_Back = new BitMap[4];
}

BackGround::~BackGround()
{
	delete[] m_Back;

}

void BackGround::Init(HDC hdc)
{
	char buf[256]; //char형 배열생성
	for (int i = 0; i < 4; i++)
	{
		sprintf_s(buf, "Resource//back_%d.bmp", i + 1); //이미지 위치 버퍼에 저장
		m_Back[i].Init(hdc, buf);//배열 초기화
	}
	m_BackWidth = m_Back[1].GetSize().cx;
}

void BackGround::Update(float deltaTime, float speed, float pos)
{
	if (m_Clear)
	{
		AnimationUpdate(deltaTime);
	}


	if (pos == 0 && speed < 0)
	{
		m_PosX = 0;
		return;
	}

	if (pos > 9200)
	{
		return;
	}

	m_PosX -= speed * deltaTime;

	if (-(m_BackWidth * 18) > m_PosX)
	{
		m_PosX += (m_BackWidth * 18);
	}
	if (0 < m_PosX)
	{
		m_PosX -= (m_BackWidth * 18);
	}

}

void BackGround::Reset()
{
	m_PosX = 0;
	m_Clear = false;
}

void BackGround::BackGroundDraw(HDC hdc)
{

	for (int i = 0; i < (18 * 2); i++)
	{
		if (i%6 == 0)
		{
			m_Back[1].Draw(hdc, m_BackWidth*i + m_PosX, 125);
		}
		else
		{
			m_Back[2 + m_ClearMove].Draw(hdc, m_BackWidth*i + m_PosX, 125);
		}
	}
	m_Back[0].Draw(hdc, 0,190, 1000, 200);
}

void BackGround::AnimationUpdate(float deltaTime)
{
	m_Animationtimer += deltaTime;

	if (0.03f <= m_Animationtimer) //0.1 초마다 업데이트 
	{
		m_Animationtimer = 0; //초기화 한번 하고
		m_ClearMove++;
		if (m_ClearMove > 1) 
		{
		   m_ClearMove = 0;
		}
	}
}

void BackGround::Clear()
{
	m_Clear = true;
}
