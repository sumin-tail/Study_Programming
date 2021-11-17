#include<iostream>
using namespace std;

//종업원이 일한 시간을 입력받아 종업원의 총 임금을 출력하시오.
//(기본값(Default value) 시간 : 8, 시급 : 7500)
//
//1부터 입력받은 수까지의 합을 구하는 Class를 만드시오
//(기본값(Default value) 10)
//
//숫자를 입력받아 구구단을 출력하는 Class를 만드시오
//(기본값(Default value) 2단 ~9단)


class Func
{
public:
	void AddNum(int num = 10);
	void Gugudan(int start = 2, int end = 9);
	void TimeToCoin(int day, int time = 8, int coin = 7500);
};

void Func::AddNum(int n) 
{
	int Sum = 0;
	for (int i = 1; i <= n; i++)
		Sum += i;
	cout << "1 ~ " << n << " 총 합 : " << Sum << endl;
}

void Func::Gugudan(int start, int end)
{
	for (int j = 0; j <= 9; j++)
	{
		for (int i = start; i <= end; i++)
		{
			if (j == 0)
				cout << "===" << i << "단===\t";
			else
				cout << i << " x " << j << " = " << i * j << "\t";
		}
		cout << endl;
	}
	
}

void Func::TimeToCoin(int day, int time, int coin)
{
	cout << "시급 : " << coin <<endl;
	cout << "시간 : " << time << "시간	일수 : " << day << " 일" << endl;
	cout << "급여 : " << coin*time*day << endl;
}

void Menu() 
{
	system("cls");
	cout << "1. 시급 계산" << endl;
	cout << "2. 1부터 x수 까지의 합" << endl;
	cout << "3. 구구단 출력" << endl;
	cout << "4. 종료" << endl;
	cout << "입력 : ";
}

int Check() 
{
	int num;
	while (true)
	{
		system("cls");
		cout << "최종 값을 변경 하시겠습니까?" << endl;
		cout << "(1.Yes) (2.No)" << endl;
		cin >> num;
		if (num == 1 || num == 2)
		{
			return num;
		}
		cout << "잘못 입력 하셨습니다." << endl;
		cout << "다시 입력해 주세요." << endl;
		system("pause");
	}
}

void main()
{
	Func a;
	int Select, Select2;
	int day, time, coin;
	while (1)
	{
		Menu();
		cin >> Select;

		system("cls");
		switch (Select)
		{
		case 1: //시급 계산
			while (true)
			{
				system("cls");
				cout << "몇일 근무 하셨습니까? ";
				cin >> day;
				cout << "시간과 임금을 입력 하시겠습니까?" << endl;
				cout << "(1.Yes) (2.No)" << endl;
				cin >> Select;
				if (Select == 1 || Select == 2)
				{
					break;
				}
				cout << "잘못 입력 하셨습니다." << endl;
				cout << "다시 입력해 주세요." << endl;
				system("pause");
			}
			switch (Select)
			{
			case 1:
				cout << "시급 입력 : " << endl;
				cin >> coin;
				cout << "시간 입력 : " << endl;
				cin >> time;
				a.TimeToCoin(day, time ,coin);
				break;
			case 2:
				a.TimeToCoin(day);
				break;
			}
			break;
		case 2://숫자 합
			switch (Check())
			{
			case 1:
				cout << "최대 값 입력 : (현재:10)" << endl;
				cin >> Select;
				a.AddNum(Select);
				break;
			case 2:
				a.AddNum();
				break;
			}
			break;
		case 3://구구단 출력
			switch (Check())
			{
			case 1:
				while (true)
				{
					cout << "최소 값 입력 : ";
					cin >> Select;
					cout << "최대 값 입력 : ";
					cin >> Select2;
					if (Select <= Select2)
					{
						break;
					}
					cout << "최대 값이 최소 값보다 작습니다." << endl;
					cout << "다시 입력해 주세요." << endl;
				}
				a.Gugudan(Select, Select2);
				break;
			case 2:
				a.Gugudan();
				break;
			}
			break;
		case 4://종료
			return;
		default://다른 숫자들어왓을때는 그냥 재실행
			break;
		}
		system("pause");
	}
}
