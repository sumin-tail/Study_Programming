#include<iostream>
using namespace std;

class Point
{
private:
	int m_ix;
	int m_iy;
public:
	Point() {}
	void SetNum(int x, int y)
	{
		m_ix = x;
		m_iy = y;
	}
	void ShowNum() 
	{
		cout << "x = " << m_ix << endl;
		cout << "y = " << m_iy << endl;
		m_ix = 30;
		m_iy = 40;
		cout << "x = " << m_ix << endl;
	}
	int* GetNum()
	{
		return &m_ix;
	}
};

void main()
{
	Point p;
	p.SetNum(10, 20);
	p.ShowNum();
	*(p.GetNum()) = 100;
	p.ShowNum();
}

//const	int m_ix > 생성과 동시에 상수로 만들어서 값을 변경하지 못하게 함
//void ShowNum() const > 해당 함수내에서 변수의 값을 변경하지 못하게 함
//const int* GetNum() > 주로를 리턴하지만 접근하지 못하게 막음
