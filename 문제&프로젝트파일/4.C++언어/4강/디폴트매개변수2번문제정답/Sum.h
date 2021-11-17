#pragma once
#include<iostream>
using namespace std;

class Sum
{
private:
	int m_iSum;
	int m_iNum;
public:
	void SetSum(int Num = 10);
	void ShowSum();
	Sum();
	~Sum();
};

