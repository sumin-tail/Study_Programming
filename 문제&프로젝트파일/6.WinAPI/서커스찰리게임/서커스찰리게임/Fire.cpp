#include "Fire.h"

Fire::Fire() : m_PosX(0), m_MoveFire(0) , m_Animationtimer(0)
{
	m_Fire = new BitMap[2]; //불
}

Fire::~Fire()
{
    delete[] m_Fire;
}

void Fire::ImageInit(HDC hdc, const char* name, int count, BitMap* arr)
{
	char buf[256]; //char형 배열생성
	for (int i = 0; i < count; i++)
	{
		sprintf_s(buf, "Resource//%s_%d.bmp", name, i + 1); //이미지 위치 버퍼에 저장
		arr[i].Init(hdc, buf);//배열 초기화
	}

}

void Fire::Init(HDC hdc)
{
	char buf[256]; //char형 배열생성
	sprintf_s(buf, "Resource//goal.bmp");
	m_goal.Init(hdc, buf);//골인지점
	ImageInit(hdc, "fire", 2, m_Fire); 

	m_Width = m_Fire[0].GetSize().cx; //가로 사이즈 저장
	m_Height = m_Fire[0].GetSize().cy; //세로 사이즈 저장
}

void Fire::Update(float deltaTime, float speed, float pos)
{
	AnimationUpdate(deltaTime);//애니메이션 업데이트

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


}

void Fire::AnimationUpdate(float deltaTime)
{
	m_Animationtimer += deltaTime;

	if (0.03f <= m_Animationtimer) //0.3 초마다 업데이트 
	{
		m_Animationtimer = 0; //초기화 한번 하고
		m_MoveFire++;
		if (m_MoveFire > 1)
		{
			m_MoveFire = 0;
		}
	}
}

bool Fire::DeadColliderCheck(RECT PlayerRect)
{
	RECT temp;
	for (int i = 1; i < 11; i++)
	{
		if (IntersectRect(&temp, &m_DeadCollider[i-1], &PlayerRect))
		{
			return true;
		}
		
	}
	return false;
}

bool Fire::GoalCheck(RECT PlayerRect)
{
	RECT temp;
	if (IntersectRect(&temp, &m_GoalCollider, &PlayerRect))
	{
		return true;
	}
	return false;
}


void Fire::Draw(HDC hdc)
{
	for (int i = 1; i < 11; i++) //불 단지 드로우
	{
		m_Fire[m_MoveFire].Draw(hdc, 1000*i+ m_PosX, 340);	
		m_DeadCollider[i-1] = {(LONG)(1000 * i + m_PosX + m_Width * 0.25f), 340 , (LONG)(1000 * i + m_PosX + m_Width*0.75f), 340 + m_Height };
#ifdef Debug
		Rectangle(hdc, m_DeadCollider[i - 1].left, m_DeadCollider[i - 1].top, m_DeadCollider[i - 1].right, m_DeadCollider[i - 1].bottom);//불단지 콜라이더
		Rectangle(hdc, m_GoalCollider.left, m_GoalCollider.top, m_GoalCollider.right, m_GoalCollider.bottom); // 골지점 콜라이더
#endif // Debug
	}

	//이게진짜
	m_GoalCollider = {(LONG)(10050 + m_PosX), 340 , (LONG)(10050 + m_PosX + m_goal.GetSize().cx), 340 + m_goal.GetSize().cy };
	m_goal.Draw(hdc, 10050 + m_PosX, 340); //골지점 드로우

	//승리 확인용
	//m_GoalCollider = {(LONG)(500 + m_PosX), 340 , (LONG)(500 + m_PosX + m_goal.GetSize().cx), 340 + m_goal.GetSize().cy };
	//m_goal.Draw(hdc, 500 + m_PosX, 340); //골지점 드로우

}

void Fire::Reset()
{
	m_PosX = 0;
	m_MoveFire = 0;
	m_Animationtimer = 0;
}
