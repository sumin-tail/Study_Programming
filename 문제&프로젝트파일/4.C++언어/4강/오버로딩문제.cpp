#include<iostream>
using namespace std;
#define MAXLEN 5

//�����ε��� �̿��Ͽ� �������� �Է½� ���������� ���� ���� ���� ���� ���Ͽ� ��ȯ�ϴ� �Լ��� �����
//���ڿ� ������ �Է½� ���ڿ��� ������ŭ�� ���� ���ڸ�
//����ϴ� �Լ��� ����ÿ�.
//(���� ���ҽ� �¿� �ش��ϴ� ���ڰ� 1���� ������ �ȵ�)
//(���ڿ��� �ش� ������ŭ �̵��� z�� �Ѿ��� ���� �� ��ŭ a���� ����)
//(ex > y -> 3 = b)
//
//�����ε��� �̿��Ͽ� ���ڰ� ���ڿ� �ϳ��� ��� ���ڿ��� ������ �Լ��� ����ð� ���ڿ��� 2���ϰ�� �� ���ڿ��� ��ġ�� �Լ��� ����ÿ�.(string)
//
//�����ε��� �̿��Ͽ� 5���� ���ڸ� �Է½� �������� ����
//5���� ���ڸ� �Է½� �������� ������ �Ͻÿ�(char[])

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
		cout << num2 <<"�� 1���� �۽��ϴ�." << endl;
		return;
	}
	int sum = num;
	for (int i = 1; i < num2; i++)
	{
		sum *= num;
	}
	cout << num << "��" << num2 << " �� : " << sum << endl;
}
void Test::Quiz1(char ch, int num2)
{ 
	//97���� 122����
	char tmp = ch;
	tmp += num2;

	while (tmp > 'z')
	{
		tmp -= 26;
	}

	cout << ch << " >> " << num2 << " : " << tmp << endl;
}

void Test::Quiz2(string str)// ���ڿ� �ٲٱ� ó��/ ������ - ó��+1/������-1 ������ �ָ��� > ������ ���ݸ�ŭ
{
	cout << str << " -> ";
	char chtmp;
	for (int i = 0; i < str.size()/2 ; i++)
	{
		chtmp = str[i];
		str[i] = str[str.size()-1-i]; //*����!! �迭�� ����� 3 �̶�� �迭�� ������ �ε����� ������-1 ��!
		str[str.size() - 1 - i] = chtmp;
	}
	cout << str << endl;
}
void Test::Quiz2(string str, string str2)
{
	cout << str << " + " << str2 << " = " << str + str2 << endl;
}

void Test::Quiz3(int iarr[]) //������������
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
void Test::Quiz3(char charr[]) //������������
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
	cout << "���� 2�� �Է� : ";
	cin >> num >> num2;
	t.Quiz1(num, num2);
	cout << endl;

	cout << "1-2" << endl;
	cout << "���Ϲ��ڿ� ���� �Է� : ";
	cin >> ch >> num2;
	t.Quiz1(ch, num2);
	cout << endl;

	cout << "2-1" << endl;
	cout << "���ڿ� �ϳ� �Է� : ";
	cin >> str1;
	t.Quiz2(str1);
	cout << endl;

	cout << "2-2" << endl;
	cout << "���ڿ� �ΰ� �Է� : ";
	cin >> str1 >> str2;
	t.Quiz2(str1, str2);
	cout << endl;

	cout << "3-1" << endl;
	cout << "���� 5�� �Է� : ";
	for (int i = 0; i < MAXLEN; i++)
	{
		cin >> iarr[i];
	}
	t.Quiz3(iarr);
	cout << endl;

	cout << "3-2" << endl;
	cout << "���Ϲ��� 5�� �Է� : ";
	for (int i = 0; i < MAXLEN; i++)
	{
		cin >> charr[i];
	}
	t.Quiz3(charr);
	cout << endl;

}

