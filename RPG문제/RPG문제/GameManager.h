#pragma once
#include "Mecro.h"
#include "Character.h"
#include "MapDraw.h"
#include "Shop.h"

enum FILESTATE
{
	FILESTATE_SAVE,
	FILESTATE_LOAD
};

//언제나 디파인과 enum 활용하기!! 
//상속을 활용하기 무기- 무기종류 로 활용하면 될듯
//변수 이름 잘 짓기
class GameManager
{
private:
	//게임 매니저가 가지고있을 변수들- 플레이어 ,몬스터,상점,맵드로우
	//플레이어와 몬스터가 가지고있는 변수들이 같음 = 굳이 몬스터 클래스를 따로 생성하지 않고 플레이어 클래스를 활용하는 방식으로 ->플레이어 클래스보다는 캐릭터 클래스로
	Character* m_Player; //플레이어
	Character* m_Monster; //몬스터
	Shop m_Shop; //상점
	MapDraw m_MapDrawManager; //드로우를 위한 변수
	string m_PlayerFileName;//플레이어 파일 이름
	string m_MonsterFileName;//몬스터 파일 이름
	int m_MonsterCount; //몬스터 종류(갯수)

	//--다른곳에서 쓰일 일이 없는 함수들--//
	void Menu(); //메뉴
	void GameSetting(STARTTYPE type); //게임세팅 - New 인지 Load 인지 체크해서 설정
	void Dongeon(); //던전 메뉴 출력
	//-파일 관련-//
	bool Load(STARTTYPE StartType); //파일 로드
	bool FileList(FILESTATE State); //파일리스트 출력
	bool FileOpenCheck(string filename); //해당 파일이 있는지 (열리는지)확인
	//-전투-/
	void Fight(Character* Player, Character* Monster);//플레이어와 몬스터 싸움
public:
	//-생성/소멸자-//
	GameManager();
	~GameManager();
	//--//
	void MainMenu(); //메인(시작) 메뉴
};

