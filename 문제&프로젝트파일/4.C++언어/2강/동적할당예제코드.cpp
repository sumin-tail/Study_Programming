#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

#define STUDENTMAX 50

void main()
{
	int Select, StudentCount = 0;
	string* student[STUDENTMAX]; //string ������ �迭 50��
	while (1)
	{
		system("cls");
		cout << "===�л���������===(�л��� : " << StudentCount << "��)" << endl;
		cout << "   1.�л����" << endl;
		cout << "   2.�л����� ����" << endl;
		cout << "   3.����" << endl;
		cout << " �Է� : " << endl;
		cin >> Select;
		switch (Select)
		{
		case 1:
			if (StudentCount < STUDENTMAX) //�л��� ���� �̸��϶�
			{
				student[StudentCount] = new string; //string ���� �Ҵ�
				cout << StudentCount + 1 << "�� �л� �̸� : ";
				cin >> *student[StudentCount++];//student �迭�� StudentCount��° �ּ��� ���� �����ؼ� �����ϰ� StudentCount�� 1 �÷���
			}
			break;
		case 2: //�л� ��� ���
			for (int i = 0; i < StudentCount; i++)
				cout << i + 1 << "�� �л� : " << *student[i] << endl;
			system("pause");
			break;
		case 3: //�Ҵ� ����
			for (int i = 0; i < StudentCount; i++)
			{
				cout << i + 1 << "�� �л� : " << *student[i] << endl;
				delete student[i];
				cout << "�Ҵ� ���� �Ϸ�" << endl;
			}
			system("pause");
			return;
		}
	}
}


