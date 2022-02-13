// 서커스찰리게임.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#include "서커스찰리게임.h"
#include "GameManager.h"
#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//void DoubleBuffer(HWND hWnd, HDC hdc); // 더블 버퍼
//HBITMAP CreateDIBSectionRe(HDC hdc, int width, int height);//버퍼 세팅

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    //어플리케이션 초기화- 윈도우 핸들 
    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    //여기까지 어플리케이션 초기화

    MSG msg;
    ZeroMemory(&msg, sizeof(msg)); //메시지 메모리 비워주고- 안그러면 쓰레기값 들어감

    HDC hdc = GetDC(hWnd); //윈도우 핸들로 DC만듬 -> 지우는거 잊지않기
    ULONGLONG frameTime, limitFrameTime = GetTickCount64(); //프레임 타임 가져옴 

    GameManager::GetInstance()->Init(hWnd);

    // 기본 메시지 루프 -> 유니티 업데이트함수와 같음
    while (WM_QUIT != msg.message) //창 닫기 메세지가 오기전까지는 계속 돌아감
    {
        if (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))//메세지가 오면 실행
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else //아니라면 업데이트 (프레임단위)
        {
            frameTime = GetTickCount64();
            if (!(limitFrameTime > frameTime))//이 안은 프레임단위 조절해서 업데이트 할것들 -ex) 30 프레임 마다 호출~
            {
                float elapsed = (frameTime - limitFrameTime) * 0.01f; //사양에 따라 초당 프레임 다르니까
                limitFrameTime = frameTime + 30;//30 => 0.03초.
                GameManager::GetInstance()->Update(elapsed);
                GameManager::GetInstance()->Draw();
            }
        }
    }
        
    ReleaseDC(hWnd, hdc); //-> 만든 DC지움
    return (int) msg.wParam;
}



//  함수: MyRegisterClass()
//  용도: 창 클래스를 등록합니다.
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = 0;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
