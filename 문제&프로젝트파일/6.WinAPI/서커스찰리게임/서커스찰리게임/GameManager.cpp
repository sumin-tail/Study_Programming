#include "GameManager.h"
GameManager* GameManager::m_hThis = NULL; //초기화

GameManager::GameManager() : m_GameState(GAME_MAIN), m_WindowWidth(1000), m_WindowHeight(500), m_score(0), m_bonus(10000), m_Pausetimer(0)//게임 상태는 기본적으로 게임 메인
{
    m_Ring[0] = new Ring;
    m_Ring[1] = new LittleRing;
}

GameManager::~GameManager()
{
    delete[] m_Ring;
    DeleteObject(m_backDC); //back DC 삭제
	ReleaseDC(m_hWnd, m_hdc); //DC풀어줌
    DeleteObject(m_font);
}

void GameManager::Init(HWND hWnd)
{
    m_hWnd = hWnd;//윈도우 핸들 받아옴
	MoveWindow(m_hWnd, 500, 0, m_WindowWidth, m_WindowHeight, true); //윈도우 사이즈 다시 그림  > 그릴 시작 좌표(X,Y) 랑 가로 세로사이즈

    RECT windowRect;
    GetWindowRect(m_hWnd, &windowRect); //윈도우 사각형 사이즈 가져옴
    m_WindowScreenWidth = windowRect.right - windowRect.left;
    m_WindowScreenHeight = windowRect.bottom - windowRect.top;

	m_hdc = GetDC(m_hWnd); //핸들값을 이용해 DC얻어옴 > 다쓰고 난뒤에 ReleaseDC 하는것 잊지않기
    m_backDC = CreateCompatibleDC(m_hdc); //DC만듬 - back DC(뒤쪽 캔버스)로 쓸 친구 
    m_font = CreateFontA(20, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "궁서");
    m_oldfont = (HFONT)SelectObject(m_backDC, m_font);
    //SelectObject(m_hdc, m_oldfont);

    m_MainMenu.Init(m_hdc);//메인 메뉴 초기화
    m_Player.Init(m_hdc);//플레이BG 초기화
    m_BackGround.Init(m_hdc); //플레이 백그라운드 초기화
    m_Interface.Init(m_hdc); //인터페이스 초기화
    m_Fire.Init(m_hdc); //불 단지 초기화
    m_Ring[0]->Init(m_hdc);
    m_Ring[1]->Init(m_hdc);
}

void GameManager::Draw()
{
    HBITMAP backBitmap = CreateDIBSectionRe(m_hdc, m_WindowScreenWidth, m_WindowScreenHeight); //캔버스(가로, 세로)로 바꿔줌
    HBITMAP oldBack = (HBITMAP)SelectObject(m_backDC, backBitmap);//캔버스 피고  - oldBack에 기존 거 들어감
    
    switch (m_GameState) //게임 상태에따라 그리는게 달라야함 - back DC에 그림
    {
    case GAME_MAIN:
        m_MainMenu.Draw(m_backDC, m_WindowWidth, m_WindowHeight); //메인메뉴 드로우
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

    BitBlt(m_hdc, 0, 0, m_WindowScreenWidth, m_WindowScreenHeight, m_backDC, 0, 0, SRCCOPY); //back DC에 있던거 hdc에 찍음
    SelectObject(m_backDC, oldBack); //원래 핸들로 돌려줌
    DeleteObject(backBitmap); // HBITMAP 삭제
}

void GameManager::Update(float elapsed)
{
    if (GetAsyncKeyState(VK_RETURN) && m_GameState == GAME_MAIN )
    {
        m_GameState = GAME_PLAY;
    }

    switch (m_GameState) //게임 상태에따라
    {
    case GAME_MAIN:
        m_MainMenu.Update(elapsed); //메인메뉴 업데이트
        break;
    case GAME_PLAY:
        if (m_bonus > 0)
        {
            m_bonus -= elapsed * 100; //보너스 점수 관리
        }
        m_Player.Update(elapsed);
        m_BackGround.Update(elapsed, m_Player.GetPlayerSpeed(), m_Player.GetPlayermMovePos());
        m_Fire.Update(elapsed, m_Player.GetPlayerSpeed(), m_Player.GetPlayermMovePos());
        m_Ring[0]->Update(elapsed, m_Player.GetPlayerSpeed(), m_Player.GetPlayermMovePos());
        m_Ring[1]->Update(elapsed, m_Player.GetPlayerSpeed(), m_Player.GetPlayermMovePos());

        //충돌체크 일시적 주석처리
        //if (m_Ring[0]->DeadColliderCheck(m_Player.GetPlayerRect()) || m_Ring[1]->DeadColliderCheck(m_Player.GetPlayerRect()) || m_Fire.DeadColliderCheck(m_Player.GetPlayerRect())) //사망 체크
        //{
        //    m_Player.Dead();
        //    m_GameState = GAME_PAUSE; //일시정지 상태로 바꿔줌
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
        if (0.5f <= m_Pausetimer) //0.5 초뒤에
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

        if ( m_bonus > 0) //0.01 초마다
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

        if (2 <= m_Pausetimer) //2초뒤에
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


//더블 버퍼용
HBITMAP GameManager::CreateDIBSectionRe(HDC hdc, int width, int height)
{
    BITMAPINFO bm_info;
    ZeroMemory(&bm_info.bmiHeader, sizeof(BITMAPINFOHEADER));
    bm_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bm_info.bmiHeader.biBitCount = 24; // 컬러 수(color bits) : 1, 4, 8, 16, 24, 31
    bm_info.bmiHeader.biWidth = width; // 너비.
    bm_info.bmiHeader.biHeight = height;// 높이.
    bm_info.bmiHeader.biPlanes = 1;
    LPVOID pBits;
    return CreateDIBSection(hdc, &bm_info, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
}


