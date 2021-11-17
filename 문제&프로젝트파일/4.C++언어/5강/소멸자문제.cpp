#include <iostream>
#include<string>
using namespace std;
//
//번호 두 번째 자리수가 1인 경우 휴대폰번호 ->11자리
//번호 두 번째 자리수가 2인 경우 서울번호 -> 9자리
//번호 두 번째 자리수가 3~6인 경우 지역번호 -> 10자리

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
			cout << "전화번호 입력 : ";
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
				cout << "번호를 잘봇 입력하셨습니다." << endl;
			}
		}
	}
	~PhoneNumber()
	{
		cout << "완성된 번호 : " << number << endl;
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
