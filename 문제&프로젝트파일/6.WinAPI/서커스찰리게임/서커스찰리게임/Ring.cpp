#include "Ring.h"
#include "GameManager.h"

Ring::Ring() : m_PosX(1000), m_MoveRing(1), m_Animationtimer(0),m_ScoreUp(false)
{
	m_Ring = new BitMap[4]; //��
}

Ring::~Ring()
{
	delete[] m_Ring;
}

void Ring::Init(HDC hdc)
{
	char buf[256]; //char�� �迭����
	for (int i = 0; i < 4; i++)// �̹��� ������ ��ŭ ���鼭
	{
		sprintf_s(buf, "Resource//ring_%d.bmp", i + 1); //�̹��� ��ġ�� ���ۿ� �����ϰ�
		m_Ring[i].Init(hdc, buf); //���� DC�� �̹��� ��ġ �Ѱ���
	}
	m_Width = m_Ring[0].GetSize().cx; //���� ������ ����
	m_Height = m_Ring[0].GetSize().cy; //���� ������ ����
}


void Ring::Update(float deltaTime, float speed, float pos)
{
	AnimationUpdate(deltaTime);//�ִϸ��̼� ������Ʈ
	if (0 >= pos || pos >= 9200) speed = 0; // �÷��̾ 0 ���� �ڷ� �̵��Ҷ�/ ������ �κο��� ������ �̵��Ҷ� �� �ӵ� �����

	m_PosX -= (speed + 700) * deltaTime;
	if (-100 > m_PosX) 
	{
		m_PosX = 1000;	// �� ������ �������� �ٽ� ������ �ǵ�����
		m_ScoreUp = false;
	}
	m_DeadCollider = {(LONG)(m_PosX + m_Width*0.5f), 200 + m_Height - 15 , (LONG)(m_PosX + m_Width*1.5f), 200 + m_Height}; //��� �ݶ��̴�
	m_ScoreCollider = {(LONG)(m_PosX + m_Width * 0.5f), 200, (LONG)(m_PosX + m_Width * 1.5f), (LONG)(200 + m_Height*0.8f)}; //���ھ� �ݶ��̴�
}

void Ring::AnimationUpdate(float deltaTime)
{
	m_Animationtimer += deltaTime;

	if (0.03f <= m_Animationtimer) //0.3 �ʸ��� ������Ʈ 
	{
		m_Animationtimer = 0; //�ʱ�ȭ �ѹ� �ϰ�
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


//��Ʋ �� ��


LittleRing::LittleRing()
{
	m_cash = new BitMap; //ĳ�� �Ҵ�
}

LittleRing::~LittleRing()
{
	delete[] m_cash;
}

void LittleRing::Init(HDC hdc)
{
	Ring::Init(hdc);
	char buf[256]; //char�� �迭����
	m_PosX = 3000;
	sprintf_s(buf, "Resource//cash.bmp"); 
	m_cash->Init(hdc, buf);  //ĳ�� �̹����Ҵ�
	
	m_Height = m_Ring[0].GetSize().cy * 0.7f; //���� ������ ���� (���� �۰�)

	//m_CashWidth = m_cash->GetSize().cx; //ĳ������ ���� ����
	//m_CashHeight = m_cash->GetSize().cy;
}

void LittleRing::Update(float deltaTime, float speed, float pos)
{
	AnimationUpdate(deltaTime);//�ִϸ��̼� ������Ʈ
	if (0 >= pos || pos >= 9200) speed = 0; // �÷��̾ 0 ���� �ڷ� �̵��Ҷ�/ ������ �κο��� ������ �̵��Ҷ� �� �ӵ� �����

	m_PosX -= (speed + 900) * deltaTime;
	if (-100 > m_PosX)
	{
		m_PosX = 3000;
		m_ScoreUp = false;
	}// �� ������ �������� �ٽ� ������ �ǵ�����

	m_DeadCollider = { (LONG)(m_PosX + m_Width * 0.5f), (LONG)(200 + m_Height - 15) , (LONG)(m_PosX + m_Width * 1.5f),(LONG)(200 + m_Height)};
	m_ScoreCollider = { (LONG)(m_PosX + m_Width * 0.5f), 200, (LONG)(m_PosX + m_Width * 1.5f), (LONG)(200 + m_Height * 0.8f) }; //���ھ� �ݶ��̴�
}

void LittleRing::BackRing(HDC hdc)
{
	m_Ring[m_MoveRing - 1].Draw(hdc, m_PosX, 200, m_Width, m_Height); //�� ���� ��ο�
	if (m_ScoreUp == false)
	{
		m_cash->Draw(hdc, m_PosX + 10, 210);// �� ���� ��ο�
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
