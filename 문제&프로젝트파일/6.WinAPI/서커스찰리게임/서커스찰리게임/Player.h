#pragma once
#include "서커스찰리게임.h"
#include "BitMap.h"


enum PLAYER //플레이어 상태
{
	PLAYER_IDLE, //서있음
	PLAYER_MOVE,//움직이는중
	PLAYER_JUMP, //점프
	PLAYER_DEAD, //사망 - 충돌함
	PLAYER_CLEAR //게임 성공
};

//플레이어 클래스 -> 가지고 있을 이미지 리소스는 플레이어 리소스만
//가지고 있을 멤버 변수는 라이프, 스코어 
class Player
{
private:
	PLAYER m_PlayerState;
	BitMap* m_PlayerImage; //플레이어 이미지
	int m_Life; //플레이어 라이프 
	int m_MovePlayer; // 움직이는 플레이어 이미지
	bool m_jump;
	float m_PosX;//플레이어 X 좌표
	float m_PosY; //플레이어 Y 좌표
	int m_Width;//가로사이즈
	int m_Height;//세로사이즈
	float m_Speed; //플레이어 스피드
	float m_MovePos; //플레이어가 움직인거리
	int m_PlayerMoveStep;//플레이어가 가장 멀리간 기록
	float m_Animationtimer; //애니메이션용
	float m_Keyinputtimer; //키인풋 용
	RECT m_PlayerCollider; //플레이어 콜라이더
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
	float GetPlayerSpeed(); //플레이어 스피드 리턴
	float GetPlayermMovePos(); //플레이어 움직인거리 리턴
	int GetLife();//플레이어 남은 라이프 리턴
	void Dead();
	void PlayerMoveStepUpdate();
	void Goal();
	RECT GetPlayerRect();
};
