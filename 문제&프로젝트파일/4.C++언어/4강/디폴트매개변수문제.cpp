#include<iostream>
using namespace std;

//�������� ���� �ð��� �Է¹޾� �������� �� �ӱ��� ����Ͻÿ�.
//(�⺻��(Default value) �ð� : 8, �ñ� : 7500)
//
//1���� �Է¹��� �������� ���� ���ϴ� Class�� ����ÿ�
//(�⺻��(Default value) 10)
//
//���ڸ� �Է¹޾� �������� ����ϴ� Class�� ����ÿ�
//(�⺻��(Default value) 2�� ~9��)


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
	cout << "1 ~ " << n << " �� �� : " << Sum << endl;
}

void Func::Gugudan(int start, int end)
{
	for (int j = 0; j <= 9; j++)
	{
		for (int i = start; i <= end; i++)
		{
			if (j == 0)
				cout << "===" << i << "��===\t";
			else
				cout << i << " x " << j << " = " << i * j << "\t";
		}
		cout << endl;
	}
	
}

void Func::TimeToCoin(int day, int time, int coin)
{
	cout << "�ñ� : " << coin <<endl;
	cout << "�ð� : " << time << "�ð�	�ϼ� : " << day << " ��" << endl;
	cout << "�޿� : " << coin*time*day << endl;
}

void Menu() 
{
	system("cls");
	cout << "1. �ñ� ���" << endl;
	cout << "2. 1���� x�� ������ ��" << endl;
	cout << "3. ������ ���" << endl;
	cout << "4. ����" << endl;
	cout << "�Է� : ";
}

int Check() 
{
	int num;
	while (true)
	{
		system("cls");
		cout << "���� ���� ���� �Ͻðڽ��ϱ�?" << endl;
		cout << "(1.Yes) (2.No)" << endl;
		cin >> num;
		if (num == 1 || num == 2)
		{
			return num;
		}
		cout << "�߸� �Է� �ϼ̽��ϴ�." << endl;
		cout << "�ٽ� �Է��� �ּ���." << endl;
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
		case 1: //�ñ� ���
			while (true)
			{
				system("cls");
				cout << "���� �ٹ� �ϼ̽��ϱ�? ";
				cin >> day;
				cout << "�ð��� �ӱ��� �Է� �Ͻðڽ��ϱ�?" << endl;
				cout << "(1.Yes) (2.No)" << endl;
				cin >> Select;
				if (Select == 1 || Select == 2)
				{
					break;
				}
				cout << "�߸� �Է� �ϼ̽��ϴ�." << endl;
				cout << "�ٽ� �Է��� �ּ���." << endl;
				system("pause");
			}
			switch (Select)
			{
			case 1:
				cout << "�ñ� �Է� : " << endl;
				cin >> coin;
				cout << "�ð� �Է� : " << endl;
				cin >> time;
				a.TimeToCoin(day, time ,coin);
				break;
			case 2:
				a.TimeToCoin(day);
				break;
			}
			break;
		case 2://���� ��
			switch (Check())
			{
			case 1:
				cout << "�ִ� �� �Է� : (����:10)" << endl;
				cin >> Select;
				a.AddNum(Select);
				break;
			case 2:
				a.AddNum();
				break;
			}
			break;
		case 3://������ ���
			switch (Check())
			{
			case 1:
				while (true)
				{
					cout << "�ּ� �� �Է� : ";
					cin >> Select;
					cout << "�ִ� �� �Է� : ";
					cin >> Select2;
					if (Select <= Select2)
					{
						break;
					}
					cout << "�ִ� ���� �ּ� ������ �۽��ϴ�." << endl;
					cout << "�ٽ� �Է��� �ּ���." << endl;
				}
				a.Gugudan(Select, Select2);
				break;
			case 2:
				a.Gugudan();
				break;
			}
			break;
		case 4://����
			return;
		default://�ٸ� ���ڵ��������� �׳� �����
			break;
		}
		system("pause");
	}
}
