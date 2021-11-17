#include "Computer.h"

//������
Computer::Computer() 
{
	name = "Atents";
	state = ON;
	graphics_card = "GTX990";
	cpu = "i7";
	memory = 8;
}

void Computer::Menu()
{
	int select;
	while (true)
	{
		system("cls");
		cout << "===== ȯ �� �� �� �� =====" << endl;
		cout << "1. ��ǻ�� ����" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. off" << endl;
		cout << "�Է� >>>>";
		cin >> select;

		switch (select)
		{
		case 1:
			system("cls");
			Stats();
			break;
		case 2:
			Play();
			break;
		case 3://����
			End();
			return;
		default:
			break;
		}
	}
}

void Computer::Stats()
{
	cout << "�� ǰ �� : " << name << endl;
	if (state == ON)
		cout << "���� ���� : ON"  << endl;
	else
	    cout << "���� ���� : OFF" << state << endl;
	cout << "�׷���ī�� : " << graphics_card << endl;
	cout << "C P U : " << cpu << endl;
	cout << "�޸� : " << memory << "G" << endl;
	system("pause");
}

void Computer::Play()
{
	int select;
	while (true)
	{
		system("cls");
		cout << "1. �� �� ��" << endl;
		cout << "2. �� �� ��" << endl;
		cout << "3. �� �� ��" << endl;
		cout << "4. ���ư���" << endl;
		cout << "�Է� >>>>" ;
		cin >> select;
		switch (select)
		{
		case 1:
			Calc();
			break;
		case 2:
			Notepad();
			break;
		case 3:
			Mspaint();
			break;
		case 4://���ư���
			return;
		default:
			break;
		}
	}
}

void Computer::Calc()
{
	system("calc");
}

void Computer::Notepad()
{
	system("notepad");
}

void Computer::Mspaint()
{
	system("mspaint");
}

void Computer::End()
{
	for (int i = 5; i > 0 ; i--)
	{
		cout << "off " << i<< "�� ��" << endl;
		Sleep(1000);
	}
}