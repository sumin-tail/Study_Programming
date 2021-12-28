#pragma once
#include "News.h"
#include "Person.h"

//1.����� : ������(�̸�)�� ���
//2.News ���� : �ֽ� ������Ʈ ������ ����
//3.News ������Ʈ : �ֽ� ������ �ۼ�, �ۼ� �ð� ����
//4.News ��û : ���۵� News�� ������ ��û

void menu()
{
	int select;
	while (true)
	{
		system("cls");
		cout << "===Atents News===" << endl;
		cout << "1. �� ���" << endl;
		cout << "2. News ����" << endl;
		cout << "3. News ������Ʈ" << endl;
		cout << "4. News ��û" << endl;
		cout << "���� :" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			News::get_instance()->Add(new Person); //���߰�
			break;
		case 2:
			News::get_instance()->Update(); //���� ����
			break;
		case 3:
			News::get_instance()->NewsUpdate(); //���� ���� ������Ʈ
			break;
		case 4:
			News::get_instance()->Print(); //����Ʈ
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

