#include "BitMapManager.h"

BitMapManager* BitMapManager::m_hThis = NULL; //초기화

BitMapManager::BitMapManager()
{
	m_parrBitMap = new BitMap[IMAGE_END];//비트맵 배열을 이미지 사이즈 만큼 동적할당해서 비트맵 포인터에 넣어줌
}


void BitMapManager::Init(HWND hWnd)
{
	char buf[256]; //char형 배열생성
	HDC hdc = GetDC(hWnd); //핸들값을 이용해 DC얻어옴 > 다쓰고 난뒤에 ReleaseDC 하는것 잊지않기
	for (int i = IMAGE_START; i < IMAGE_END; i++)// 이미지 사이즈 만큼 돌면서
	{
		sprintf_s(buf, "RES//0%d.bmp", i); //이미지 위치를 버퍼에 저장하고
		m_parrBitMap[i].Init(hdc,buf); //얻어온 DC랑 이미지 위치 넘겨줌
	}
	ReleaseDC(hWnd, hdc); //DC풀어줌
}

BitMapManager::~BitMapManager()
{
	delete[] m_parrBitMap;
}
