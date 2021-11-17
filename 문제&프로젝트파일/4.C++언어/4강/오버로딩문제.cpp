#include<iostream>
using namespace std;
#define MAXLEN 5

//오버로딩을 이용하여 두정수를 입력시 앞의정수에 대한 뒤의 정수 승을 구하여 반환하는 함수를 만들고
//문자와 정수를 입력시 문자에서 정수만큼의 다음 문자를
//출력하는 함수를 만드시오.
//(승을 구할시 승에 해당하는 숫자가 1보다 작으면 안됨)
//(문자에서 해당 정수만큼 이동시 z를 넘어갈경우 남은 수 만큼 a부터 시작)
//(ex > y -> 3 = b)
//
//오버로딩을 이용하여 인자값 문자열 하나일 경우 문자열을 뒤집는 함수를 만드시고 문자열이 2개일경우 두 문자열을 합치는 함수를 만드시오.(string)
//
//오버로딩을 이용하여 5개의 숫자를 입력시 오름차순 정렬
//5개의 문자를 입력시 내림차순 정렬을 하시오(char[])

class Test
{
public:
	void Quiz1(int num, int num2);
	void Quiz1(char num, int num2);
	void Quiz2(string str);
	void Quiz2(string str, string str2);
	void Quiz3(int iarr[]);
	void Quiz3(char charr[]);
};

void Test::Quiz1(int num, int num2)
{
	if (num2<=0)
	{
		cout << num2 <<"은 1보다 작습니다." << endl;
		return;
	}
	int sum = num;
	for (int i = 1; i < num2; i++)
	{
		sum *= num;
	}
	cout << num << "의" << num2 << " 승 : " << sum << endl;
}
void Test::Quiz1(char ch, int num2)
{ 
	//97부터 122까지
	char tmp = ch;
	tmp += num2;

	while (tmp > 'z')
	{
		tmp -= 26;
	}

	cout << ch << " >> " << num2 << " : " << tmp << endl;
}

void Test::Quiz2(string str)// 문자열 바꾸기 처음/ 마지막 - 처음+1/마지막-1 순으로 주르륵 > 길이의 절반만큼
{
	cout << str << " -> ";
	char chtmp;
	for (int i = 0; i < str.size()/2 ; i++)
	{
		chtmp = str[i];
		str[i] = str[str.size()-1-i]; //*주의!! 배열의 사이즈가 3 이라면 배열의 마지막 인덱스는 사이즈-1 임!
		str[str.size() - 1 - i] = chtmp;
	}
	cout << str << endl;
}
void Test::Quiz2(string str, string str2)
{
	cout << str << " + " << str2 << " = " << str + str2 << endl;
}

void Test::Quiz3(int iarr[]) //내림차순으로
{
	int temp;
	for (int i = 0; i < MAXLEN - 1; i++)
	{
		for (int j = i + 1; j < MAXLEN; j++)
		{
			if (iarr[i] < iarr[j])
			{
				temp = iarr[i];
				iarr[i] = iarr[j];
				iarr[j] = temp;
			}
		}
	}

	for (int i = 0; i < MAXLEN; i++)
	{
		cout << "iarr[" << i << "] : " << iarr[i] << endl;
	}

}
void Test::Quiz3(char charr[]) //오름차순으로
{
	char temp;
	for (int i = 0; i < MAXLEN - 1; i++)
	{
		for (int j = i + 1; j < MAXLEN; j++)
		{
			if (charr[i] > charr[j])
			{
				temp = charr[i];
				charr[i] = charr[j];
				charr[j] = temp;
			}
		}
	}
	for (int i = 0; i < MAXLEN; i++)
	{
		cout << "charr[" << i << "] : " << charr[i] << endl;
	}
}

void main()
{
	Test t;
	int num, num2;
	char ch;
	string str1, str2;

	int iarr[MAXLEN];
	char charr[MAXLEN];

	cout << "1-1" << endl;
	cout << "정수 2개 입력 : ";
	cin >> num >> num2;
	t.Quiz1(num, num2);
	cout << endl;

	cout << "1-2" << endl;
	cout << "단일문자와 정수 입력 : ";
	cin >> ch >> num2;
	t.Quiz1(ch, num2);
	cout << endl;

	cout << "2-1" << endl;
	cout << "문자열 하나 입력 : ";
	cin >> str1;
	t.Quiz2(str1);
	cout << endl;

	cout << "2-2" << endl;
	cout << "문자열 두개 입력 : ";
	cin >> str1 >> str2;
	t.Quiz2(str1, str2);
	cout << endl;

	cout << "3-1" << endl;
	cout << "숫자 5개 입력 : ";
	for (int i = 0; i < MAXLEN; i++)
	{
		cin >> iarr[i];
	}
	t.Quiz3(iarr);
	cout << endl;

	cout << "3-2" << endl;
	cout << "단일문자 5개 입력 : ";
	for (int i = 0; i < MAXLEN; i++)
	{
		cin >> charr[i];
	}
	t.Quiz3(charr);
	cout << endl;

}

