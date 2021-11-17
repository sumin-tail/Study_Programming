#include <iostream>
#include<string>
using namespace std;
//
//��ȣ �� ��° �ڸ����� 1�� ��� �޴�����ȣ ->11�ڸ�
//��ȣ �� ��° �ڸ����� 2�� ��� �����ȣ -> 9�ڸ�
//��ȣ �� ��° �ڸ����� 3~6�� ��� ������ȣ -> 10�ڸ�

#define ADDEMPTY 3

enum NUMBERTYPE
{
	CAPITAL = 9,
	PROVINCE,
	PHONE
};

class PhoneNumber
{
private:
	char* number;
	NUMBERTYPE type;
public:

	PhoneNumber()
	{
		string str;
		int j = 0;
		while (true)
		{
			cout << "��ȭ��ȣ �Է� : ";
			cin >> str;
			if (str[1] == '1' && str.length() == PHONE)
			{
				HyphenAdd(str, PHONE);
				break;
			}
			else if (str[1] == '2' && str.length() == CAPITAL)
			{
				HyphenAdd(str, CAPITAL);
				break;
			}
			else if ((str[1] >= '3' && str[1] <= '6') && str.length() == PROVINCE)
			{
				HyphenAdd(str, PROVINCE);
				break;
			}
			else
			{
				cout << "��ȣ�� �ߺ� �Է��ϼ̽��ϴ�." << endl;
			}
		}
	}
	~PhoneNumber()
	{
		cout << "�ϼ��� ��ȣ : " << number << endl;
		delete[] number;
	}

//if (i == 2 || i == 6) CAPITAL 9
//if (i == 3 || i == 7) PROVINCE 10
//if (i == 3 || i == 8) PHONE 11

	void HyphenAdd(string str, NUMBERTYPE type)
	{
		int j = 0;

		int addPoint = 3;
		if (type == CAPITAL)
			addPoint = 2;

		number = new char[type + ADDEMPTY];
		for (int i = 0; i < type + ADDEMPTY; i++)
		{
			if (i == addPoint || i == type - ADDEMPTY)
			{
				number[i] = '-';
			}
			else
			{
				number[i] = str[j];
				j++;
			}
		}
	}

};

void main()
{
	PhoneNumber st1;
}
