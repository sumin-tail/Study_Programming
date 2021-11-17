#include<iostream>
using namespace std;

class GuGuDan
{
private:
	int StartGuGuDan;
	int EndGuGuDan;
public:
	void SetGuGuDan()
	{
		while (1)
		{
			cout << "시작 단 입력 : ";
			cin >> StartGuGuDan;
			cout << "끝 단 입력 : ";
			cin >> EndGuGuDan;
			if (StartGuGuDan < 2 || StartGuGuDan > 9)
				cout << "시작 단이 2보다 작거나 9보다 큽니다." << endl;
			else if (EndGuGuDan < 2 || EndGuGuDan > 9)
				cout << "끝 단이 2보다 작거나 9보다 큽니다." << endl;
			else if (StartGuGuDan > EndGuGuDan)
				cout << "시작 단이 끝 단보다 큽니다." << endl;
			else
				break;
			system("pause");
		}
	}
	void ShowGuGuDan()
	{
		for (int j = 0; j <= 9; j++) // 0부터 시작해서 0일때만 각 단을 출력함 
		{
			for (int i = StartGuGuDan; i <= EndGuGuDan; i++)
			{
				if (j == 0)
					cout << "=======" << i << "단=======\t";
				else
					cout << "    " << i << " x " << j << " = " << i * j << "\t\t";
			}
			cout << endl;
		}
	}
};

void main()
{
	GuGuDan Gu1;
	Gu1.SetGuGuDan();
	Gu1.ShowGuGuDan();
}