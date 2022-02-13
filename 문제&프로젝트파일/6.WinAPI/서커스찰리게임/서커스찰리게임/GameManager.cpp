#include "GameManager.h"
GameManager* GameManager::m_hThis = NULL; //�ʱ�ȭ

GameManager::GameManager() : m_GameState(GAME_MAIN), m_WindowWidth(1000), m_WindowHeight(500), m_score(0), m_bonus(10000), m_Pausetimer(0)//���� ���´� �⺻������ ���� ����
{
    m_Ring[0] = new Ring;
    m_Ring[1] = new LittleRing;
}

GameManager::~GameManager()
{
    delete[] m_Ring;
    DeleteObject(m_backDC); //back DC ����
	ReleaseDC(m_hWnd, m_hdc); //DCǮ����
    DeleteObject(m_font);
}

void GameManager::Init(HWND hWnd)
{
    m_hWnd = hWnd;//������ �ڵ� �޾ƿ�
	MoveWindow(m_hWnd, 500, 0, m_WindowWidth, m_WindowHeight, true); //������ ������ �ٽ� �׸�  > �׸� ���� ��ǥ(X,Y) �� ���� ���λ�����

    RECT windowRect;
    GetWindowRect(m_hWnd, &windowRect); //������ �簢�� ������ ������
    m_WindowScreenWidth = windowRect.right - windowRect.left;
    m_WindowScreenHeight = windowRect.bottom - windowRect.top;

	m_hdc = GetDC(m_hWnd); //�ڵ鰪�� �̿��� DC���� > �پ��� ���ڿ� ReleaseDC �ϴ°� �����ʱ�
    m_backDC = CreateCompatibleDC(m_hdc); //DC���� - back DC(���� ĵ����)�� �� ģ�� 
    m_font = CreateFontA(20, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "�ü�");
    m_oldfont = (HFONT)SelectObject(m_backDC, m_font);
    //SelectObject(m_hdc, m_oldfont);

    m_MainMenu.Init(m_hdc);//���� �޴� �ʱ�ȭ
    m_Player.Init(m_hdc);//�÷���BG �ʱ�ȭ
    m_BackGround.Init(m_hdc); //�÷��� ��׶��� �ʱ�ȭ
    m_Interface.Init(m_hdc); //�������̽� �ʱ�ȭ
    m_Fire.Init(m_hdc); //�� ���� �ʱ�ȭ
    m_Ring[0]->Init(m_hdc);
    m_Ring[1]->Init(m_hdc);
}

void GameManager::Draw()
{
    HBITMAP backBitmap = CreateDIBSectionRe(m_hdc, m_WindowScreenWidth, m_WindowScreenHeight); //ĵ����(����, ����)�� �ٲ���
    HBITMAP oldBack = (HBITMAP)SelectObject(m_backDC, backBitmap);//ĵ���� �ǰ�  - oldBack�� ���� �� ��
    
    switch (m_GameState) //���� ���¿����� �׸��°� �޶���� - back DC�� �׸�
    {
    case GAME_MAIN:
        m_MainMenu.Draw(m_backDC, m_WindowWidth, m_WindowHeight); //���θ޴� ��ο�
        break;
    case GAME_PAUSE:
    case GAME_CLEAR:
    case GAME_PLAY:
        m_Interface.InterfaceDraw(m_backDC, m_WindowWidth, m_Player.GetPlayermMovePos(),m_Player.GetLife(), m_score, m_bonus);
        m_BackGround.BackGroundDraw(m_backDC);
        m_Ring[0]->BackRing(m_backDC);
        m_Ring[1]->BackRing(m_backDC);
        m_Player.Draw(m_backDC);
        m_Ring[0]->FrontRing(m_backDC);
        m_Ring[1]->FrontRing(m_backDC);
        m_Fire.Draw(m_backDC);
        break;
    }

    BitBlt(m_hdc, 0, 0, m_WindowScreenWidth, m_WindowScreenHeight, m_backDC, 0, 0, SRCCOPY); //back DC�� �ִ��� hdc�� ����
    SelectObject(m_backDC, oldBack); //���� �ڵ�� ������
    DeleteObject(backBitmap); // HBITMAP ����
}

