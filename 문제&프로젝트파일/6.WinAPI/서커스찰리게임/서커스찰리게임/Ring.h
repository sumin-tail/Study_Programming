#pragma once
#include "BitMap.h"
#include "��Ŀ����������.h"

class Ring
{
protected: // ����ؼ� ������ ģ������ ������Ƽ��
	BitMap* m_Ring; //��
	float m_PosX; //��ǥ
	int m_Width;//���λ�����
	int m_Height;//���λ�����
	int m_MoveRing;//�ִϸ��̼�
	float m_Animationtimer; //�ִϸ��̼� �ð����
	RECT m_ScoreCollider; //���ھ� �ݶ��̴�
	RECT m_DeadCollider; //����ݶ��̴�
	bool m_ScoreUp;//������ ���� ���Ѿ��ϴ��� �ƴ���
public:
	Ring();
	~Ring();
	virtual void Init(HDC hdc);
	virtual void Update(float deltaTime, float speed, float pos);// ������Ʈ
	void AnimationUpdate(float deltaTime);
	virtual void BackRing(HDC hdc);//�� ���� ���
	virtual void FrontRing(HDC hdc);//�� ���� ���
	bool DeadColliderCheck(RECT PlayerRect); //���� ��Ҵ��� �� ��Ҵ��� üũ
	void ScoreColliderCheck(RECT PlayerRect); //���ھ� ��� ���� �ƴ��� üũ
	virtual void Reset();
	virtual void ScoreUP();
};

class LittleRing : public Ring
{
	BitMap* m_cash;
public:
	LittleRing();
	~LittleRing();
	void Init(HDC hdc);
	void Update(float deltaTime, float speed, float pos);// ������Ʈ
	void BackRing(HDC hdc);//�� ���� ���
	void FrontRing(HDC hdc);//�� ���� ���
	void ScoreUP();
	void Reset();
};