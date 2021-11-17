#include "GuGuDan.h"



GuGuDan::GuGuDan()
{
}

void GuGuDan::SetGuGuDan(int StartNum, int EndNum)
{
	if (StartNum < 2 || StartNum > 9)
		cout << "StartNum�� 2���� �۽��ϴ�.";
	if (EndNum < 2 || EndNum > 9)
		cout << "EndNum�� 2���� �۽��ϴ�.";
	if (StartNum > EndNum)
		cout << "StartNum �� EndNum���� Ů�ϴ�.";
	m_iEndNum = EndNum;
	m_iStartNum = StartNum;
}
void GuGuDan::ShowGuGuDan()
{
	for (int i = m_iStartNum; i <= m_iEndNum; i++)
	{
		cout << "========" << i << "��========" << endl;
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
