#pragma once
#include<iostream>
using namespace std;
class GuGuDan
{
private:
	int m_iStartNum;
	int m_iEndNum;
public:
	void SetGuGuDan(int StartNum = 2,int EndNum = 9);
	void ShowGuGuDan();
	GuGuDan();
	~GuGuDan();
};

