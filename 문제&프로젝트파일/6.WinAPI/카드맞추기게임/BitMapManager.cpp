#include "BitMapManager.h"

BitMapManager* BitMapManager::m_hThis = NULL; //�ʱ�ȭ

BitMapManager::BitMapManager()
{
	m_parrBitMap = new BitMap[IMAGE_END];//��Ʈ�� �迭�� �̹��� ������ ��ŭ �����Ҵ��ؼ� ��Ʈ�� �����Ϳ� �־���
}


void BitMapManager::Init(HWND hWnd)
{
	char buf[256]; //char�� �迭����
	HDC hdc = GetDC(hWnd); //�ڵ鰪�� �̿��� DC���� > �پ��� ���ڿ� ReleaseDC �ϴ°� �����ʱ�
	for (int i = IMAGE_START; i < IMAGE_END; i++)// �̹��� ������ ��ŭ ���鼭
	{
		sprintf_s(buf, "RES//0%d.bmp", i); //�̹��� ��ġ�� ���ۿ� �����ϰ�
		m_parrBitMap[i].Init(hdc,buf); //���� DC�� �̹��� ��ġ �Ѱ���
	}
	ReleaseDC(hWnd, hdc); //DCǮ����
}

BitMapManager::~BitMapManager()
{
	delete[] m_parrBitMap;
}
