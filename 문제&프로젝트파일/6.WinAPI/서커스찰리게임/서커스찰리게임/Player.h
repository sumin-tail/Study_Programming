#pragma once
#include "��Ŀ����������.h"
#include "BitMap.h"


enum PLAYER //�÷��̾� ����
{
	PLAYER_IDLE, //������
	PLAYER_MOVE,//�����̴���
	PLAYER_JUMP, //����
	PLAYER_DEAD, //��� - �浹��
	PLAYER_CLEAR //���� ����
};

//�÷��̾� Ŭ���� -> ������ ���� �̹��� ���ҽ��� �÷��̾� ���ҽ���
//������ ���� ��� ������ ������, ���ھ� 
class Player
{
private:
	PLAYER m_PlayerState;
	BitMap* m_PlayerImage; //�÷��̾� �̹���
	int m_Life; //�÷��̾� ������ 
	int m_MovePlayer; // �����̴� �÷��̾� �̹���
	bool m_jump;
	float m_PosX;//�÷��̾� X ��ǥ
	float m_PosY; //�÷��̾� Y ��ǥ
	int m_Width;//���λ�����
	int m_Height;//���λ�����
	float m_Speed; //�÷��̾� ���ǵ�
	float m_MovePos; //�÷��̾ �����ΰŸ�
	int m_PlayerMoveStep;//�÷��̾ ���� �ָ��� ���
	float m_Animationtimer; //�ִϸ��̼ǿ�
	float m_Keyinputtimer; //Ű��ǲ ��
	RECT m_PlayerCollider; //�÷��̾� �ݶ��̴�
public:
	Player();
	~Player();
	void Init(HDC hdc);
	void Update(float elapsed);
	void Reset();
	void Draw(HDC hdc);
	void Jump(float elapsed);
	void AnimationUpdate(float elapsed);
	void KeyinputUpdate(float elapsed);
	float GetPlayerSpeed(); //�÷��̾� ���ǵ� ����
	float GetPlayermMovePos(); //�÷��̾� �����ΰŸ� ����
	int GetLife();//�÷��̾� ���� ������ ����
	void Dead();
	void PlayerMoveStepUpdate();
	void Goal();
	RECT GetPlayerRect();
};
