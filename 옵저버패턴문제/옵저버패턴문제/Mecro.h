#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

class Observer //관찰자
{
public:
	//정보 업데이트 함수, 정보 출력 함수
	Observer() {}
	virtual ~Observer() {}
	virtual void Update() abstract;
	virtual void Print() abstract;
};

class Subject //관찰대상
{
public:
	Subject() {}
	virtual ~Subject() { }
	virtual void Add(Observer*) abstract;	//옵저버 추가 함수
	virtual void Update() abstract; //옵저버 정보 업데이트 함수
};

