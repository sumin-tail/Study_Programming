#include <iostream>
using namespace std;
//동적할당으로 정수형 배열 5개 만든 후 값을 입력 받은 뒤 오름차순 정렬하여 출력

#define MAX 5

void Print(int *ptr)
{
	for (int i = 0; i < MAX; i++)
	{
		cout << i + 1 << "번 쨰 정수 : " << ptr[i] << endl;
	}
}

void Ascending(int* ptr) //오름차순
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
		cout << i + 1 << "번 쨰 정수 : ";
		cin >> ptr[i];
	}
	cout << endl;
	cout <<"오름차순 정렬 전" << endl;
	cout << "===================" << endl;
	Print(ptr);
	cout << "===================" << endl << endl;
	Ascending(ptr);
	cout << "오름차순 정렬 후" << endl;
	cout << "===================" << endl;
	Print(ptr);
	cout << "===================" << endl;
	delete []ptr;
}
