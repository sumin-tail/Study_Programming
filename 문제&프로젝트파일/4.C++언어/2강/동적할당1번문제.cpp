#include <iostream>
using namespace std;
//�����Ҵ����� ������ �迭 5�� ���� �� ���� �Է� ���� �� �������� �����Ͽ� ���

#define MAX 5

void Print(int *ptr)
{
	for (int i = 0; i < MAX; i++)
	{
		cout << i + 1 << "�� �� ���� : " << ptr[i] << endl;
	}
}

void Ascending(int* ptr) //��������
{
	int temp;
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (ptr[i] < ptr[j])
			{
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}

void main()
{
	int* ptr;
	ptr = new int[MAX];

	for (int i = 0; i < MAX; i++)
	{
		cout << i + 1 << "�� �� ���� : ";
		cin >> ptr[i];
	}
	cout << endl;
	cout <<"�������� ���� ��" << endl;
	cout << "===================" << endl;
	Print(ptr);
	cout << "===================" << endl << endl;
	Ascending(ptr);
	cout << "�������� ���� ��" << endl;
	cout << "===================" << endl;
	Print(ptr);
	cout << "===================" << endl;
	delete []ptr;
}