void GameManager::Update(float elapsed)
{
    if (GetAsyncKeyState(VK_RETURN) && m_GameState == GAME_MAIN )
    {
        m_GameState = GAME_PLAY;
    }

    switch (m_GameState) //���� ���¿�����
    {
    case GAME_MAIN:
        m_MainMenu.Update(elapsed); //���θ޴� ������Ʈ
        break;
    case GAME_PLAY:
        if (m_bonus > 0)
        {
            m_bonus -= elapsed * 100; //���ʽ� ���� ����
        }
        m_Player.Update(elapsed);
        m_BackGround.Update(elapsed, m_Player.GetPlayerSpeed(), m_Player.GetPlayermMovePos());
        m_Fire.Update(elapsed, m_Player.GetPlayerSpeed(), m_Player.GetPlayermMovePos());
        m_Ring[0]->Update(elapsed, m_Player.GetPlayerSpeed(), m_Player.GetPlayermMovePos());
        m_Ring[1]->Update(elapsed, m_Player.GetPlayerSpeed(), m_Player.GetPlayermMovePos());

        //�浹üũ �Ͻ��� �ּ�ó��
        //if (m_Ring[0]->DeadColliderCheck(m_Player.GetPlayerRect()) || m_Ring[1]->DeadColliderCheck(m_Player.GetPlayerRect()) || m_Fire.DeadColliderCheck(m_Player.GetPlayerRect())) //��� üũ
        //{
        //    m_Player.Dead();
        //    m_GameState = GAME_PAUSE; //�Ͻ����� ���·� �ٲ���
        //}
        m_Ring[0]->ScoreColliderCheck(m_Player.GetPlayerRect());
        m_Ring[1]->ScoreColliderCheck(m_Player.GetPlayerRect());

        if (m_Fire.GoalCheck(m_Player.GetPlayerRect()))
        {
            m_GameState = GAME_CLEAR;
            m_Player.Goal();
            m_BackGround.Clear();
        }
        break;
    case GAME_PAUSE:
        m_Pausetimer += elapsed;
        if (0.5f <= m_Pausetimer) //0.5 �ʵڿ�
        {
            m_Pausetimer = 0;
            m_GameState = GAME_PLAY;
            if (m_Player.GetLife() == 0)
            {
                m_score = 0;
                m_GameState = GAME_MAIN;
            }
            Reset();
        }
        break;
    case GAME_CLEAR:
        m_Pausetimer += elapsed;

        if ( m_bonus > 0) //0.01 �ʸ���
        {
            m_Pausetimer = 0;
            if(m_bonus >1000)
            {
                m_bonus -= elapsed * 10000;
                m_score += elapsed * 10000;
            }
            if (m_bonus > 100)
            {
                m_bonus -= elapsed * 1000;
                m_score += elapsed * 1000;
            }
            else
            {
                m_bonus -= elapsed * 100;
                m_score += elapsed * 100;
            }
            if (m_bonus <= 0)
            {
                m_bonus = 0;
            }
        }

        if (2 <= m_Pausetimer) //2�ʵڿ�
        {
            Reset();
            m_Pausetimer = 0;
            m_score = 0;
            m_GameState = GAME_MAIN;
        }
        m_Fire.Update(elapsed, m_Player.GetPlayerSpeed(), m_Player.GetPlayermMovePos());
        m_Player.Update(elapsed);
        m_BackGround.Update(elapsed, m_Player.GetPlayerSpeed(), m_Player.GetPlayermMovePos());
        break;
    }
}

void GameManager::Reset()
{
    m_bonus = 10000;
    m_Player.Reset();
    m_Fire.Reset();
    m_BackGround.Reset();
    m_Ring[0]->Reset();
    m_Ring[1]->Reset();
}

void GameManager::ScoreUP(int score)
{
    m_score += score;
}


//���� ���ۿ�
HBITMAP GameManager::CreateDIBSectionRe(HDC hdc, int width, int height)
{
    BITMAPINFO bm_info;
    ZeroMemory(&bm_info.bmiHeader, sizeof(BITMAPINFOHEADER));
    bm_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bm_info.bmiHeader.biBitCount = 24; // �÷� ��(color bits) : 1, 4, 8, 16, 24, 31
    bm_info.bmiHeader.biWidth = width; // �ʺ�.
    bm_info.bmiHeader.biHeight = height;// ����.
    bm_info.bmiHeader.biPlanes = 1;
    LPVOID pBits;
    return CreateDIBSection(hdc, &bm_info, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
}


