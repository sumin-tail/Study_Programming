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
		cout << "======="<< i <<"단=======\t";
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
		//예외처리 부분도 클래스 안에 들어가면 좋음
		cout << "시작 단 입력 :";
		cin >> start;
		cout << "끝 단 입력 :";
		cin >> end;

		if (start > end)
		{
			cout << "시작 단이 끝 단보다 큽니다." << endl;
		}
		else if (start < Nstart || start > Nend)
		{
			cout << "시작 단이 2보다 작거나 9보다 큽니다." << endl;
		}
		else if (end < Nstart || end > Nend)
		{
			cout << "끝 단이 2보다 작거나 9보다 큽니다." << endl;
		}
		else
		{
			SetNum(start, end);
			return;
		}
		system("pause");
	}
}

//구구단을 입력받고 출력하는 클래스
void main()
{
	Math M1;
	M1.Check();
	M1.Print();
}
