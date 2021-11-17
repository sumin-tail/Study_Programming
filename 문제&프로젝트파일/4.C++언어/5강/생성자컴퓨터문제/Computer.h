#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

//(main에서는 하나의 맴버함수만 사용할 것)
//(컴퓨터 정보는 생성자에서 초기화)
//계산기 호출 명령어 = system("calc");
//메모장 호출 명령어 = system("notepad");
//그림판 호출 명령어 = system("mspaint");

//배운거 활용하기 *자주해야 손에 익는다

enum POWER
{
	OFF,
	ON
};

class Computer
{
private:
	string name;
	POWER state;
	string graphics_card;
	string cpu;
	int memory;

public:
	//생성자
	Computer();
	//시작메뉴
	void Menu();
	void Play();
	//상태
	void Stats();
	//기능
	void Calc();
	void Notepad();
	void Mspaint();
	void End();
};

