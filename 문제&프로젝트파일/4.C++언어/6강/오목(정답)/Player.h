#pragma once
#include"Mecro.h"
#include"MapDraw.h"

#define DEFAULT_UNDO 5 //디폴트 무르기값 5

struct Point
{
	int m_ix;
	int m_iy;
};

class Player
{
private:
	MapDraw m_DrawManager; //맵 드로우 매니저
	string m_strName; //플레이어 이름
	Point* m_pStoneList; //둔 돌 리스트
	Point m_Cursor; //커서 좌표 
	int m_iStoneCount; 
	string m_strCursorIcon; //커서 아이콘
	string m_strStoneIcon; //돌 아이콘
	bool m_bMyWindState;//승리 상태
	int m_iUndo;//무르기
public:
	int NextStoneCheck(int x,int y,int addx,int addy, int Width, int Height); //다음 돌 체크
	bool WinCheck(int Width,int Height); //승리 체크
	void DrawStone(int x, int y); //돌 그리는 함수
	void AllStoneDraw();
	bool CompareStone(int x, int y);
	void CreateStone();
	void Move(char ch,int Width,int Height);
	void DrawCursor();
	void EraseCursor(int Width, int Height);
	void PlayerSet(int Width, int Height);
	void DeleteStone();
	void Undo(int Width,int Height);
	inline void DownUndo() { m_iUndo--; }//무르기 카운트 감소
	inline void SetUndo(int undo) { m_iUndo = undo; } //무르기 횟수 설정
	inline int GetUndo(){ return m_iUndo; }  //무르기 횟수 반환
	inline Point GetCursor() { return m_Cursor; } //커서좌표반환
	inline string GetName() { return m_strName; } //이름 반환
	inline void SetStoneIcon(string Icon) { m_strStoneIcon = Icon; } //돌 아이콘 설정
	inline void SetCursorIcon(string Icon) { m_strCursorIcon = Icon; } //커서아이콘 설정
	inline void SetName(){ cin >> m_strName; } //이름 설정
	Player();
	~Player();
};

