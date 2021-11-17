#include <iostream>
#include <string>
using namespace std;

//�� ���� ������ �Է� �޾� ū ���� ����Ͻÿ�
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


//-�ϳ��� ���� �Է� �޾� 1 ~100������ �ش�
//���� ��� ���� ���Ͻÿ�(5�Է½� 1 ~100������ 5�ǹ���� ��� �ջ�)
void Sum(int num, int& answer)
{
	int maxSum = 0;
	for (int i = 1; i*num <= 100; i++)
	{
		maxSum += num * i;
	}
	answer = maxSum;
}

//- �ϳ��� ���ڸ� �Է� �޾� �Ųٷ� ����Ͻÿ�
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

//(main������ cin,cout���,return������)
void main()
{
	int a;
	int b;
	int answer;

	cout << "1. �� ���� ������ �Է� : ";
	cin >> a >> b;
	Max(a, b, answer);
	cout << a <<"�� " << b<<"�� ū ����"<< answer << endl;

	cout << "2. ���� �ϳ� �Է� : ";
	cin >> a;
	Sum(a, answer);
	cout << "1~ 100 ���� " << a << "����� ���� :" << answer << endl;

	cout << "3. ���� �ϳ� �Է� : ";
	cin >> a;
	Backing(a, answer);
	cout << a << "�� �Ųٷ� �� : "<< answer << endl;
}
