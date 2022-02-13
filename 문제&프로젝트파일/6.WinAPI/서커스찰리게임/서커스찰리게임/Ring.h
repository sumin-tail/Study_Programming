#pragma once
#include "BitMap.h"
#include "서커스찰리게임.h"

class Ring
{
protected: // 상속해서 변경할 친구들은 프로텍티드
	BitMap* m_Ring; //링
	float m_PosX; //좌표
	int m_Width;//가로사이즈
	int m_Height;//세로사이즈
	int m_MoveRing;//애니메이션
	float m_Animationtimer; //애니메이션 시간계산
	RECT m_ScoreCollider; //스코어 콜라이더
	RECT m_DeadCollider; //사망콜라이더
	bool m_ScoreUp;//점수를 증가 시켜야하는지 아닌지
public:
	Ring();
	~Ring();
	virtual void Init(HDC hdc);
	virtual void Update(float deltaTime, float speed, float pos);// 업데이트
	void AnimationUpdate(float deltaTime);
	virtual void BackRing(HDC hdc);//링 뒤쪽 출력
	virtual void FrontRing(HDC hdc);//링 앞쪽 출력
	bool DeadColliderCheck(RECT PlayerRect); //링에 닿았는지 안 닿았는지 체크
	void ScoreColliderCheck(RECT PlayerRect); //스코어 상승 인지 아닌지 체크
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
	void Update(float deltaTime, float speed, float pos);// 업데이트
	void BackRing(HDC hdc);//링 뒤쪽 출력
	void FrontRing(HDC hdc);//링 앞쪽 출력
	void ScoreUP();
	void Reset();
};