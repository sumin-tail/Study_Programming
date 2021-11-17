#include "GuGuDan.h"



GuGuDan::GuGuDan()
{
}

void GuGuDan::SetGuGuDan(int StartNum, int EndNum)
{
	if (StartNum < 2 || StartNum > 9)
		cout << "StartNum이 2보다 작습니다.";
	if (EndNum < 2 || EndNum > 9)
		cout << "EndNum이 2보다 작습니다.";
	if (StartNum > EndNum)
		cout << "StartNum 이 EndNum보다 큽니다.";
	m_iEndNum = EndNum;
	m_iStartNum = StartNum;
}
void GuGuDan::ShowGuGuDan()
{
	for (int i = m_iStartNum; i <= m_iEndNum; i++)
	{
		cout << "========" << i << "단========" << endl;
		for (int j = 1; j <= 9; j++)
		{
			cout << i << " x " << j << " = " << i*j << endl;
		}
		cout << "==============================" << endl;
	}
}

GuGuDan::~GuGuDan()
{
}
