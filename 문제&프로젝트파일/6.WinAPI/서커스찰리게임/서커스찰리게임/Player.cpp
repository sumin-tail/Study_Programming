#include "Player.h"
#include "GameManager.h"

Player::Player() : m_Life(3), m_PosX(50), m_PosY(320), m_PlayerState(PLAYER_IDLE), m_MovePos(0), m_jump(false) , m_PlayerMoveStep(0)
{
	m_PlayerImage = new BitMap[6];
}

Player::~Player()
{
	delete[] m_PlayerImage;
}


void Player::Init(HDC hdc)
{
	char buf[256]; //char형 배열생성
	for (int i = 0; i < 6; i++)// 이미지 사이즈 만큼 돌면서
	{
		sprintf_s(buf, "Resource//player_%d.bmp", i+1); //이미지 위치를 버퍼에 저장하고
		m_PlayerImage[i].Init(hdc, buf); //얻어온 DC랑 이미지 위치 넘겨줌
	}
	m_Width = m_PlayerImage[0].GetSize().cx; //가로 사이즈 저장
	m_Height = m_PlayerImage[0].GetSize().cy; //세로 사이즈 저장
}


void Player::Update(float elapsed)
{
	KeyinputUpdate(elapsed);
	AnimationUpdate(elapsed);
	PlayerMoveStepUpdate();
	m_MovePos += m_Speed * elapsed;

	if (m_MovePos > 9200)
	{
		m_PosX += m_Speed * elapsed;
	}
	else
	{
		m_PosX = 50;
		//m_Speed += (m_PosX + 50);
	}

	if (m_MovePos <= 0 && m_Speed <= 0)
	{
		m_MovePos = 0;
	}

	m_PlayerCollider = {(LONG)(m_PosX + m_Width * 0.25f),  (LONG)m_PosY , (LONG)(m_PosX + m_Width*0.75f),  (LONG)m_PosY + m_Height-10 };
}

void Player::Reset()
{
	if (m_Life == 0 || m_PlayerState == PLAYER_CLEAR) //만약 죽었거나 클리어 리셋일 경우
	{
		m_MovePos = 0;
		m_Life = 3; //라이프 초기화
		m_PlayerMoveStep = 0; //움직인거리 초기화
	}
	else //아니라면 가장 멀리갔던 곳으로
	{
		m_MovePos = m_PlayerMoveStep * 1000 + 50;
	}
	m_PlayerState = PLAYER_IDLE;
	m_PosX = 50;
	m_PosY = 320;
	m_jump = false;
}

void Player::Draw(HDC hdc)
{

	switch (m_PlayerState)
	{
	case PLAYER_IDLE:
		m_PlayerImage[0].Draw(hdc, m_PosX, m_PosY);
		break;
	case PLAYER_MOVE:
		m_PlayerImage[m_MovePlayer].Draw(hdc, m_PosX, m_PosY);
		break;
	case PLAYER_JUMP:
		m_PlayerImage[2].Draw(hdc, m_PosX, m_PosY);
		break;
	case PLAYER_DEAD:
		m_PlayerImage[5].Draw(hdc, m_PosX, m_PosY);
		break;
	case PLAYER_CLEAR:
		m_PlayerImage[m_MovePlayer+3].Draw(hdc, m_PosX, m_PosY);
		break;
	default:
		break;
	}

#ifdef Debug
	Rectangle(hdc, m_PlayerCollider.left, m_PlayerCollider.top, m_PlayerCollider.right, m_PlayerCollider.bottom);
#endif // Debug
}


void Player::AnimationUpdate(float elapsed)
{
	m_Animationtimer += elapsed;

	if (0.03f <= m_Animationtimer) //0.1 초마다 업데이트 
	{
		m_Animationtimer = 0; //초기화 한번 하고

		m_MovePlayer++;

		if (m_Speed > 0 && m_MovePlayer > 2) //앞으로 가고있다면
		{
			m_MovePlayer = 0;
		}
		else if ((m_Speed < 0 || m_PlayerState == PLAYER_CLEAR) && m_MovePlayer > 1) //뒤로 가고있거나 골인했을떄
		{
			m_MovePlayer = 0;
		}

		if (m_PlayerState == PLAYER_JUMP) Jump(elapsed);
	}
}

void Player::KeyinputUpdate(float elapsed)
{
	m_Keyinputtimer += elapsed;

	if (0.03f <= m_Keyinputtimer) //0.1 초마다 업데이트 
	{
		m_Keyinputtimer = 0; //초기화 한번 하고

		if (m_PlayerState == PLAYER_JUMP || m_PlayerState == PLAYER_CLEAR) return; //점프 상태일 때 리턴

		if (GetAsyncKeyState(VK_SPACE)) //점프키를 눌렀을 때
		{
			m_PlayerState = PLAYER_JUMP;
			m_jump = true;
			return;
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			m_PlayerState = PLAYER_MOVE;
			m_Speed = 2500;
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			m_PlayerState = PLAYER_MOVE;
			m_Speed = -500;
		}
		else
		{
			m_PlayerState = PLAYER_IDLE;
			m_Speed = 0;
		}
	
	}
}

void Player::Jump(float elapsed)
{
	//마지막 스피드가 0 이었나 아니었나에 따라서 제자리 점프일지 아닐지 결정
	if (m_PosY > 200 && m_jump == true)
	{
		m_PosY -= 1500 * elapsed;
		if (m_PosY <= 200)
		{
			m_jump = false;
		}
	}
	else
	{
		m_PosY += 1500 * elapsed;
		if (m_PosY > 310 && m_PosY < 330)
		{
			m_PosY = 320;
			m_PlayerState = PLAYER_IDLE;
		}
	}
}

float Player::GetPlayerSpeed()
{
	return m_Speed;
}

float Player::GetPlayermMovePos()
{
	return m_MovePos;
}

int Player::GetLife()
{
	return m_Life;
}

void Player::Dead()
{
	if (m_Life > 0)
	{
		m_Life--;
		m_PlayerState = PLAYER_DEAD;
	}
}

void Player::PlayerMoveStepUpdate()
{
	int Step = m_MovePos / 1050;
	if (Step > m_PlayerMoveStep)
	{
		m_PlayerMoveStep = Step;
		GameManager::GetInstance()->ScoreUP(100);
	}
}

void Player::Goal()
{
	m_PosX = 850;
	m_PosY = 280;
	m_PlayerState = PLAYER_CLEAR;
	m_Speed = 0;
}

RECT Player::GetPlayerRect()
{
	return m_PlayerCollider;
}

