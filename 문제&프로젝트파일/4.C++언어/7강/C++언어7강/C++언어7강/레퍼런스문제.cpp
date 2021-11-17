#include <iostream>
#include <string>
using namespace std;

//두 개의 정수를 입력 받아 큰 수를 출력하시오
void Max(int num1, int num2, int& answer)
{
	if (num1 > num2)
	{
		answer = num1;
	}
	else
	{
		answer = num2;
	}
}


//-하나의 수를 입력 받아 1 ~100사이의 해당
//수의 배수 합을 구하시오(5입력시 1 ~100사이의 5의배수를 모두 합산)
void Sum(int num, int& answer)
{
	int maxSum = 0;
	for (int i = 1; i*num <= 100; i++)
	{
		maxSum += num * i;
	}
	answer = maxSum;
}

//- 하나의 숫자를 입력 받아 거꾸로 출력하시오
void Backing(int num, int& answer)
{
	int backNum = 0;

	for (; num >= 1;)
	{
		backNum = backNum * 10;
		backNum += num % 10;
		num = num/10;
	}
	answer = backNum;
}

//(main에서만 cin,cout사용,return사용금지)
void main()
{
	int a;
	int b;
	int answer;

	cout << "1. 두 개의 정수를 입력 : ";
	cin >> a >> b;
	Max(a, b, answer);
	cout << a <<"과 " << b<<"중 큰 수는"<< answer << endl;

	cout << "2. 정수 하나 입력 : ";
	cin >> a;
	Sum(a, answer);
	cout << "1~ 100 사이 " << a << "배수의 합은 :" << answer << endl;

	cout << "3. 정수 하나 입력 : ";
	cin >> a;
	Backing(a, answer);
	cout << a << "의 거꾸로 수 : "<< answer << endl;
}
