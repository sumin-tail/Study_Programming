#include "Fire.h"

Fire::Fire() : m_PosX(0), m_MoveFire(0) , m_Animationtimer(0)
{
	m_Fire = new BitMap[2]; //��
}

Fire::~Fire()
{
    delete[] m_Fire;
}

void Fire::ImageInit(HDC hdc, const char* name, int count, BitMap* arr)
{
	char buf[256]; //char�� �迭����
	for (int i = 0; i < count; i++)
	{
		sprintf_s(buf, "Resource//%s_%d.bmp", name, i + 1); //�̹��� ��ġ ���ۿ� ����
		arr[i].Init(hdc, buf);//�迭 �ʱ�ȭ
	}

}

void Fire::Init(HDC hdc)
{
	char buf[256]; //char�� �迭����
	sprintf_s(buf, "Resource//goal.bmp");
	m_goal.Init(hdc, buf);//��������
	ImageInit(hdc, "fire", 2, m_Fire); 

	m_Width = m_Fire[0].GetSize().cx; //���� ������ ����
	m_Height = m_Fire[0].GetSize().cy; //���� ������ ����
}

void Fire::Update(float deltaTime, float speed, float pos)
{
	AnimationUpdate(deltaTime);//�ִϸ��̼� ������Ʈ

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

	if (0.03f <= m_Animationtimer) //0.3 �ʸ��� ������Ʈ 
	{
		m_Animationtimer = 0; //�ʱ�ȭ �ѹ� �ϰ�
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
	for (int i = 1; i < 11; i++) //�� ���� ��ο�
	{
		m_Fire[m_MoveFire].Draw(hdc, 1000*i+ m_PosX, 340);	
		m_DeadCollider[i-1] = {(LONG)(1000 * i + m_PosX + m_Width * 0.25f), 340 , (LONG)(1000 * i + m_PosX + m_Width*0.75f), 340 + m_Height };
#ifdef Debug
		Rectangle(hdc, m_DeadCollider[i - 1].left, m_DeadCollider[i - 1].top, m_DeadCollider[i - 1].right, m_DeadCollider[i - 1].bottom);//�Ҵ��� �ݶ��̴�
		Rectangle(hdc, m_GoalCollider.left, m_GoalCollider.top, m_GoalCollider.right, m_GoalCollider.bottom); // ������ �ݶ��̴�
#endif // Debug
	}

	//�̰���¥
	m_GoalCollider = {(LONG)(10050 + m_PosX), 340 , (LONG)(10050 + m_PosX + m_goal.GetSize().cx), 340 + m_goal.GetSize().cy };
	m_goal.Draw(hdc, 10050 + m_PosX, 340); //������ ��ο�

	//�¸� Ȯ�ο�
	//m_GoalCollider = {(LONG)(500 + m_PosX), 340 , (LONG)(500 + m_PosX + m_goal.GetSize().cx), 340 + m_goal.GetSize().cy };
	//m_goal.Draw(hdc, 500 + m_PosX, 340); //������ ��ο�

}

void Fire::Reset()
{
	m_PosX = 0;
	m_MoveFire = 0;
	m_Animationtimer = 0;
}
