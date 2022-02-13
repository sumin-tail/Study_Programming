#include "Ring.h"
#include "GameManager.h"

Ring::Ring() : m_PosX(1000), m_MoveRing(1), m_Animationtimer(0),m_ScoreUp(false)
{
	m_Ring = new BitMap[4]; //불
}

Ring::~Ring()
{
	delete[] m_Ring;
}

void Ring::Init(HDC hdc)
{
	char buf[256]; //char형 배열생성
	for (int i = 0; i < 4; i++)// 이미지 사이즈 만큼 돌면서
	{
		sprintf_s(buf, "Resource//ring_%d.bmp", i + 1); //이미지 위치를 버퍼에 저장하고
		m_Ring[i].Init(hdc, buf); //얻어온 DC랑 이미지 위치 넘겨줌
	}
	m_Width = m_Ring[0].GetSize().cx; //가로 사이즈 저장
	m_Height = m_Ring[0].GetSize().cy; //세로 사이즈 저장
}


void Ring::Update(float deltaTime, float speed, float pos)
{
	AnimationUpdate(deltaTime);//애니메이션 업데이트
	if (0 >= pos || pos >= 9200) speed = 0; // 플레이어가 0 에서 뒤로 이돌할때/ 마지막 부부에서 앞으로 이동할때 링 속도 잡아줌

	m_PosX -= (speed + 700) * deltaTime;
	if (-100 > m_PosX) 
	{
		m_PosX = 1000;	// 맵 밖으로 나갔으면 다시 앞으로 되돌려줌
		m_ScoreUp = false;
	}
	m_DeadCollider = {(LONG)(m_PosX + m_Width*0.5f), 200 + m_Height - 15 , (LONG)(m_PosX + m_Width*1.5f), 200 + m_Height}; //사망 콜라이더
	m_ScoreCollider = {(LONG)(m_PosX + m_Width * 0.5f), 200, (LONG)(m_PosX + m_Width * 1.5f), (LONG)(200 + m_Height*0.8f)}; //스코어 콜라이더
}

void Ring::AnimationUpdate(float deltaTime)
{
	m_Animationtimer += deltaTime;

	if (0.03f <= m_Animationtimer) //0.3 초마다 업데이트 
	{
		m_Animationtimer = 0; //초기화 한번 하고
		m_MoveRing += 2;
		if (m_MoveRing > 3)
		{
			m_MoveRing = 1;
		}
	}
}

void Ring::BackRing(HDC hdc)
{
	m_Ring[m_MoveRing-1].Draw(hdc, m_PosX, 200);
}

void Ring::FrontRing(HDC hdc)
{
	m_Ring[m_MoveRing].Draw(hdc, m_PosX + m_Width, 200);

#ifdef Debug
	Rectangle(hdc, m_DeadCollider.left, m_DeadCollider.top, m_DeadCollider.right, m_DeadCollider.bottom);
	Rectangle(hdc, m_ScoreCollider.left, m_ScoreCollider.top, m_ScoreCollider.right, m_ScoreCollider.bottom);
#endif // Debug
}

bool Ring::DeadColliderCheck(RECT PlayerRect)
{
	RECT temp;
	return IntersectRect(&temp, &m_DeadCollider, &PlayerRect);
}

void Ring::ScoreColliderCheck(RECT PlayerRect)
{
	RECT temp;
	if (m_ScoreUp != true && IntersectRect(&temp, &m_ScoreCollider, &PlayerRect))
	{
		m_ScoreUp = true;
		ScoreUP();
	}

}

void Ring::Reset()
{
	m_PosX=1000;
	m_MoveRing=1;
	m_Animationtimer=0;
	m_ScoreUp= false;
}

void Ring::ScoreUP()
{
	GameManager::GetInstance()->ScoreUP(100);
}


//리틀 링 존


LittleRing::LittleRing()
{
	m_cash = new BitMap; //캐쉬 할당
}

LittleRing::~LittleRing()
{
	delete[] m_cash;
}

void LittleRing::Init(HDC hdc)
{
	Ring::Init(hdc);
	char buf[256]; //char형 배열생성
	m_PosX = 3000;
	sprintf_s(buf, "Resource//cash.bmp"); 
	m_cash->Init(hdc, buf);  //캐쉬 이미지할당
	
	m_Height = m_Ring[0].GetSize().cy * 0.7f; //세로 사이즈 저장 (조금 작게)

	//m_CashWidth = m_cash->GetSize().cx; //캐쉬가로 세로 넣음
	//m_CashHeight = m_cash->GetSize().cy;
}

void LittleRing::Update(float deltaTime, float speed, float pos)
{
	AnimationUpdate(deltaTime);//애니메이션 업데이트
	if (0 >= pos || pos >= 9200) speed = 0; // 플레이어가 0 에서 뒤로 이돌할때/ 마지막 부부에서 앞으로 이동할때 링 속도 잡아줌

	m_PosX -= (speed + 900) * deltaTime;
	if (-100 > m_PosX)
	{
		m_PosX = 3000;
		m_ScoreUp = false;
	}// 맵 밖으로 나갔으면 다시 앞으로 되돌려줌

	m_DeadCollider = { (LONG)(m_PosX + m_Width * 0.5f), (LONG)(200 + m_Height - 15) , (LONG)(m_PosX + m_Width * 1.5f),(LONG)(200 + m_Height)};
	m_ScoreCollider = { (LONG)(m_PosX + m_Width * 0.5f), 200, (LONG)(m_PosX + m_Width * 1.5f), (LONG)(200 + m_Height * 0.8f) }; //스코어 콜라이더
}

void LittleRing::BackRing(HDC hdc)
{
	m_Ring[m_MoveRing - 1].Draw(hdc, m_PosX, 200, m_Width, m_Height); //링 뒤쪽 드로우
	if (m_ScoreUp == false)
	{
		m_cash->Draw(hdc, m_PosX + 10, 210);// 링 앞쪽 드로우
	}
}

void LittleRing::FrontRing(HDC hdc)
{
	m_Ring[m_MoveRing].Draw(hdc, m_PosX + m_Width, 200, m_Width, m_Height);
#ifdef Debug
	Rectangle(hdc, m_DeadCollider.left, m_DeadCollider.top, m_DeadCollider.right, m_DeadCollider.bottom);
	Rectangle(hdc, m_ScoreCollider.left, m_ScoreCollider.top, m_ScoreCollider.right, m_ScoreCollider.bottom);
#endif // Debug
}

void LittleRing::ScoreUP()
{
	GameManager::GetInstance()->ScoreUP(200);
}

void LittleRing::Reset()
{
	Ring::Reset();
	m_PosX = 3000;
}
