#pragma once
#include "Mecro.h"
#include "Character.h"
#include "MapDraw.h"
#include "Shop.h"

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

	//--다른곳에서 쓰일 일이 없는 함수들--
	void Menu(); //메뉴
	void GameSetting(STARTTYPE type); //게임세팅 - New 인지 Load 인지 체크해서 설정
	void PlayerSetting(); //플레이어 세팅
	void SaveFileList(); //세이프 파일 리스트 출력
protected:
public:
	void MainMenu(); //메인(시작) 메뉴
};

