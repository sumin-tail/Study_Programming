#pragma once
#include "News.h"
#include "Person.h"

//1.고객등록 : 고객정보(이름)을 등록
//2.News 전송 : 최신 업데이트 뉴스를 적용
//3.News 업데이트 : 최신 정보를 작성, 작성 시간 보관
//4.News 시청 : 전송된 News를 고객들이 시청

void menu()
{
	int select;
	while (true)
	{
		system("cls");
		cout << "===Atents News===" << endl;
		cout << "1. 고객 등록" << endl;
		cout << "2. News 전송" << endl;
		cout << "3. News 업데이트" << endl;
		cout << "4. News 시청" << endl;
		cout << "선택 :" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			News::get_instance()->Add(new Person);
			break;
		case 2:
			News::get_instance()->Update();
			break;
		case 3:
			News::get_instance()->NewsUpdate(); 
			break;
		case 4:
			News::get_instance()->Print();
			break;
		default:
			break;
		}
	}
}

void main()
{
	menu();
}

