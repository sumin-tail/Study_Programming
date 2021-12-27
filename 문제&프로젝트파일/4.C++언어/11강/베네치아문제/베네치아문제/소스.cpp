#include "Mecro.h"
#include "Play.h"


//만드는 순서
//게임시작 화면 만들기->배경이야기 스크롤 만들기->단어 떨어트리기->단어 맞추기(점수증가)->Stage기능 만들기->Rank시스템 만들기
//->아이템기능 추가
void main()
{
	system("mode con: cols=130 lines=35"); //콘솔창 사이즈 설정
	Play game;
	game.MainMenu();
}