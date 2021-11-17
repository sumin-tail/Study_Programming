#include "Computer.h"

//생성자
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
		cout << "===== 환 영 합 니 다 =====" << endl;
		cout << "1. 컴퓨터 상태" << endl;
		cout << "2. 기 능" << endl;
		cout << "3. off" << endl;
		cout << "입력 >>>>";
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
		case 3://종료
			End();
			return;
		default:
			break;
		}
	}
}

void Computer::Stats()
{
	cout << "제 품 명 : " << name << endl;
	if (state == ON)
		cout << "현재 상태 : ON"  << endl;
	else
	    cout << "현재 상태 : OFF" << state << endl;
	cout << "그래픽카드 : " << graphics_card << endl;
	cout << "C P U : " << cpu << endl;
	cout << "메모리 : " << memory << "G" << endl;
	system("pause");
}

void Computer::Play()
{
	int select;
	while (true)
	{
		system("cls");
		cout << "1. 계 산 기" << endl;
		cout << "2. 메 모 장" << endl;
		cout << "3. 그 림 판" << endl;
		cout << "4. 돌아가기" << endl;
		cout << "입력 >>>>" ;
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
		case 4://돌아가기
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
		cout << "off " << i<< "초 전" << endl;
		Sleep(1000);
	}
}