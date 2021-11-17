#pragma once
#include"Mecro.h"
#include"MapDraw.h"

#define DEFAULT_UNDO 5 //����Ʈ �����Ⱚ 5

struct Point
{
	int m_ix;
	int m_iy;
};

class Player
{
private:
	MapDraw m_DrawManager; //�� ��ο� �Ŵ���
	string m_strName; //�÷��̾� �̸�
	Point* m_pStoneList; //�� �� ����Ʈ
	Point m_Cursor; //Ŀ�� ��ǥ 
	int m_iStoneCount; 
	string m_strCursorIcon; //Ŀ�� ������
	string m_strStoneIcon; //�� ������
	bool m_bMyWindState;//�¸� ����
	int m_iUndo;//������
public:
	int NextStoneCheck(int x,int y,int addx,int addy, int Width, int Height); //���� �� üũ
	bool WinCheck(int Width,int Height); //�¸� üũ
	void DrawStone(int x, int y); //�� �׸��� �Լ�
	void AllStoneDraw();
	bool CompareStone(int x, int y);
	void CreateStone();
	void Move(char ch,int Width,int Height);
	void DrawCursor();
	void EraseCursor(int Width, int Height);
	void PlayerSet(int Width, int Height);
	void DeleteStone();
	void Undo(int Width,int Height);
	inline void DownUndo() { m_iUndo--; }//������ ī��Ʈ ����
	inline void SetUndo(int undo) { m_iUndo = undo; } //������ Ƚ�� ����
	inline int GetUndo(){ return m_iUndo; }  //������ Ƚ�� ��ȯ
	inline Point GetCursor() { return m_Cursor; } //Ŀ����ǥ��ȯ
	inline string GetName() { return m_strName; } //�̸� ��ȯ
	inline void SetStoneIcon(string Icon) { m_strStoneIcon = Icon; } //�� ������ ����
	inline void SetCursorIcon(string Icon) { m_strCursorIcon = Icon; } //Ŀ�������� ����
	inline void SetName(){ cin >> m_strName; } //�̸� ����
	Player();
	~Player();
};

