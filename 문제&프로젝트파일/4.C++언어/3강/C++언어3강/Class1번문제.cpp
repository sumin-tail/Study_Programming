#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

#define Nstart 2
#define Nend 9

typedef class math
{
private:
	int startNum;
	int endNum;
public:
	void Check();
	void SetNum(int _startNum, int _endNum);
	void Print();
}Math;

void Math::SetNum(int _startNum, int _endNum) 
{
	startNum = _startNum;
	endNum = _endNum;
}

void Math::Print()
{
	for (int i = startNum; i <= endNum; i++)
	{
		cout << "======="<< i <<"��=======\t";
	}
	cout << endl;
	for (int i = Nstart - 1; i <= Nend; i++)
	{
		for (int j = startNum; j <= endNum; j++)
		{
			cout << "    " << j << " x " << i << " = " << i * j << "\t\t";
		}
		cout << endl;
	}
}

void Math::Check()
{
	int start;
	int end;
	while (1)
	{
		//����ó�� �κе� Ŭ���� �ȿ� ���� ����
		cout << "���� �� �Է� :";
		cin >> start;
		cout << "�� �� �Է� :";
		cin >> end;

		if (start > end)
		{
			cout << "���� ���� �� �ܺ��� Ů�ϴ�." << endl;
		}
		else if (start < Nstart || start > Nend)
		{
			cout << "���� ���� 2���� �۰ų� 9���� Ů�ϴ�." << endl;
		}
		else if (end < Nstart || end > Nend)
		{
			cout << "�� ���� 2���� �۰ų� 9���� Ů�ϴ�." << endl;
		}
		else
		{
			SetNum(start, end);
			return;
		}
		system("pause");
	}
}

//�������� �Է¹ް� ����ϴ� Ŭ����
void main()
{
	Math M1;
	M1.Check();
	M1.Print();
}
