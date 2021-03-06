#include "Quiz.h"

Quiz::Quiz()
{
}

void Quiz::Quiz1(int inum1, int inum2)
{
	int sum = 1;
	if (inum2 >= 1)
	{
		cout << "Quiz1(정수2개)" << endl;
		for (int i = 0; i < inum2; i++)
			sum *= inum1;
		cout << inum1 << "의 " << inum2 << "승 : " << sum << endl;
	}
	else
	{
		cout << inum2 << "은 1보다 작습니다." << endl;
	}
}
void Quiz::Quiz1(char ch, int inum)
{
	char Endchar,Startchar;
	char ch2;
	int inum2 = inum;
	if ((ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z')) //대문자와 소문자를 따로 구분해서
	{
		if (ch >= 'a' && ch <= 'z') //소문자의경우 스타트와 엔드를 a와 z로 초기화
		{
			Startchar = 'a';
			Endchar = 'z';
		}
		else if (ch >= 'A' && ch <= 'Z')//대문자의경우 스타트와 엔드를 A와 Z로 초기화
		{
			Startchar = 'A';
			Endchar = 'Z';
		}
		ch2 = ch + inum; 
		if (ch2 > Endchar) //만약 엔드보다 크다면
		{
			inum = ch2 - Endchar; //inum에 ch2 - Endchar 한 값을 넣음
			ch2 = Startchar + (inum-1); //ch2에 Startchar + (inum-1)넣음 
		}
		cout << ch << " >> " << inum2 << " : " << ch2 << endl;
	}
	else
		cout << "해당 문자가 알파벳이 아닙니다." << endl;
}
void Quiz::Quiz2(string str)
{
	string str2;
	for (int i = 1; i <= str.length(); i++)
		str2 += str.substr(str.length() - i, 1); //문자열을 끝에서부터 하나씩 잘라서 반대편 문자열에 넣음
	cout << str << " -> " << str2 << endl;
}
void Quiz::Quiz2(string str1, string str2)
{
	cout << str1 << " + " << str2 << " : " << str1 + str2 << endl;
}
void Quiz::Quiz3(int iarr[],int size)
{
	int tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (iarr[i] < iarr[j])
			{
				tmp = iarr[i];
				iarr[i] = iarr[j];
				iarr[j] = tmp;
			}
		}
	}
	cout << "=============iarr=============" << endl;
	for (int i = 0; i < size; i++)
		cout << "iarr[" << i << "] : " << iarr[i] << endl;
}
void Quiz::Quiz3(char charr[],int size)
{
	char tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (charr[i] > charr[j])
			{
				tmp = charr[i];
				charr[i] = charr[j];
				charr[j] = tmp;
			}
		}
	}
	cout << "=============charr=============" << endl;
	for (int i = 0; i < size; i++)
		cout << "charr[" << i << "] : " << charr[i] << endl;
}

Quiz::~Quiz()
{
}
