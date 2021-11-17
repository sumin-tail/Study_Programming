#include "Sum.h"



Sum::Sum()
{
}

void Sum::SetSum(int Num)
{
	m_iNum = Num;
	m_iSum = 0;
	for (int i = 1; i <= m_iNum; i++)
		m_iSum += i;
}
void Sum::ShowSum()
{
	cout << "1 ~ " << m_iNum << " ÃÑ ÇÕ : " << m_iSum << endl;
}

Sum::~Sum()
{
}
