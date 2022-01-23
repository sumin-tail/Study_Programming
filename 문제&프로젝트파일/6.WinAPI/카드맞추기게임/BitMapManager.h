#pragma once
#include"BitMap.h"
#include<vector>

enum IMAGE //카드 이미지 파일
{
	IMAGE_START,
	IMAGE_DOG = 0,
	IMAGE_TIGER,
	IMAGE_DUCK,
	IMAGE_ELEPHANT,
	IMAGE_COW,
	IMAGE_HORSE,
	IMAGE_CAT,
	IMAGE_MONKEY,
	IMAGE_FROG,
	IMAGE_CHICKEN,
	IMAGE_BLACK, //뒷면 저장
	IMAGE_BACKGROUND,
	IMAGE_END
};

class BitMapManager //싱글톤임
{
private:
	BitMap* m_parrBitMap; //비트맵 포인터
	static BitMapManager* m_hThis; //싱글톤
public:
	static BitMapManager* GetInstance()
	{
		if (m_hThis == NULL)
			m_hThis = new BitMapManager;
		return m_hThis;
	}
	BitMap* GetImage(IMAGE index) //비트 맵 포인터로 돌려줌
	{
		return &m_parrBitMap[index]; // 해당하는 인덱스의 비트맵 좌표를 돌려줌
	}
	BitMapManager();
	void Init(HWND hWnd);
	~BitMapManager();
};

